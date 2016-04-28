SELECT COUNT(`historique_membre`.`date`) as films
FROM `db_tlepeche`.`historique_membre`
WHERE `historique_membre`.`date` BETWEEN '2006-10-30' AND '2007-07-27'
OR DATE_FORMAT(`historique_membre`.`date`, '%m-%d') = '12-24';
