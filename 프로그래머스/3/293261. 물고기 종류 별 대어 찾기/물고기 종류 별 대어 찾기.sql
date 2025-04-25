
select id, fish_name, length
from fish_info a
join fish_name_info b
on a.fish_type = b.fish_type
where (a.fish_type, length)
in
(select fish_type, max(length) as length
 from fish_info
 group by fish_type
 having length > 10
)
