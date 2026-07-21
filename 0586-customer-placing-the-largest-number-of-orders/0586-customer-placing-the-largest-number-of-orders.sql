# Write your MySQL query statement below
SELECT customer_number FROM Orders Group by customer_number order by COUNT(*) DESC LIMIT 1; 