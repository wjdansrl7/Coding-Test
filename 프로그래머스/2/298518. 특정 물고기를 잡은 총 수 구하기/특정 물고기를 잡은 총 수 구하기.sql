-- 코드를 작성해주세요

# select count(*) as FISH_COUNT
# from fish_info a join fish_name_info b
# on a.fish_type = b.fish_type
# where b.fish_name = 'BASS' or b.fish_name = 'SNAPPER';



WITH fish AS (
SELECT ID, a.fish_type, LENGTH, TIME, b.fish_name
FROM fish_info a
LEFT JOIN fish_name_info b
ON a.fish_type = b.fish_type
)
SELECT COUNT(CASE WHEN fish_name = 'BASS' OR fish_name = "SNAPPER" THEN 1
END) AS fish_count
FROM fish;