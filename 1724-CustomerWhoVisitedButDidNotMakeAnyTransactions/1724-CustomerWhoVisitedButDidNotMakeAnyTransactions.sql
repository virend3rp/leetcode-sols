-- Last updated: 4/24/2026, 10:08:36 PM
# Write your MySQL query statement below
select v.customer_id,COUNT(v.visit_id) as count_no_trans from
VISITS v
LEFT JOIN 
Transactions t
ON v.visit_id=t.visit_id
where transaction_id is NULL
GROUP BY v.customer_id