-- 코드를 작성해주세요

select a.id
from ecoli_data a join (
    select c.id
    from ecoli_data b left join ecoli_data c
    on b.id = c.parent_id
    where b.parent_id is null
) as d
on a.parent_id = d.id
order by a.id;