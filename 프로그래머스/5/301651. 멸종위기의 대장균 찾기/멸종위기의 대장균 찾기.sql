-- 코드를 작성해주세요

with recursive generation as (
    select id, 1 as g_level
    from ecoli_data
    where parent_id is null
    
    union all
    
    select a.id, g.g_level + 1 as g_level
    from ecoli_data a join generation g
    on a.parent_id = g.id
)

select count(*) as count, g_level as generation
from generation g left join ecoli_data a
on g.id = a.parent_id
where a.id is null
group by generation
order by generation