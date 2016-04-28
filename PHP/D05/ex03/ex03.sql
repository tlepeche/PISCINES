INSERT INTO `db_tlepeche`.`ft_table` (`login`, `groupe`, `date_de_creation`)
SELECT nom, 'other', date_naissance FROM `db_tlepeche`.`fiche_personne`
WHERE nom LIKE '%a%' AND length(nom) < 9 ORDER BY nom LIMIT 10;
