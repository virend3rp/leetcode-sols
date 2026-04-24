-- Last updated: 4/24/2026, 10:10:01 PM
SELECT DISTINCT author_id AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY id;
