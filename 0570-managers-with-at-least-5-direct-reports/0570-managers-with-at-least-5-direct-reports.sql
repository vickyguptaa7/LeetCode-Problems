# Write your MySQL query statement below
SELECT e1.name 
FROM Employee as e1 INNER JOIN Employee as e2 On e1.id=e2.managerId
GROUP BY e1.id 
HAVING COUNT(e1.id)>=5;