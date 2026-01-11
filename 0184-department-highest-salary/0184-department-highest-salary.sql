# Write your MySQL query statement below
select d.name as Department  , e.name as Employee , e.salary as salary 
from (
    select * , DENSE_RANK() OVER(
        partition by departmentId
        order by salary DESC
    )
    as rnk 
    from Employee 
)
 e
right join 
Department d
ON e.departmentId = d.id
where rnk =1
order by d.name DESC;

