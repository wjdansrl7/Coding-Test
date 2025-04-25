
select month(start_date) as month, car_id, count(history_id) as records
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where car_id in (
    select car_id
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where date(start_date) >= '2022-08-01' and date(start_date) < '2022-11-01'
    group by car_id
    having count(history_id) >= 5
) and date(start_date) >= '2022-08-01' and date(start_date) < '2022-11-01'
group by car_id, month(start_date)
order by month(start_date), car_id desc


# select * from CAR_RENTAL_COMPANY_RENTAL_HISTORY;
