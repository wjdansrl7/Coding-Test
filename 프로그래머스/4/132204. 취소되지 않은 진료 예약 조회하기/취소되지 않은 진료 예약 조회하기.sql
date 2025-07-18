-- 코드를 입력하세요

-- 2022 4/13 취소되지 않은 흉부외과 진료 예약 내역 조회
SELECT APNT_NO, PT_NAME, A.PT_NO, A.MCDP_CD, DR_NAME, APNT_YMD
FROM APPOINTMENT A
JOIN DOCTOR B ON A.MDDR_ID = B.DR_ID
JOIN PATIENT C ON A.PT_NO = C.PT_NO
WHERE YEAR(APNT_YMD) = '2022' AND MONTH(APNT_YMD) = '04' AND DAY(APNT_YMD) = '13'
AND APNT_CNCL_YN = 'N'
ORDER BY APNT_YMD