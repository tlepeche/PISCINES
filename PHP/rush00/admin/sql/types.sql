-- phpMyAdmin SQL Dump
-- version 4.3.11.1
-- http://www.phpmyadmin.net
--
-- Client :  localhost:3306
-- Généré le :  Sam 11 Avril 2015 à 16:04
-- Version du serveur :  5.5.40
-- Version de PHP :  5.4.39

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données :  `pokebase_db`
--

-- --------------------------------------------------------

--
-- Structure de la table `types`
--

CREATE TABLE IF NOT EXISTS `types` (
  `id` int(11) NOT NULL,
  `name` varchar(64) NOT NULL,
  `simg` varchar(256) NOT NULL,
  `limg` varchar(256) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `types`
--

INSERT INTO `types` (`id`, `name`, `simg`, `limg`) VALUES
(0, 'Aucun', '', ''),
(1, 'Acier', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/1.png', ''),
(2, 'Dragon', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/3.png', ''),
(3, 'Electrik', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/5.png', ''),
(4, 'Feu', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/6.png', ''),
(5, 'Insecte', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/8.png', ''),
(6, 'Plante', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/10.png', ''),
(7, 'Psy', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/12.png', ''),
(8, 'Sol', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/14.png', ''),
(9, 'Tenebres', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/16.png', ''),
(10, 'Combat', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/2.png', ''),
(11, 'Eau', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/4.png', ''),
(12, 'Fee', '', ''),
(13, 'Glace', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/7.png', ''),
(14, 'Normal', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/9.png', ''),
(15, 'Poison', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/11.png', ''),
(16, 'Roche', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/13.png', ''),
(17, 'Spectre', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/15.png', ''),
(18, 'Vol', 'http://www.pokebip.com/pokemon/pokedex/images/gen5_types/17.png', '');

--
-- Index pour les tables exportées
--

--
-- Index pour la table `types`
--
ALTER TABLE `types`
  ADD PRIMARY KEY (`id`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
