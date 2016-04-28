SELECT MD5(REPLACE(CONCAT(`distrib`.`telephone`,42), '7', '9')) as 'ft5'
FROM `db_tlepeche`.`distrib`
WHERE `distrib`.`id_distrib` = 84;
