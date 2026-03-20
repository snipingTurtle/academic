-- task 1
DO $$
DECLARE 
    rname varchar;
    pname varchar;
    rich NUMERIC;
    poor NUMERIC;
    rid NUMERIC;
    pid NUMERIC;
BEGIN
    SELECT employee_id, first_name || ' ' || last_name, salary
    INTO rid, rname, rich
    FROM employees
    ORDER BY salary DESC LIMIT 1;

    RAISE NOTICE 'Richest is %', rname;

    SELECT employee_id, first_name || ' ' || last_name, salary
    INTO pid, pname, poor
    FROM employees
    ORDER BY salary ASC LIMIT 1;

    RAISE NOTICE 'Poorest is %', pname;

    UPDATE employees SET salary = salary - 1000 WHERE employee_id = rid;
    UPDATE employees SET salary = salary + 1000 WHERE employee_id = pid;
END $$;

-- task 2
DO $$
DECLARE
    r RECORD;
    abbr varchar;
BEGIN
    FOR r IN
        SELECT first_name, last_name FROM employees LIMIT 10
    LOOP
        abbr := LOWER(SUBSTR(r.first_name, 1, 1) || r.last_name);
        RAISE NOTICE '%', abbr;
    END LOOP;
END $$;

-- task 3
DO $$
DECLARE
    num NUMERIC := 1;
    fact NUMERIC := 1;
BEGIN
    WHILE num <= 6 LOOP
        fact := fact * num;
        num := num + 1;
    END LOOP;

    RAISE NOTICE '6! = %', fact;
END $$;

-- -- task 4
DO $$
DECLARE
    id NUMERIC;
    r RECORD;
BEGIN
    FOR r IN
        SELECT employee_id FROM employees WHERE department = 'IT' LIMIT 3
    LOOP
        UPDATE employees SET department = 'CyberSec' WHERE employee_id = r.employee_id;
        RAISE NOTICE 'Moving % to CyberSec', r.employee_id;
    END LOOP;
END $$;