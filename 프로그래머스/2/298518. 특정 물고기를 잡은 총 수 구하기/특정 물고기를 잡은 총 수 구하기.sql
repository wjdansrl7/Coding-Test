-- 코드를 작성해주세요

select count(*) as FISH_COUNT
from fish_info a join fish_name_info b
on a.fish_type = b.fish_type
where b.fish_name = 'BASS' or b.fish_name = 'SNAPPER';
