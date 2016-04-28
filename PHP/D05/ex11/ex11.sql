SELECT upper(`fiche_personne`.`nom`) as NOM, `fiche_personne`.`prenom`, `abonnement`.`prix` FROM `db_tlepeche`.`abonnement`
INNER JOIN `db_tlepeche`.`membre`
ON `abonnement`.`id_abo` = `membre`.`id_abo`
INNER JOIN `db_tlepeche`.`fiche_personne`
ON `membre`.`id_membre` = `fiche_personne`.`id_perso`
WHERE `abonnement`.`prix` > 42 ORDER BY `fiche_personne`.`nom`, `fiche_personne`.`prenom`;
