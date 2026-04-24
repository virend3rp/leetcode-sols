-- Last updated: 4/24/2026, 10:10:19 PM
SELECT p.project_id,ROUND(SUM(e.experience_years)/COUNT(e.employee_id),2) as  average_years FROM 
Project p
LEFT JOIN
Employee e
ON p.employee_id=e.employee_id
GROUP BY p.project_id

