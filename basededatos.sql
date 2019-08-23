-- Adminer 4.7.2 MySQL dump

SET NAMES utf8;
SET time_zone = '+00:00';
SET foreign_key_checks = 0;
SET sql_mode = 'NO_AUTO_VALUE_ON_ZERO';

SET NAMES utf8mb4;

DROP TABLE IF EXISTS `Candidato`;
CREATE TABLE `Candidato` (
  `claveCandidato` varchar(50) NOT NULL,
  `nombre` varchar(200) NOT NULL,
  `apaterno` varchar(200) NOT NULL,
  `amaterno` varchar(200) NOT NULL,
  `partido` varchar(200) NOT NULL,
  `emblema` varchar(200) NOT NULL,
  `foto` varchar(200) NOT NULL,
  `idUsuario` int(11) NOT NULL,
  `idEleccion` int(11) NOT NULL,
  `cantidadVotos` int(15) NOT NULL,
  PRIMARY KEY (`claveCandidato`),
  KEY `fk_Candidato_Usuario1_idx` (`idUsuario`),
  KEY `fk_Candidato_Eleccion1_idx` (`idEleccion`),
  CONSTRAINT `Candidato_ibfk_1` FOREIGN KEY (`idUsuario`) REFERENCES `Usuario` (`idUsuario`) ON DELETE CASCADE ON UPDATE NO ACTION,
  CONSTRAINT `Candidato_ibfk_2` FOREIGN KEY (`idEleccion`) REFERENCES `Eleccion` (`idEleccion`) ON DELETE CASCADE ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

INSERT INTO `Candidato` (`claveCandidato`, `nombre`, `apaterno`, `amaterno`, `partido`, `emblema`, `foto`, `idUsuario`, `idEleccion`, `cantidadVotos`) VALUES
('CEGOR680712',	'RODRIGO',	'GOMEZ',	'CERVANTES',	'PRI',	':/imagenes/pri.png',	':/imagenes/cegor.png',	4,	1,	0),
('HEBEP760703',	'PATRICIA',	'BENITEZ',	'HERRERA',	'PAN',	':/imagenes/pan.png',	':/imagenes/hebep.png',	3,	1,	1),
('MOSUJ721209',	'JAVIER',	'SUAREZ',	'MORALES',	'INDEPENDIENTE',	':/imagenes/ind.png',	':/imagenes/mosuj.png',	5,	1,	0),
('ROMAJ710916',	'JUAN',	'ROBLES',	'MORALES',	'PRD',	':/imagenes/prd.png',	':/imagenes/roma.png',	2,	1,	0);

DELIMITER ;;

CREATE TRIGGER `Candidato_bi` BEFORE INSERT ON `Candidato` FOR EACH ROW
BEGIN
SET @pass = (SELECT SUBSTRING(MD5(RAND()) FROM 1 FOR 6));
INSERT INTO Usuario(password, tipoUsuario) VALUES(@pass, 2);
SET NEW.idUsuario = LAST_INSERT_ID();
END;;

CREATE TRIGGER `Candidato_ai` AFTER INSERT ON `Candidato` FOR EACH ROW
BEGIN
INSERT INTO Publicacion(estado, claveCandidato, idEleccion) VALUES(0, NEW.claveCandidato, NEW.idEleccion);
END;;

DELIMITER ;

DROP TABLE IF EXISTS `Eleccion`;
CREATE TABLE `Eleccion` (
  `idEleccion` int(11) NOT NULL AUTO_INCREMENT,
  `fechaJornada` date NOT NULL,
  `horaIniJornada` time NOT NULL,
  `horaFinJornada` time NOT NULL,
  PRIMARY KEY (`idEleccion`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

INSERT INTO `Eleccion` (`idEleccion`, `fechaJornada`, `horaIniJornada`, `horaFinJornada`) VALUES
(1,	'2019-08-13',	'10:01:08',	'10:01:08');

DROP TABLE IF EXISTS `Elector`;
CREATE TABLE `Elector` (
  `claveElector` varchar(50) NOT NULL,
  `nombre` varchar(200) NOT NULL,
  `apaterno` varchar(200) NOT NULL,
  `amaterno` varchar(200) NOT NULL,
  `yaVoto` int(11) NOT NULL,
  `idUsuario` int(11) NOT NULL,
  PRIMARY KEY (`claveElector`),
  KEY `fk_Elector_Usuario1_idx` (`idUsuario`),
  CONSTRAINT `fk_Elector_Usuario1` FOREIGN KEY (`idUsuario`) REFERENCES `Usuario` (`idUsuario`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

INSERT INTO `Elector` (`claveElector`, `nombre`, `apaterno`, `amaterno`, `yaVoto`, `idUsuario`) VALUES
('ADCOPL396995',	'Plato',	'Adams',	'Coleman',	0,	96),
('ADMICO378657',	'Cody',	'Adams',	'Miranda',	0,	83),
('ADMIN',	'Sergio',	'Martinez',	'Fernadez',	0,	1),
('AGMCMA364740',	'Malachi',	'Aguilar',	'Mcintyre',	0,	63),
('ALANSE559255',	'Sean',	'Alston',	'Anderson',	0,	105),
('ARBRMY656008',	'Myles',	'Armstrong',	'Bridges',	1,	66),
('BABAHE711774',	'Henry',	'Barrera',	'Barber',	0,	13),
('BADYKA981862',	'Kane',	'Barton',	'Dyer',	0,	95),
('BAFIFU330847',	'Fulton',	'Barry',	'Figueroa',	0,	89),
('BAHAMU966157',	'Mufutau',	'Baird',	'Harding',	0,	39),
('BECOMI546617',	'Michael',	'Berry',	'Conrad',	0,	35),
('BEWAHE193632',	'Herman',	'Bell',	'Walter',	0,	88),
('BLCRIR38977',	'Ira',	'Blankenship',	'Craig',	0,	18),
('BLMANO525723',	'Nolan',	'Blackburn',	'Macdonald',	0,	23),
('BLORMA576039',	'Malik',	'Blair',	'Ortiz',	0,	57),
('BOMOCA707415',	'Cade',	'Bowen',	'Moore',	0,	12),
('BRROLA706055',	'Lars',	'Browning',	'Roach',	0,	34),
('BRSNCA350109',	'Cade',	'Bradley',	'Snyder',	0,	36),
('BRWOHA396024',	'Hall',	'Brewer',	'Wong',	0,	97),
('BUFRCH493469',	'Chaim',	'Buckner',	'Fry',	0,	65),
('BUMIKE324155',	'Keith',	'Buchanan',	'Miranda',	0,	86),
('CAKICA50830',	'Carson',	'Cain',	'Kim',	0,	72),
('CALAIG380900',	'Igor',	'Carroll',	'Lancaster',	0,	100),
('CAMAMA814908',	'Mannix',	'Cantrell',	'Marshall',	0,	6),
('CAVAOR78843',	'Oren',	'Cain',	'Vasquez',	0,	15),
('CHWHSO873958',	'Solomon',	'Chavez',	'White',	0,	47),
('CLBACY448006',	'Cyrus',	'Clemons',	'Banks',	0,	20),
('CLLYDE406354',	'Deacon',	'Cleveland',	'Lynch',	0,	60),
('COCOMA638755',	'Malik',	'Copeland',	'Cohen',	0,	42),
('COHOCO878242',	'Conan',	'Cox',	'Holman',	0,	9),
('CORAOC504643',	'Octavius',	'Cote',	'Randall',	0,	74),
('CRLAOR920168',	'Orson',	'Crane',	'Lane',	0,	53),
('DUCOTO160926',	'Tobias',	'Dunn',	'Coleman',	0,	80),
('DULEHA785148',	'Hamilton',	'Durham',	'Leach',	0,	92),
('DUWHCA599462',	'Carl',	'Duffy',	'White',	0,	16),
('ERGRAS509403',	'Ashton',	'Erickson',	'Greer',	0,	45),
('FAWITH785682',	'Thomas',	'Faulkner',	'Wilkerson',	0,	55),
('FICOKE416606',	'Kenneth',	'Fitzgerald',	'Collier',	0,	21),
('FLPEDU795651',	'Dustin',	'Fletcher',	'Peters',	0,	25),
('FOGRHU516080',	'Hunter',	'Fox',	'Grimes',	0,	52),
('FOMOCE289392',	'Cedric',	'Fox',	'Moreno',	0,	59),
('GIKEDE452462',	'Dean',	'Gibson',	'Key',	0,	40),
('GOHOGA573871',	'Gannon',	'Gordon',	'Howell',	0,	70),
('GULAUP752878',	'Upton',	'Guerra',	'Lara',	0,	104),
('HAMAXA957737',	'Xander',	'Hayes',	'Mathews',	0,	73),
('HASINA910624',	'Nathan',	'Hartman',	'Simon',	0,	85),
('HECAKA722256',	'Kareem',	'Henson',	'Carney',	0,	8),
('HEGEMA638227',	'Martin',	'Hernandez',	'Gentry',	0,	10),
('HEHEOR741635',	'Orson',	'Hester',	'Herman',	0,	51),
('HOCHAK340618',	'Akeem',	'Hopper',	'Church',	0,	76),
('HORICO783458',	'Connor',	'House',	'Rice',	0,	68),
('HOSNHU191090',	'Hu',	'Holt',	'Snow',	0,	7),
('JABEAL222459',	'Allistair',	'James',	'Benson',	0,	93),
('KESNRO485783',	'Rogan',	'Keller',	'Snider',	0,	98),
('KIMACA294608',	'Cadman',	'Kirby',	'Marshall',	0,	61),
('KIMICO753676',	'Colby',	'Kinney',	'Mitchell',	0,	78),
('KROLGE420099',	'George',	'Kramer',	'Olson',	0,	24),
('LABOKN115703',	'Knox',	'Lang',	'Boone',	0,	102),
('LAMCRA804586',	'Rajah',	'Lara',	'Mcneil',	0,	77),
('LOWAFO833441',	'Forrest',	'Logan',	'Walter',	0,	49),
('MAHEGI817047',	'Gil',	'Martin',	'Hensley',	0,	31),
('MASAST524627',	'Stewart',	'Maldonado',	'Santos',	0,	30),
('MCACCO601737',	'Colt',	'Mckenzie',	'Acosta',	0,	101),
('MCCOKE260773',	'Keith',	'Mcmahon',	'Conway',	0,	56),
('MCPAPH718245',	'Phelan',	'Mcmahon',	'Pacheco',	0,	27),
('MEHUHA120472',	'Hayes',	'Melton',	'Hull',	0,	82),
('MIMIKA599616',	'Kamal',	'Miles',	'Michael',	0,	67),
('OCMOFR348381',	'Francis',	'Oconnor',	'Morales',	0,	46),
('ODPRMA116711',	'Marsden',	'Odom',	'Prince',	0,	50),
('OLJUIG109319',	'Igor',	'Olson',	'Juarez',	0,	71),
('ORBEIS95822',	'Isaac',	'Ortega',	'Bell',	0,	19),
('ORHAGR73882',	'Grady',	'Ortega',	'Hays',	0,	103),
('PACLMA609803',	'Maxwell',	'Padilla',	'Clay',	0,	87),
('PAPILA116723',	'Lawrence',	'Parsons',	'Pittman',	0,	29),
('PATIUR647828',	'Uriel',	'Parker',	'Tillman',	0,	84),
('PAWICL133880',	'Clarke',	'Pate',	'William',	0,	44),
('PECOAR456630',	'Arden',	'Pena',	'Cox',	0,	91),
('RAVERA76077',	'Rajah',	'Ratliff',	'Velasquez',	0,	81),
('RISABE877523',	'Bevis',	'Richards',	'Sanders',	0,	37),
('ROWOCU614169',	'Curran',	'Rocha',	'Wooten',	0,	14),
('SADEJO526090',	'Joseph',	'Santiago',	'Deleon',	0,	58),
('SCWAAB378705',	'Abel',	'Scott',	'Wallace',	0,	75),
('SHDEBR205089',	'Branden',	'Sharpe',	'Delgado',	0,	22),
('SHGOZE17870',	'Zeus',	'Sherman',	'Good',	0,	48),
('SIHORU893564',	'Russell',	'Silva',	'Horton',	0,	17),
('STDRDR812274',	'Drake',	'Steele',	'Drake',	0,	11),
('STSLBR690984',	'Brenden',	'Stephenson',	'Slater',	0,	94),
('STTRAI64564',	'Aidan',	'Stout',	'Tran',	0,	41),
('SUGRLU210314',	'Lucian',	'Sullivan',	'Graham',	0,	64),
('TALAHA574443',	'Hayden',	'Taylor',	'Lamb',	0,	99),
('TEMELE445016',	'Leroy',	'Terry',	'Mercado',	0,	79),
('TEWALU3471',	'Lucas',	'Terrell',	'Wall',	0,	28),
('TOMERE304795',	'Reece',	'Todd',	'Melton',	0,	32),
('TOMOSE57626',	'Sebastian',	'Townsend',	'Morton',	0,	54),
('WAESDA526157',	'Dane',	'Waller',	'Estrada',	0,	43),
('WAHAEL571864',	'Elijah',	'Walter',	'Haynes',	0,	62),
('WAKNTR135053',	'Troy',	'Wagner',	'Knowles',	0,	38),
('WARAJO968029',	'Jordan',	'Wallace',	'Randolph',	0,	26),
('WIGEAL756285',	'Alvin',	'Wilcox',	'George',	0,	33),
('WIJOQU541347',	'Quinn',	'Wilson',	'Jordan',	0,	69),
('WITICO574969',	'Coby',	'Wilder',	'Tillman',	0,	90);

DELIMITER ;;

CREATE TRIGGER `Elector_bi` BEFORE INSERT ON `Elector` FOR EACH ROW
BEGIN
SET @pass = (SELECT SUBSTRING(MD5(RAND()) FROM 1 FOR 6));
INSERT INTO Usuario(password, tipoUsuario) VALUES(@pass, 3);
SET NEW.idUsuario = LAST_INSERT_ID();
END;;

DELIMITER ;

DROP TABLE IF EXISTS `Publicacion`;
CREATE TABLE `Publicacion` (
  `folio` int(11) NOT NULL AUTO_INCREMENT,
  `titulo` varchar(200) DEFAULT NULL,
  `texto` longtext DEFAULT NULL,
  `estado` int(11) NOT NULL,
  `claveCandidato` varchar(50) NOT NULL,
  `idEleccion` int(11) NOT NULL,
  PRIMARY KEY (`folio`),
  KEY `fk_Publicacion_Candidato_idx` (`claveCandidato`),
  KEY `fk_Publicacion_Eleccion1_idx` (`idEleccion`),
  CONSTRAINT `Publicacion_ibfk_1` FOREIGN KEY (`claveCandidato`) REFERENCES `Candidato` (`claveCandidato`) ON DELETE CASCADE ON UPDATE NO ACTION,
  CONSTRAINT `Publicacion_ibfk_2` FOREIGN KEY (`idEleccion`) REFERENCES `Eleccion` (`idEleccion`) ON DELETE CASCADE ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

INSERT INTO `Publicacion` (`folio`, `titulo`, `texto`, `estado`, `claveCandidato`, `idEleccion`) VALUES
(1,	NULL,	NULL,	0,	'ROMAJ710916',	1),
(2,	NULL,	NULL,	0,	'HEBEP760703',	1),
(3,	'asdasd',	'aasdasdasdasdasd',	0,	'CEGOR680712',	1),
(4,	NULL,	NULL,	0,	'MOSUJ721209',	1);

DROP TABLE IF EXISTS `Usuario`;
CREATE TABLE `Usuario` (
  `idUsuario` int(11) NOT NULL AUTO_INCREMENT,
  `password` varchar(50) NOT NULL,
  `tipoUsuario` int(11) NOT NULL,
  PRIMARY KEY (`idUsuario`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

INSERT INTO `Usuario` (`idUsuario`, `password`, `tipoUsuario`) VALUES
(1,	'admin',	1),
(2,	'2ef5d9',	2),
(3,	'25de62',	2),
(4,	'2bf62b',	2),
(5,	'68eb29',	2),
(6,	'604ec5',	3),
(7,	'bb0c5f',	3),
(8,	'57d079',	3),
(9,	'077a04',	3),
(10,	'68cfb2',	3),
(11,	'20f7b1',	3),
(12,	'f105eb',	3),
(13,	'33e06a',	3),
(14,	'9cd199',	3),
(15,	'9ba369',	3),
(16,	'93a3c9',	3),
(17,	'a17340',	3),
(18,	'a86c0e',	3),
(19,	'909e3e',	3),
(20,	'57b362',	3),
(21,	'a9ae57',	3),
(22,	'd3efc8',	3),
(23,	'809d62',	3),
(24,	'914d31',	3),
(25,	'322bc9',	3),
(26,	'2a41cf',	3),
(27,	'3d07e8',	3),
(28,	'a1e7dd',	3),
(29,	'25ab91',	3),
(30,	'e3ccd5',	3),
(31,	'1b4f42',	3),
(32,	'751890',	3),
(33,	'432c8b',	3),
(34,	'5dc56f',	3),
(35,	'4a1d84',	3),
(36,	'08979c',	3),
(37,	'9d9994',	3),
(38,	'969277',	3),
(39,	'b70ed9',	3),
(40,	'5409fe',	3),
(41,	'ee6f81',	3),
(42,	'23dd68',	3),
(43,	'a79510',	3),
(44,	'7f66c1',	3),
(45,	'1057a0',	3),
(46,	'436b24',	3),
(47,	'9d294a',	3),
(48,	'f77975',	3),
(49,	'506af7',	3),
(50,	'86e43d',	3),
(51,	'fdd7c6',	3),
(52,	'2d951a',	3),
(53,	'923cb2',	3),
(54,	'ea9435',	3),
(55,	'a5d00d',	3),
(56,	'08f5a6',	3),
(57,	'ecbd0f',	3),
(58,	'5a0590',	3),
(59,	'ac6f19',	3),
(60,	'edf046',	3),
(61,	'c4adaf',	3),
(62,	'176da4',	3),
(63,	'689474',	3),
(64,	'97ae2f',	3),
(65,	'54a861',	3),
(66,	'0aaf07',	3),
(67,	'609e52',	3),
(68,	'1f2d44',	3),
(69,	'17daf7',	3),
(70,	'5f38d0',	3),
(71,	'7d9979',	3),
(72,	'a6cbd2',	3),
(73,	'1fdf59',	3),
(74,	'c19350',	3),
(75,	'147709',	3),
(76,	'8c206f',	3),
(77,	'd02276',	3),
(78,	'5a2ca1',	3),
(79,	'885594',	3),
(80,	'962ace',	3),
(81,	'ba5057',	3),
(82,	'985060',	3),
(83,	'a092bc',	3),
(84,	'647d8a',	3),
(85,	'0ea545',	3),
(86,	'71b64c',	3),
(87,	'4560dc',	3),
(88,	'029f7e',	3),
(89,	'e058bc',	3),
(90,	'f3ca1a',	3),
(91,	'964e1f',	3),
(92,	'8670b9',	3),
(93,	'db692a',	3),
(94,	'511c91',	3),
(95,	'323b01',	3),
(96,	'137aa3',	3),
(97,	'dbc5e9',	3),
(98,	'c4216d',	3),
(99,	'252517',	3),
(100,	'5ecf00',	3),
(101,	'd9161f',	3),
(102,	'3026c4',	3),
(103,	'5832a1',	3),
(104,	'ca8a62',	3),
(105,	'aa1666',	3);

DROP VIEW IF EXISTS `vListaCandidatos`;
CREATE TABLE `vListaCandidatos` (`claveCandidato` varchar(50), `candidato` text, `partido` varchar(200), `emblema` varchar(200), `foto` varchar(200));


DROP VIEW IF EXISTS `vPerfil`;
CREATE TABLE `vPerfil` (`nombre` text, `foto` varchar(200), `folio` int(11), `titulo` varchar(200), `texto` longtext, `estado` int(11), `claveCandidato` varchar(50), `idEleccion` int(11));


DROP VIEW IF EXISTS `vResultados`;
CREATE TABLE `vResultados` (`nombre` text, `partido` varchar(200), `emblema` varchar(200), `foto` varchar(200), `cantidadVotos` int(15), `porcentaje` decimal(18,4), `perc2` decimal(18,4));


DROP VIEW IF EXISTS `vUsuarios`;
CREATE TABLE `vUsuarios` (`usr` varchar(50), `usrnombre` varchar(602), `pass` varchar(50), `tipoUsuario` int(11), `idUsuario` int(11));


DROP TABLE IF EXISTS `vListaCandidatos`;
CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `vListaCandidatos` AS select `Candidato`.`claveCandidato` AS `claveCandidato`,concat(`Candidato`.`nombre`,' ',`Candidato`.`apaterno`,' ',`Candidato`.`amaterno`) AS `candidato`,`Candidato`.`partido` AS `partido`,`Candidato`.`emblema` AS `emblema`,`Candidato`.`foto` AS `foto` from `Candidato`;

DROP TABLE IF EXISTS `vPerfil`;
CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `vPerfil` AS select concat(`c`.`nombre`,' ',`c`.`apaterno`,' ',`c`.`amaterno`) AS `nombre`,`c`.`foto` AS `foto`,`p`.`folio` AS `folio`,`p`.`titulo` AS `titulo`,`p`.`texto` AS `texto`,`p`.`estado` AS `estado`,`p`.`claveCandidato` AS `claveCandidato`,`p`.`idEleccion` AS `idEleccion` from (`Candidato` `c` join `Publicacion` `p` on(`p`.`claveCandidato` = `c`.`claveCandidato`));

DROP TABLE IF EXISTS `vResultados`;
CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `vResultados` AS select concat(`Candidato`.`nombre`,' ',`Candidato`.`apaterno`,' ',`Candidato`.`amaterno`) AS `nombre`,`Candidato`.`partido` AS `partido`,`Candidato`.`emblema` AS `emblema`,`Candidato`.`foto` AS `foto`,`Candidato`.`cantidadVotos` AS `cantidadVotos`,`Candidato`.`cantidadVotos` / (select sum(`Candidato`.`cantidadVotos`) AS `totalVotos` from `Candidato`) AS `porcentaje`,`Candidato`.`cantidadVotos` / sum(`Candidato`.`cantidadVotos`) AS `perc2` from `Candidato` group by `Candidato`.`claveCandidato`;

DROP TABLE IF EXISTS `vUsuarios`;
CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `vUsuarios` AS select `e`.`claveElector` AS `usr`,concat(`e`.`nombre`,' ',`e`.`apaterno`,' ',`e`.`amaterno`) AS `usrnombre`,`u`.`password` AS `pass`,`u`.`tipoUsuario` AS `tipoUsuario`,`u`.`idUsuario` AS `idUsuario` from (`Elector` `e` join `Usuario` `u` on(`e`.`idUsuario` = `u`.`idUsuario`)) union select `c`.`claveCandidato` AS `usr`,concat(`c`.`nombre`,' ',`c`.`apaterno`,' ',`c`.`amaterno`) AS `usrnombre`,`l`.`password` AS `pass`,`l`.`tipoUsuario` AS `tipoUsuario`,`l`.`idUsuario` AS `idUsuario` from (`Candidato` `c` join `Usuario` `l` on(`c`.`idUsuario` = `l`.`idUsuario`));

-- 2019-08-23 15:58:26
