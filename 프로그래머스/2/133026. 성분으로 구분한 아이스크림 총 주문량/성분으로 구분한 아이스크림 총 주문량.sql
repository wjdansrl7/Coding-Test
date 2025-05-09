-- 코드를 입력하세요
-- first_half : 상반기 주문 정보 -- flavor
-- icecream_info : 아이스크림 성분에 대한 정보
-- 총 주문량이 작은 순서대로 출력
SELECT INGREDIENT_TYPE, SUM(TOTAL_ORDER) AS TOTAL_ORDER
FROM FIRST_HALF A
LEFT JOIN ICECREAM_INFO B ON A.FLAVOR = B.FLAVOR
GROUP BY INGREDIENT_TYPE
ORDER BY TOTAL_ORDER

