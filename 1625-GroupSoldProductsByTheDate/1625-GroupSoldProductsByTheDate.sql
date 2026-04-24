-- Last updated: 4/24/2026, 10:08:52 PM
SELECT sell_date
    ,COUNT(DISTINCT product) AS num_sold
    ,GROUP_CONCAT(DISTINCT product ORDER BY product SEPARATOR ',') AS products
FROM activities
GROUP BY sell_date
ORDER BY sell_date 