-- listing people who directed a movie with 9.0 rating

SELECT DISTINCT name
FROM people JOIN directors ON directors.person_id = people.id JOIN ratings ON ratings.movie_id = directors.movie_id
WHERE rating >= 9.0