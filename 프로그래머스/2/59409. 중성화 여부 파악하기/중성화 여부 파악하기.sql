-- 코드를 입력하세요
-- 중성화 유무 판단
SELECT ANIMAL_ID, NAME, 
    CASE WHEN SEX_UPON_INTAKE LIKE '%Neutered%' then 'O'
    WHEN SEX_UPON_INTAKE LIKE '%Spayed%' then 'O'
    ELSE 'X'
    END AS '중성화'
FROM ANIMAL_INS
ORDER BY ANIMAL_ID
