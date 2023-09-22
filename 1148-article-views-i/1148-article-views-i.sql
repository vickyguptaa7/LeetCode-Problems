# Write your MySQL query statement below
SELECT DISTINCT author_id as id FROM Views as v1 
WHERE v1.author_id in ( SELECT DISTINCT viewer_id FROM Views as v2 WHERE v1.author_id=v2.author_id )
ORDER BY author_id;