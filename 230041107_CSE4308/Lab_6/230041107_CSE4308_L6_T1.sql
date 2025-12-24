-- Task 1
SELECT 
TRIM(raw_msg) AS trimmed_msg
FROM server_logs;

-- Task 2
SELECT full_name, 
EXTRACT(YEAR FROM AGE(CURRENT_DATE, enrollment_date)) AS tenure
FROM Students;

-- Task 3
SELECT 
    full_name AS name,
    'Student' AS role
FROM Students
UNION ALL
SELECT 
    name, 'Staff' AS role
FROM Faculty;

-- Task 4
SELECT UPPER(location), COUNT(person_id)
FROM Gate_Logs
GROUP BY location;

-- Task 5
REFRESH MATERIALIZED VIEW MatView_Enrollment_Stats;