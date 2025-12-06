CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      SELECT salary
      FROM (
          SELECT salary,
                 DENSE_RANK() OVER (ORDER BY salary DESC) as rk
          FROM Employee
      ) t
      WHERE rk = N
      LIMIT 1
  );
END
