-- Last updated: 4/24/2026, 10:08:25 PM
# Write your MySQL query statement below

SELECT 
    user_id
    ,CONCAT(UPPER(SUBSTRING(name,1,1)),LOWER(SUBSTRING(name,2))) AS name
FROM users
ORDER BY user_id