-- Last updated: 4/24/2026, 10:10:16 PM
# Write your MySQL query statement below
SELECT player_id,MIN(event_date) as first_login from Activity 
GROUP BY player_id