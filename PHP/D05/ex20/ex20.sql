SELECT `film`.`id_genre`, `genre`.`nom` as 'nom genre', `distrib`.`id_distrib`, `distrib`.`nom` as 'nom distrib', `film`.`titre` as 'titre film'
FROM `db_tlepeche`.`film`
INNER JOIN `db_tlepeche`.`genre`
ON `genre`.`id_genre` = `film`.`id_genre`
INNER JOIN `db_tlepeche`.`distrib`
ON `film`.`id_distrib` = `distrib`.`id_distrib` OR `film`.`id_distrib` IS NULL
WHERE `film`.`id_genre` BETWEEN 4 AND 8
GROUP BY `film`.`titre`;
