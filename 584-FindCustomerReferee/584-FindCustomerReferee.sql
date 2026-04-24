-- Last updated: 4/24/2026, 10:12:20 PM
SELECT name 
FROM Customer
WHERE referee_id <> 2 OR referee_id IS NULL;
