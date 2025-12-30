# Write your MySQL query statement below
select e.name as name 
from Employee e
join Employee e1
ON e1.managerId = e.id
group by e1.managerId
having count(e1.managerId)>=5;
