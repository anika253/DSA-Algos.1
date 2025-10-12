# Write your MySQL query statement below
select c.name as Customers from Customers as c
 left join orders as o
 ON c.id = o. customerId
 WHERE
 o.id IS NULL;