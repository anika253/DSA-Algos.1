# Write your MySQL query statement below
WITH cte as 
(
    select e.name as Employee , e.salary ,d.name as Department,
    MAX(e.salary) OVER(partition by d.id)
    as max_salary from Employee e left join 
    Department d
    on e.departmentID=d.id
    

    
)
Select Department , Employee, Salary 
from cte
where
salary = max_salary