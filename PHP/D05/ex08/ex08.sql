SELECT CONCAT(nom,' ',prenom,' ',DATE_FORMAT(date_naissance, '%Y-%m-%d')) as date_naissance FROM `db_tlepeche`.`fiche_personne`
WHERE date_naissance BETWEEN '1989-01-01' AND '1989-12-31'
ORDER BY nom;
