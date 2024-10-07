select rating, title from movies
join ratings on movies.id=ratings.movie_id
where year = 2010 and rating is not null order by rating desc, title asc;