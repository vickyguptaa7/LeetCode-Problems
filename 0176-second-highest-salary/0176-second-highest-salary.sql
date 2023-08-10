# Write your MySQL query statement below
SELECT 
    IFNULL(
        (SELECT DISTINCT salary as SecondHighestSalary FROM Employee as e1 WHERE 1 = 
            (   
                SELECT COUNT(DISTINCT salary) FROM Employee as e2 where    e1.salary<e2.salary
)),NULL) AS SecondHighestSalary;