-- Last updated: 4/24/2026, 10:14:51 PM
# Write your MySQL query statement below
select email as Email 
from Person 
group by email
having count(email)>1;