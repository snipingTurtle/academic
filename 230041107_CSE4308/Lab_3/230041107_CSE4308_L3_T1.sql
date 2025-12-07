-- Task 1
SELECT * FROM EMPLOYEE;

-- Task 2
SELECT name FROM employee
WHERE dept_name = 'Finance'
AND salary > 7000;

-- Task 3
SELECT name FROM employee 
WHERE dept_name = 'Sales' 
OR dept_name = 'Research';

-- Task 4
DELETE FROM employee
WHERE salary = 0;

-- Task 5
DROP Table employee;