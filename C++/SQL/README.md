# SQL
MySQL을 이용한 프로그래머스 SQL 고득적 kit 풀이

✍🏻 SELECT <a href="https://github.com/Choyoonyoung98/Algorithm/tree/master/SQL/SELECT">GO</a>
<br>
✍🏻 SUM, MAX, MIN <a href="https://github.com/Choyoonyoung98/Algorithm/tree/master/SQL/SUM_MAX_MIN">GO</a>
<br>
✍🏻 GROUP BY <a href="https://github.com/Choyoonyoung98/Algorithm/tree/master/SQL/GROUPBY">GO</a>
<br>
✍🏻 IS NULL <a href="https://github.com/Choyoonyoung98/Algorithm/tree/master/SQL/ISNULL">GO</a>
<br>
✍🏻 JOIN <a href="https://github.com/Choyoonyoung98/Algorithm/tree/master/SQL/JOIN">GO</a>
<br>
✍🏻 String, Date <a href="https://github.com/Choyoonyoung98/Algorithm/tree/master/SQL/String_Date">GO</a>
<br>
✍🏻 CASE <a href="https://github.com/Choyoonyoung98/Algorithm/tree/master/SQL/Case">GO</a>


```
SELECT idx,
  CASE 
    WHEN type = '1'
    THEN '의사'
    WHEN type = '2'
    THEN '장군'
    ELSE '일반인'
    END AS hero_type,
    name
FROM hero_table;
    
```
