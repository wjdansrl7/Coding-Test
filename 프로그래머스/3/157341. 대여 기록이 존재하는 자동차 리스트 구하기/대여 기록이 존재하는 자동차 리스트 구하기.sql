-- 코드를 입력하세요

-- 세단, 10월에 대여를 시작한 기록이 있는 리스트
-- id 중복 없이
SELECT DISTINCT A.CAR_ID
FROM CAR_RENTAL_COMPANY_CAR A
JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY B ON A.CAR_ID = B.CAR_ID
WHERE A.CAR_TYPE = '세단' AND MONTH(START_DATE) = 10
ORDER BY A.CAR_ID DESC


