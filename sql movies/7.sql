-- listing all 2010 movies by their rating.

SELECT title, rating
FROM movies JOIN ratings ON movies.id = ratings.movie_id
WHERE year = 2010
ORDER BY rating DESC, title ASC;