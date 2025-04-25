-- 코드를 작성해주세요

select b.id, b.genotype, a.genotype as parent_genotype
from ecoli_data a left join ecoli_data b
on a.id = b.parent_id
where a.genotype & b.genotype >= a.genotype
order by id
