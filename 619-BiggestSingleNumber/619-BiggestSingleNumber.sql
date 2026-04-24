-- Last updated: 4/24/2026, 10:12:13 PM
SELECT 
    MAX(num) AS num
FROM MyNumbers
WHERE num IN (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1
);
