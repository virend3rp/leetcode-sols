-- Last updated: 4/24/2026, 10:12:23 PM
SELECT 
    e.name,
    b.bonus
FROM Employee e
LEFT JOIN Bonus b
    ON e.empId = b.empId
WHERE b.bonus < 1000 OR b.bonus IS NULL;
