-- Last updated: 4/24/2026, 10:07:32 PM
# Write your MySQL query statement below
SELECT employee_id from Employees
where salary< 30000 and 
      manager_id NOT IN (
         Select employee_id from Employees
      )
ORDER BY employee_id