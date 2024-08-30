select r.*
from (select name, count(animal_id) as count
      from animal_ins
      where name is not null
      group by name) as r
where count >= 2
order by name;