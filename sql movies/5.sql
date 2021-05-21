-- all harry potter movies

SELECT title, year
FROM movies
WHERE title LIKE "Harry Potter%"
ORDER BY year;