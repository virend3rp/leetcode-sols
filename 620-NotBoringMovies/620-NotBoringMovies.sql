-- Last updated: 4/24/2026, 10:12:12 PM
# Write your MySQL query statement below
Select * from Cinema 
where id%2!=0 and description!='Boring'
order by rating DESC