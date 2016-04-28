SELECT `distrib`.`nom`, distrib.id_distrib
FROM `db_tlepeche`.`distrib`
WHERE `distrib`.`id_distrib` = 42
OR `id_distrib` BETWEEN 62 AND 69
OR `distrib`.`id_distrib` = 71
OR `id_distrib` BETWEEN 88 AND 90
OR LOWER(`nom`) LIKE '%y%y%'
LIMIT 2, 5;
