

select year(DIFFERENTIATION_DATE) as YEAR, b.max_size - a.size_of_colony as YEAR_DEV, id
from ecoli_data a join
    (select year(differentiation_date) as year, max(size_of_colony) as max_size
     from ecoli_data
     group by year(differentiation_date)
    ) as b
on year(a.DIFFERENTIATION_DATE) = b.year
order by YEAR, YEAR_DEV;