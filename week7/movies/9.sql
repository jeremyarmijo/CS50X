select name from people
inner join stars on stars.person_id=people.id
inner join movies on movies.id=stars.movie_id and movies.year='2004'
order by people.birth;