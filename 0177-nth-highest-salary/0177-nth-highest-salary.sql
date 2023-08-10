CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN

  RETURN (
      SELECT DISTINCT salary FROM Employee AS e1 WHERE N-1 = 
        (
            SELECT COUNT(DISTINCT salary) FROM Employee as e2 
            where e1.salary<e2.salary
        )
  );
END