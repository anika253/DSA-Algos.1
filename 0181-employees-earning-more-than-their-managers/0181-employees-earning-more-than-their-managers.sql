# Write your MySQL query statement below
select e.name  as Employee  from Employee e 
 join 
Employee e1
ON e.managerID = e1.id
WHERE  e.salary > e1.salary;
