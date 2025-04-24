-- 코드를 입력하세요
SELECT a.title as TITLE, a.board_id as BOARD_ID, b.reply_id as REPLY_ID, b.writer_id as WRITER_ID, b.contents as CONTENTS, date_format(b.created_date, '%Y-%m-%d') as CREATE_DATE
from used_goods_board a join used_goods_reply b
on a.board_id = b.board_id
where year(a.created_date) = '2022' and month(a.created_date) = '10'
order by b.created_date, a.title;