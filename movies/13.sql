SELECT * FROM people JOIN (SELECT * FROM movies JOIN stars ON movies.id = stars.movie_id WHERE person_id = (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958)) ON movies.id = movie_id;