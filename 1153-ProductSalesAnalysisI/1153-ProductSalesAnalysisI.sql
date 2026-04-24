-- Last updated: 4/24/2026, 10:10:21 PM
# Write your MySQL query statement below
SELECT p.product_name, s.year, s.price FROM
Sales s
Left JOIN
Product p
ON s.product_id=p.product_id
