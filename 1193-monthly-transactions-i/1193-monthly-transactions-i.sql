# Write your MySQL query statement below
SELECT 
DATE_FORMAT(trans_date,'%Y-%m') as month, 
country, 
COUNT(*) as trans_count, 
SUM(state = 'approved') approved_count, 
sum(amount) as trans_total_amount, 
sum(CASE
            WHEN state = 'approved' THEN amount
            ELSE 0
        END) as approved_total_amount  
FROM Transactions 
GROUP BY DATE_FORMAT(trans_date,'%Y-%m'),  country;