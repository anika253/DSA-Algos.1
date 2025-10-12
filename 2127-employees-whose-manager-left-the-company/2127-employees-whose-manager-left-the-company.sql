# Write your MySQL query statement below
select employee_id from Employees e 
where e.salary < 30000
and manager_id NOT IN(
    select employee_id from Employees
)
order by employee_id