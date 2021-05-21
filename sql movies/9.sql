-- listing people who starred in a movie relesed in 2004 order by birth year.

SELECT name
FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON movies.id = stars.movie_id
WHERE year = 2004
GROUP BY name, person_id
ORDER BY birth;