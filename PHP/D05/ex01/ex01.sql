CREATE TABLE `db_tlepeche`.`ft_table` (	
	`id` int(11) NOT NULL PRIMARY KEY AUTO_INCREMENT,
	`login` varchar(8) DEFAULT 'toto' NOT NULL,
	`groupe` ENUM('staff', 'student', 'other') NOT NULL,
	`date_de_creation` date  NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
