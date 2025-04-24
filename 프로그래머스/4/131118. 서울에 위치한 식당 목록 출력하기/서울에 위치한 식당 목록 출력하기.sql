-- 코드를 입력하세요
-- 식당의 정보 : rest_info
-- rest_review
-- 서울에 위치한 식당 id, 식당 이름, 음식 종류, 즐겨찾기 수, 주소, 리뷰 평균 점수(소수 3번째 자리에서 반올림)를 조회
-- 결과는 평균 점수를 기준으로 내림차순 정렬 평균점수가 같다면 즐겨찾기 수, 내림차순 정렬
SELECT a.REST_ID, a.REST_NAME, a.FOOD_TYPE, a.FAVORITES, a.ADDRESS, round(avg(b.REVIEW_SCORE), 2) as SCORE
FROM REST_INFO a JOIN REST_REVIEW b
on a.REST_ID = b.REST_ID
where a.ADDRESS like '서울%'
group by a.REST_ID
order by SCORE desc, a.FAVORITES desc;

# select * from rest_info;