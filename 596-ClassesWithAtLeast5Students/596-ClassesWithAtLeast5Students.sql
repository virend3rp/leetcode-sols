-- Last updated: 4/24/2026, 10:12:17 PM
# Write your MySQL query statement below
SELECT class from Courses
GROUP BY(class)
HAVING COUNT(student)>=5