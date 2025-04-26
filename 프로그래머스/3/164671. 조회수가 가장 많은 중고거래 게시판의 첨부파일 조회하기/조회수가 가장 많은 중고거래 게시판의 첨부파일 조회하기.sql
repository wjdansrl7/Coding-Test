select concat("/home/grep/src/", a.board_id, "/", file_id, file_name, file_ext) as FILE_PATH
from USED_GOODS_BOARD a join USED_GOODS_FILE b
on a.board_id = b.board_id
where views in (select max(views) from used_goods_board)
order by file_id desc;

# select 
#     concat('/home/grep/src/',ugf.BOARD_ID,'/',ugf.FILE_ID,ugf.FILE_NAME,ugf.FILE_EXT) as FILE_PATH
# from USED_GOODS_BOARD ugb
# join USED_GOODS_FILE ugf on ugb.BOARD_ID = ugf.BOARD_ID
# where VIEWS in (select max(VIEWS) from USED_GOODS_BOARD)
# order by ugf.FILE_ID desc;