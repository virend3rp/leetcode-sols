-- Last updated: 4/24/2026, 10:08:43 PM
/* Write your PL/SQL query statement below */
SELECT patient_id, patient_name, conditions
FROM Patients
WHERE conditions LIKE 'DIAB1%' OR conditions LIKE '% DIAB1%'