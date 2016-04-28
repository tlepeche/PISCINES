-- phpMyAdmin SQL Dump
-- version 4.3.11.1
-- http://www.phpmyadmin.net
--
-- Host: localhost:3306
-- Generation Time: Apr 11, 2015 at 09:27 PM
-- Server version: 5.5.40
-- PHP Version: 5.4.39

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `pokebase_db`
--

-- --------------------------------------------------------

--
-- Table structure for table `pokedex`
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
-- Dumping data for table `pokedex`
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

--
-- Indexes for dumped tables
--

--
-- Indexes for table `pokedex`
--
ALTER TABLE `pokedex`
  ADD PRIMARY KEY (`id`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
