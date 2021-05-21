-- selecting movies with the 10 rating

SELECT COUNT(movie_id)
FROM ratings
WHERE rating = 10.0