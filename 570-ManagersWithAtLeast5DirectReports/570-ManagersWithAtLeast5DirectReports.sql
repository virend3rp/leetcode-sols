-- Last updated: 4/24/2026, 10:12:25 PM
# Write your MySQL query statement below
SELECT 
    e1.name
FROM Employee e1
JOIN Employee e2
    ON e1.id = e2.managerId
GROUP BY 
    e1.id, 
    e1.name
HAVING 
    COUNT(e2.id) >= 5;
