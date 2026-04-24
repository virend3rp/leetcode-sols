-- Last updated: 4/24/2026, 10:08:19 PM
SELECT tweet_id
FROM Tweets
WHERE CHAR_LENGTH(content) > 15;
