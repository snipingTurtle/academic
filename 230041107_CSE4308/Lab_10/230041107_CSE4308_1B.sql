--task 1
DO $$

DECLARE
	cnt int := 1;
BEGIN
	while cnt <11 LOOP
		insert into employees (first_name,last_name,salary,department) values ('USER', cnt::text,1000*cnt,'TESTING');
		cnt := cnt+1;
	END LOOP;

END $$;

--task2
DO $$

DECLARE 
	cnt int:=0;
	r record;
BEGIN
	for r in
		select * from employees where department = 'IT' LOOP
			cnt:=cnt+1;
		END LOOP;
	
	RAISE NOTICE 'Total: %',cnt;

END $$;

--task3 
DO $$

DECLARE 
	name text;
	New_Salary int;
	r record;
BEGIN
	update employees
	set salary = ROUND(salary,-2);
	
	for r in
		select * from employees LOOP
			Raise Notice 'Rounded salary for % % to %', r.first_name, r.last_name, r.salary;
		end loop;

END $$;

--task4
do $$

DECLARE 
	r record;
BEGIN 
	for r in 
		select * from employees order by salary DESC limit 1 loop
		Raise Notice 'Rich: % %', r.first_name,r.last_name;
		r.salary := r.salary-1000;
		Raise Notice 'Reduced salary: %', r.salary;
	END LOOP;
		
		
	for r in 
		select * from employees order by salary ASC limit 1 LOOP
		Raise Notice 'Poorest: % %', r.first_name,r.last_name;
		r.salary := r.salary+1000;
		Raise Notice 'Increased salary: %', r.salary;
	END LOOP;
	
End $$;