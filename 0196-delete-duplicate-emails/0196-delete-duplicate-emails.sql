# Write your MySQL query statement below
Delete p1 from person p1
join person p2
ON p1.email = p2.email 
and p1.id> p2.id;
