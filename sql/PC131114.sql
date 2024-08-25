select warehouse_id, warehouse_name, address, ifnull(FREEZER_YN, 'N') as freezer_yn
from food_warehouse
where warehouse_name like "%경기%"
order by warehouse_id;