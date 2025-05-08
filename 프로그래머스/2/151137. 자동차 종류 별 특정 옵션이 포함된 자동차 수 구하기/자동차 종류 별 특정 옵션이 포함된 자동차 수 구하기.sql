-- 코드를 입력하세요
-- 통풍시트, 열선시트, 가죽시트 중 하나의 옵션이 포함된 자동차가 종류 별로 몇대인지 출력

SELECT CAR_TYPE, COUNT(*) AS CARS
FROM CAR_RENTAL_COMPANY_CAR 
WHERE CAR_ID IN (
    SELECT DISTINCT CAR_ID
    FROM CAR_RENTAL_COMPANY_CAR
    WHERE OPTIONS LIKE '%통풍시트%'
    OR OPTIONS LIKE '%열선시트%'
    OR OPTIONS LIKE '%가죽시트%'
    # '%열선시트%''%가죽시트%'
)
GROUP BY CAR_TYPE
ORDER BY CAR_TYPE;

# SELECT CAR_ID
#     FROM CAR_RENTAL_COMPANY_CAR
#     WHERE OPTIONS LIKE '%통풍시트%' OR '%열선시트%' OR '%가죽시트%';