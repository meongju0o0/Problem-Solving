select book_id, date_format(published_date, '%Y-%m-%d') as published_date
from book
where category = '인문' and published_date between '2021-01-01' and '2021-12-31';