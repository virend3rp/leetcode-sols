-- Last updated: 4/24/2026, 10:09:11 PM
SELECT 
    u.unique_id,
    e.name
FROM Employees e
LEFT JOIN EmployeeUNI u
    ON e.id = u.id;
