SELECT `salle`.`etage_salle` as etage, SUM(`salle`.`nbr_siege`) as sieges FROM `db_tlepeche`.`salle`
GROUP BY etage
ORDER BY etage, sieges;
