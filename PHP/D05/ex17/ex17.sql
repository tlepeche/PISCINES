SELECT COUNT(`abonnement`.`id_abo`) as nb_abo, FLOOR(AVG(`abonnement`.`prix`)) as moy_abo, SUM(`abonnement`.`duree_abo`) % 42  as ft
FROM `db_tlepeche`.`abonnement`;
