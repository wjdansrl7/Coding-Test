-- 코드를 작성해주세요

# SELECT COUNT(*) AS FISH_COUNT, MONTH(TIME)
# FROM FISH_INFO
# GROUP BY MONTH(TIME)
# ORDER BY MONTH(TIME)

SELECT COUNT(*) AS FISH_COUNT, MONTH(TIME) AS MONTH
FROM FISH_INFO
GROUP BY MONTH(TIME)
ORDER BY MONTH(TIME);
