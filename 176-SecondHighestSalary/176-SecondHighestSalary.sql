-- Last updated: 4/24/2026, 10:14:53 PM
# Write your MySQL query statement below

select
(select distinct Salary 
from Employee order by salary desc 
limit 1 offset 1) 
as SecondHighestSalary;