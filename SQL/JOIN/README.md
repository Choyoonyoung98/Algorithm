### JOIN
<hr/>
✍🏻[없어진 기록 찾기]
: 천재지변으로 인해 일부 데이터가 유실되었습니다. 입양을 간 기록은 있는데, 보호소에 들어온 기록이 없는 동물의 ID와 이름을 ID 순으로 조회하는 SQL문을 작성해주세요.

```
SELECT o.ANIMAL_ID, o.NAME
FROM ANIMAL_OUTS o
LEFT JOIN ANIMAL_INS i ON (o.ANIMAL_ID = i.ANIMAL_ID)
WHERE i.ANIMAL_ID IS NULL
GROUP BY o.ANIMAL_ID
ORDER BY o.ANIMAL_ID
```
<hr/>
✍🏻[있었는데요 없었습니다]
: 관리자의 실수로 일부 동물의 입양일이 잘못 입력되었습니다. 보호 시작일보다 입양일이 더 빠른 동물의 아이디와 이름을 조회하는 SQL문을 작성해주세요. 이때 결과는 보호 시작일이 빠른 순으로 조회해야합니다.

```
SELECT i.ANIMAL_ID, i.NAME
FROM ANIMAL_INS i
JOIN ANIMAL_OUTS o ON (i.ANIMAL_ID = o.ANIMAL_ID)
WHERE i.DATETIME >=o.DATETIME
ORDER BY i.DATETIME
```
<hr/>
✍🏻[오랜 기간 보호한 동물(1)]
: 아직 입양을 못 간 동물 중, 가장 오래 보호소에 있었던 동물 3마리의 이름과 보호 시작일을 조회하는 SQL문을 작성해주세요. 이때 결과는 보호 시작일 순으로 조회해야 합니다.

```
SELECT i.NAME, i.DATETIME
FROM ANIMAL_INS i
LEFT JOIN ANIMAL_OUTS o ON (i.ANIMAL_ID = o.ANIMAL_ID)
WHERE o.SEX_UPON_OUTCOME is NULL
GROUP BY i.NAME
ORDER BY i.DATETIME 
LIMIT 3
```
<hr/>
✍🏻[보호소에서 중성화한 동물]
: 보호소에서 중성화 수술을 거친 동물 정보를 알아보려 합니다. 보호소에 들어올 당시에는 중성화1되지 않았지만, 보호소를 나갈 당시에는 중성화된 동물의 아이디와 생물 종, 이름을 조회하는 아이디 순으로 조회하는 SQL 문을 작성해주세요.
```
SELECT i.ANIMAL_ID, i.ANIMAL_TYPE, i.NAME
FROM ANIMAL_INS i
JOIN ANIMAL_OUTS o ON (i.ANIMAL_ID = o.ANIMAL_ID)
WHERE i.SEX_UPON_INTAKE LIKE'Intact %' AND o.SEX_UPON_OUTCOME NOT LIKE'Intact %'
ORDER BY i.ANIMAL_ID
```

