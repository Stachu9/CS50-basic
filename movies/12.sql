SELECT title FROM (SELECT * FROM movies JOIN stars ON movies.id = stars.movie_id JOIN people ON stars.person_id = people.id
WHERE name = "Bradley Cooper" OR name = "Jennifer Lawrence");