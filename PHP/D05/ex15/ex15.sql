SELECT REVERSE(RIGHT(`distrib`.`telephone`, 8)) as enohpelet
FROM `db_tlepeche`.`distrib`
WHERE `distrib`.`telephone` LIKE '05%';
