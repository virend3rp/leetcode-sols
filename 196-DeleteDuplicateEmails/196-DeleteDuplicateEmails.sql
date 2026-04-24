-- Last updated: 4/24/2026, 10:14:44 PM
DELETE p1
FROM Person p1
JOIN Person p2
  ON p1.email = p2.email
 AND p1.id > p2.id;
