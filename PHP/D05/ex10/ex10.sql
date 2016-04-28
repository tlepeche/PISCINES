SELECT titre as Titre, resum as Resume, annee_prod FROM `db_tlepeche`.`film`, `db_tlepeche`.`genre`
WHERE `genre`.id_genre = `film`.`id_genre` AND `genre`.`nom` = 'erotic' ORDER BY annee_prod DESC;
