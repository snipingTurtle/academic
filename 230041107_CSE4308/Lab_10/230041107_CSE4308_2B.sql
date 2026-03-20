

--Task 1

DO $$
DECLARE

v_full_name  TEXT;
v_salary NUMERIC;
v_pension NUMERIC;
BEGIN
-- 1. Fetch data into variables
SELECT first_name || ' ' || last_name, salary
INTO v_full_name, v_salary
FROM employees
WHERE employee_id = 10;

v_pension := v_salary * 0.65;

RAISE NOTICE 'Employee: % earns %', v_full_name, v_pension;
END $$;

--Task 2

DO $$
DECLARE
v_full_name TEXT;
v_salary NUMERIC;
BEGIN
SELECT first_name || ' ' || last_name, salary
INTO v_full_name, v_salary
from employees
order by salary DESC
LIMIT 1;

RAISE NOTICE 'Employee: % Salary: %', v_full_name,v_salary;

END $$;

--Task 3

DO $$
DECLARE
    r RECORD;
    v_building VARCHAR;
BEGIN
    RAISE NOTICE '--- Department Staff ASSIGNING ---';

    FOR r IN
        SELECT first_name || ' ' || last_name AS full_name,
               department
        FROM employees
    LOOP
        IF r.department IN ('IT', 'Operations') THEN
            v_building := 'Building A';

        ELSIF r.department IN ('HR', 'Management') THEN
            v_building := 'Building B';

        ELSE
            v_building := 'Building C';
        END IF;

        RAISE NOTICE '% from % is assigned to %',
            r.full_name, r.department, v_building;
    END LOOP;
END $$;

--Task 4

DO $$
DECLARE
v_first_number INT :=7;
v_second_number INT :=1;
v_counter INT :=1;
v_res INT;
BEGIN

while v_counter <= 10 LOOP
    v_res = v_first_number * v_second_number;
    RAISE NOTICE '% * % = %',v_first_number,v_second_number,v_res;
    v_second_number := v_second_number + 1;
    v_counter := v_counter +1;
    END LOOP;
END $$;

