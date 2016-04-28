-- phpMyAdmin SQL Dump
-- version 4.3.11.1
-- http://www.phpmyadmin.net
--
-- Client :  localhost:3306
-- Généré le :  Dim 12 Avril 2015 à 07:22
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
-- Structure de la table `address`
--

CREATE TABLE IF NOT EXISTS `address` (
  `id` int(11) NOT NULL,
  `first_name` varchar(64) NOT NULL,
  `last_name` varchar(64) NOT NULL,
  `email` varchar(128) NOT NULL,
  `address` varchar(256) NOT NULL,
  `city` varchar(64) NOT NULL,
  `state` varchar(64) NOT NULL,
  `zip` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `bill`
--

CREATE TABLE IF NOT EXISTS `bill` (
  `id` int(11) NOT NULL,
  `log_id` int(11) NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `total` int(11) NOT NULL,
  `cmd_id` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `cart`
--

CREATE TABLE IF NOT EXISTS `cart` (
  `id` int(10) unsigned NOT NULL,
  `log_id` int(11) NOT NULL,
  `pkm_id` int(11) NOT NULL,
  `qty` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=43 DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `cart_tmp`
--

CREATE TABLE IF NOT EXISTS `cart_tmp` (
  `id` int(11) unsigned NOT NULL,
  `log_id` int(11) NOT NULL,
  `pkm_id` int(11) NOT NULL,
  `qty` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `login`
--

CREATE TABLE IF NOT EXISTS `login` (
  `id` int(11) unsigned NOT NULL,
  `login` varchar(64) NOT NULL,
  `password` varchar(256) NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `lvl` int(10) unsigned NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `order`
--

CREATE TABLE IF NOT EXISTS `order` (
  `id` int(11) NOT NULL,
  `log_id` int(11) NOT NULL,
  `pkm_id` int(11) NOT NULL,
  `qty` int(11) NOT NULL,
  `cmd_id` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=58 DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `pokedex`
--

CREATE TABLE IF NOT EXISTS `pokedex` (
  `id` int(11) NOT NULL,
  `name` varchar(64) NOT NULL,
  `type1` int(11) NOT NULL,
  `type2` int(11) NOT NULL,
  `price` int(11) NOT NULL,
  `simg` varchar(256) NOT NULL,
  `limg` varchar(256) NOT NULL,
  `vlimg` varchar(256) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `pokedex`
--

INSERT INTO `pokedex` (`id`, `name`, `type1`, `type2`, `price`, `simg`, `limg`, `vlimg`) VALUES
(0, 'Missingno.', 13, 0, 9000, '', '', 'http://vignette4.wikia.nocookie.net/ultimate-pokemon-fanon/images/8/85/Missingno_drawing_by_aerostat-d4krmly.jpg/revision/latest?cb=20130916223342'),
(1, 'Bulbizarre', 6, 15, 200, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/1.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/001.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/001.png'),
(2, 'Herbizarre', 6, 15, 400, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/2.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/002.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/002.png'),
(3, 'Florizarre', 6, 15, 600, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/3.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/003.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/003.png'),
(4, 'Salameche', 4, 0, 200, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/4.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/004.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/004.png'),
(5, 'Reptincel', 4, 0, 400, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/5.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/005.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/005.png'),
(6, 'Dracaufeu', 4, 18, 600, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/6.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/006.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/006.png'),
(7, 'Carapuce', 11, 0, 200, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/7.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/007.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/007.png'),
(8, 'Carabaffe', 11, 0, 400, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/8.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/008.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/008.png'),
(9, 'Tortank', 11, 0, 600, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/9.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/009.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/009.png'),
(10, 'Chenipan', 5, 0, 200, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/10.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/010.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/010.png'),
(11, 'Chrysacier', 5, 0, 400, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/11.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/011.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/011.png'),
(12, 'Papilusion', 5, 18, 600, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/12.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/012.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/012.png'),
(25, 'Pikachu', 3, 0, 200, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/25.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/025.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/025.png'),
(42, 'Nosferalto', 18, 15, 42, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/42.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/042.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/042.png'),
(54, 'Psykokwak', 11, 0, 250, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/54.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/054.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/054.png'),
(63, 'Abra', 7, 0, 200, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/63.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/063.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/063.png'),
(64, 'Kadabra', 7, 0, 400, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/64.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/064.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/064.png'),
(74, 'Racaillou', 8, 16, 200, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/74.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/074.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/074.png'),
(75, 'Gravalanch', 8, 16, 400, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/75.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/075.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/075.png'),
(93, 'Spectrum', 17, 15, 400, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/93.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/093.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/093.png'),
(94, 'Ectoplasma', 17, 15, 600, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/94.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/094.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/094.png'),
(107, 'Tygnon', 10, 0, 300, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/107.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/107.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/107.png'),
(115, 'Kangourex', 14, 0, 300, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/115.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/115.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/115.png'),
(140, 'Kabuto', 16, 11, 300, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/140.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/140.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/140.png'),
(141, 'Kabutops', 16, 11, 300, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/141.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/141.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/141.png'),
(144, 'Artikodin', 13, 18, 500, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/144.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/144.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/144.png'),
(145, 'Electhor', 3, 18, 500, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/145.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/145.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/145.png'),
(146, 'Sulfura', 4, 18, 500, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/146.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/146.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/146.png'),
(147, 'Minidraco', 2, 0, 250, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/147.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/147.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/147.png'),
(148, 'Draco', 2, 0, 500, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/148.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/148.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/148.png'),
(150, 'Mewtwo', 7, 0, 800, 'http://www.pokebip.com/pokemon/pokedex/images/gen5_miniatures/150.png', 'http://www.pokebip.com/pokemon/pokedex/images/bw_animes/150.gif', 'http://assets22.pokemon.com/assets/cms2/img/pokedex/full/150.png');

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
-- Index pour la table `address`
--
ALTER TABLE `address`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `bill`
--
ALTER TABLE `bill`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `cart`
--
ALTER TABLE `cart`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `cart_tmp`
--
ALTER TABLE `cart_tmp`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `login`
--
ALTER TABLE `login`
  ADD PRIMARY KEY (`id`), ADD UNIQUE KEY `login` (`login`);

--
-- Index pour la table `order`
--
ALTER TABLE `order`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `pokedex`
--
ALTER TABLE `pokedex`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `types`
--
ALTER TABLE `types`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `bill`
--
ALTER TABLE `bill`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=21;
--
-- AUTO_INCREMENT pour la table `cart`
--
ALTER TABLE `cart`
  MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=43;
--
-- AUTO_INCREMENT pour la table `cart_tmp`
--
ALTER TABLE `cart_tmp`
  MODIFY `id` int(11) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=15;
--
-- AUTO_INCREMENT pour la table `login`
--
ALTER TABLE `login`
  MODIFY `id` int(11) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=19;
--
-- AUTO_INCREMENT pour la table `order`
--
ALTER TABLE `order`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=58;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
