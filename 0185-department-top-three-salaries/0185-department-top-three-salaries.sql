# Write your MySQL query statement below
select d.name as Department , 
e.name as Employee , 
e.salary as Salary 
from(
    select *,   DENSE_RANK() OVER (
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
where e.rnk<=3 
order by d.name;

