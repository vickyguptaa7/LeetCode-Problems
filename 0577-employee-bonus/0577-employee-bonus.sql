# Write your MySQL query statement below
SELECT e.name, b.bonus FROM Employee as e LEFT JOIN Bonus as b ON e.empId=b.empId
WHERE b.bonus is null or b.bonus < 1000;