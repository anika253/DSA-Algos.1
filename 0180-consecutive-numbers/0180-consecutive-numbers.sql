# Write your MySQL query statement below
select  distinct num  as 
 ConsecutiveNums
 from(
    select num ,
    LEAD( num , 1) OVER( ORDER BY id) as prev1,
    LAG(num , 1) OVER( order by id) as prev2
    from LOGS

 )
 as temp 
 where num = prev1 and num = prev2;