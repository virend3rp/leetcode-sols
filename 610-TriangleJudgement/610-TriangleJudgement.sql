-- Last updated: 4/24/2026, 10:12:16 PM
# Write your MySQL query statement below
SELECT
  x,
  y,
  z,
  CASE
    WHEN x + y > z AND x + z > y AND y + z > x THEN 'Yes'
    ELSE 'No'
  END AS triangle
FROM Triangle;
