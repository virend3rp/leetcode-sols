-- Last updated: 4/24/2026, 10:08:12 PM
SELECT user_id,
       COUNT(follower_id) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id;
