select ii.item_id, ii.item_name, ii.rarity
from item_info ii
join item_tree it
on ii.item_id = it.item_id
where not exists (select parent_item_id from item_tree where ii.item_id = parent_item_id)
order by ii.item_id desc;