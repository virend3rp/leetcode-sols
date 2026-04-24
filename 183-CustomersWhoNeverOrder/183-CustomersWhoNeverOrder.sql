-- Last updated: 4/24/2026, 10:14:49 PM
SELECT name AS Customers
FROM Customers
LEFT JOIN Orders ON Customers.id = Orders.customerId
WHERE Orders.id IS NULL;
