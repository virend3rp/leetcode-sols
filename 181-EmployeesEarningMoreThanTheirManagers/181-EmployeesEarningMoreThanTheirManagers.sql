-- Last updated: 4/24/2026, 10:14:52 PM
SELECT name as Employee 
FROM Employee e
WHERE salary > (
    SELECT salary 
    FROM Employee 
    WHERE id = e.managerId
);
