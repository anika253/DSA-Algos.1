# Write your MySQL query statement below
select distinct num as ConsecutiveNums
FROM(
    select num,
    LAG(num, 1) OVER (order by id )as prev1,
    LEAD(num, 1) OVER( order by id) as prev2
    from LOGS
) AS temp
where num = prev1 and num = prev2;
