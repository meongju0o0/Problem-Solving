select ugb.title, ugb.board_id, ugr.reply_id, ugr.writer_id, ugr.contents, date_format(ugr.created_date, '%Y-%m-%d') as created_date
from used_goods_board as ugb join used_goods_reply as ugr on ugb.board_id = ugr.board_id
where ugb.created_date like '2022-10-%'
order by ugr.created_date asc, ugb.title asc;