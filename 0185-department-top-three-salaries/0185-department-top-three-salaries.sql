# Write your MySQL query statement below
select d.name as Department ,e.name as Employee,e.salary  as Salary
FROM(
    select *, 
    DENSE_RANK() OVER(
        partition by departmentId 
        order by salary DESC
    )
    as rnk
    from EMPLOYEE
)
AS e left join Department as d
on e.departmentId = d.id
where e.rnk<=3