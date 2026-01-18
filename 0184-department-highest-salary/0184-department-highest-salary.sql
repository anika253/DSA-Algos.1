# Write your MySQL query statement below
select d.name as  Department , e.name as Employee , e.salary as Salary 
from (
    select * , DENSE_RANK() OVER (
        partition by departmentId
        order by salary DESC
    )
    as rnk
    from Employee
)




 e

right join department as d
ON e. departmentId = d.id

where rnk = 1
order by d.name DESC;