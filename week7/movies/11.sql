SELECT title FROM movies, ratings, stars, people 
WHERE movies.id = ratings.movie_id
AND stars.movie_id = movies.id
AND people.id = stars.person_id
AND name = 'Chadwick Boseman'
ORDER BY rating DESC LIMIT 5;