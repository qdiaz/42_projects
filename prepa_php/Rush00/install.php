<?php
include('./config.php');
$mysqli = mysqli_connect($mysqli_host, $mysqli_user, $mysqli_pass);
mysqli_query($mysqli, "CREATE DATABASE $mysqli_db");
mysqli_close($mysqli);

$mysqli = mysqli_connect($mysqli_host, $mysqli_user, $mysqli_pass, $mysqli_db, $mysqli_port);
$req = "CREATE TABLE IF NOT EXISTS `users` (`username` varchar(255) NOT NULL,`password` varchar(255) NOT NULL,`name` varchar(255) NOT NULL,`classe` int(11) NOT NULL,UNIQUE KEY `username` (`username`)) ENGINE=InnoDB DEFAULT CHARSET=utf8;";
mysqli_query($mysqli, $req);
$req = "INSERT INTO `users` (`username`, `password`, `name`, `classe`) VALUES('Quentin', 'qdiaz', 'Quentin Diaz', '3'),('client1', 'client1', 'Client1', '0'), ('client2', 'client2', 'Client2', '0');";
mysqli_query($mysqli, $req);
$req = " CREATE TABLE IF NOT EXISTS `catalog` (`ID` int(11) NOT NULL AUTO_INCREMENT,`marque` text NOT NULL,`modele` text NOT NULL,`price` int(11) NOT NULL,`img` varchar(500) NOT NULL,`cylindree` text NOT NULL, `date` text NOT NULL, `stock` int(11) NOT NULL,PRIMARY KEY (`ID`)) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=15;";
mysqli_query($mysqli, $req);
$req = "INSERT INTO `catalog` (`ID`, `marque`, `modele`, `price`, `img`, `cylindree`, `date`, `stock`) VALUES"
	."(1, 'Yamaha', 'XJ6', 6000, 'https://cdn.yamaha-motor.eu/product_assets/2015/XJ6N/950-75/2015-Yamaha-XJ6-EU-Race-Blu-Studio-007.jpg', '600', '2014', 1),"
	."(2, 'Moto-Guzzi', 'V7', 6000, 'http://pictures.topspeed.com/IMG/crop/201203/moto-guzzi-v7-racer-11_600x0w.jpg', '750', 2012, 1),"
	."(3, 'Yamaha', 'MT-07', 5700, 'http://d1o5dtyz8r69kc.cloudfront.net/1159.jpg', '700', '2014', 1),"
	."(4, 'kawasaki', 'er6-n', 3000, 'http://storage.kawasaki.eu/public/kawasaki.eu/en-EU/model/14ER650F_44SWHTDRS2CG_C.png', '600', '2010', 1),"
	."(5, 'Suzuki', 'Bandit', 2000, 'http://www.motorcyclespecs.co.za/Gallery%20%20A/Suzuki%20GSF%201200S%20Bandit%2006%20%203.jpg', '1200', '2010', 1),"
	."(6, 'Ducati', 'Monster', 3500, 'http://www.motoplanete.com/ducati/zoom-700px/Ducati-1200-monster-2015-700px.jpg', '1200', '2015', 1),"
	."(7, 'BMW', 'GS', 13000, 'http://allroadendurotouring.com/wp-content/uploads/2015/01/BMWR1200GSAdventure2015DSMotorcycle.jpg', '1200', '2015', 1),"
	."(8, 'Triumph', 'Thruxton', 7000, 'http://www.moto-addict.com/blog/images/articles/EssaisMotos/Triumph/Thruxton/02.jpg', '900', '2009', 1),"
	."(9, 'Triumph', 'Thruxton', 7000, 'http://www.moto-addict.com/blog/images/articles/EssaisMotos/Triumph/Thruxton/02.jpg', '900', '2009', 1),"
	."(10, 'Triumph', 'Thruxton', 7000, 'http://www.moto-addict.com/blog/images/articles/EssaisMotos/Triumph/Thruxton/02.jpg', '900', '2009', 1),"
	."(11, 'Triumph', 'Thruxton', 7000, 'http://www.moto-addict.com/blog/images/articles/EssaisMotos/Triumph/Thruxton/02.jpg', '900', '2009', 1),"
	."(12, 'Moto-Guzzi', 'V7', 6000, 'http://pictures.topspeed.com/IMG/crop/201203/moto-guzzi-v7-racer-11_600x0w.jpg', '750', 2012, 1);";
mysqli_query($mysqli, $req);
$req = " CREATE TABLE IF NOT EXISTS `casque` (`ID` int(11) NOT NULL AUTO_INCREMENT,`marque` text NOT NULL, `type` text NOT NULL, `modele` text NOT NULL, `price` int(11) NOT NULL,`img` varchar(500) NOT NULL,`taille` text NOT NULL, `stock` int(11) NOT NULL,PRIMARY KEY (`ID`)) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=15;";
mysqli_query($mysqli, $req);
$req = "INSERT INTO `casque` (`ID`, `marque`, `type`, `modele`, `price`, `img`, `taille`, `stock`) VALUES"
	."(1, 'Bell', 'integral', 'Bullit solid', 512, 'http://media09.motoblouz.com/images/catalogue/bullitt_gloss_black.jpg', 'S', '12'),"
	."(2, 'Bell', 'integral', 'Bullit solid', 512, 'http://media09.motoblouz.com/images/catalogue/bullitt_gloss_black.jpg', 'M', '15'),"
	."(3, 'Bell', 'integral', 'Bullit solid', 512, 'http://media09.motoblouz.com/images/catalogue/bullitt_gloss_black.jpg', 'L', '10'),"
	."(4, 'Bell', 'integral', 'Bullit solid', 512, 'http://media09.motoblouz.com/images/catalogue/bullitt_gloss_black.jpg', 'XL', '11'),"
	."(5, 'Bell', 'integral', 'Bullit solid', 512, 'http://media09.motoblouz.com/images/catalogue/bullitt_gloss_black.jpg', 'XXL', '7'),"
	."(6, 'Bell', 'integral', 'Bullit carbon', 730, 'http://media09.motoblouz.com/images/catalogue/el0184_bleu.jpg', 'S', '7'),"
	."(7, 'Bell', 'integral', 'Bullit carbon', 730, 'http://media09.motoblouz.com/images/catalogue/el0184_bleu.jpg', 'M', '7'),"
	."(8, 'Bell', 'integral', 'Bullit carbon', 730, 'http://media09.motoblouz.com/images/catalogue/el0184_bleu.jpg', 'L', '7'),"
	."(9, 'Bell', 'integral', 'Bullit carbon', 730, 'http://media09.motoblouz.com/images/catalogue/el0184_bleu.jpg', 'XL', '7'),"
	."(10, 'Bell', 'integral', 'Bullit carbon', 730, 'http://media09.motoblouz.com/images/catalogue/el0184_bleu.jpg', 'XXL', '7'),"
	."(11, 'Premier', 'integral', 'Trophy carbon', 312, 'http://media09.motoblouz.com/images/catalogue/trophy_carbon.jpg', 'S', '7'),"
	."(12, 'Premier', 'integral', 'Trophy carbon', 312, 'http://media09.motoblouz.com/images/catalogue/trophy_carbon.jpg', 'M', '7'),"
	."(13, 'Premier', 'integral', 'Trophy carbon', 312, 'http://media09.motoblouz.com/images/catalogue/trophy_carbon.jpg', 'L', '7'),"
	."(14, 'Premier', 'integral', 'Trophy carbon', 312, 'http://media09.motoblouz.com/images/catalogue/trophy_carbon.jpg', 'XL', '7'),"
	."(15, 'Premier', 'integral', 'Trophy vintage', 312, 'http://media09.motoblouz.com/images/catalogue/premier_trophy_ck_one_old_style_silver.jpg', 'S', '7'),"
	."(16, 'Premier', 'integral', 'Trophy vintage', 312, 'http://media09.motoblouz.com/images/catalogue/premier_trophy_ck_one_old_style_silver.jpg', 'M', '7'),"
	."(17, 'Premier', 'integral', 'Trophy vintage', 312, 'http://media09.motoblouz.com/images/catalogue/premier_trophy_ck_one_old_style_silver.jpg', 'L', '7'),"
	."(18, 'Premier', 'integral', 'Trophy vintage', 312, 'http://media09.motoblouz.com/images/catalogue/premier_trophy_ck_one_old_style_silver.jpg', 'XL', '7'),"
	."(19, 'HJC', 'jet', 'FG 70S', 145, 'http://media09.motoblouz.com/images/catalogue/fg_70s_rubertone_flat_b.jpg', 'S', '7'),"
	."(20, 'HJC', 'jet', 'FG 70S', 145, 'http://media09.motoblouz.com/images/catalogue/fg_70s_rubertone_flat_b.jpg', 'M', '7'),"
	."(21, 'HJC', 'jet', 'FG 70S', 145, 'http://media09.motoblouz.com/images/catalogue/fg_70s_rubertone_flat_b.jpg', 'L', '7'),"
	."(22, 'HJC', 'jet', 'FG 70S', 145, 'http://media09.motoblouz.com/images/catalogue/fg_70s_rubertone_flat_b.jpg', 'XL', '7'),"
	."(23, 'SHOEI', 'jet', 'JO UNI', 329, 'http://media09.motoblouz.com/images/catalogue/joblack.jpg', 'S', '7'),"
	."(24, 'SHOEI', 'jet', 'JO UNI', 329, 'http://media09.motoblouz.com/images/catalogue/joblack.jpg', 'M', '7'),"
	."(25, 'SHOEI', 'jet', 'JO UNI', 329, 'http://media09.motoblouz.com/images/catalogue/joblack.jpg', 'L', '7'),"
	."(26, 'SHOEI', 'jet', 'JO UNI', 329, 'http://media09.motoblouz.com/images/catalogue/joblack.jpg', 'XL', '7');";
mysqli_query($mysqli, $req);
$req = " CREATE TABLE IF NOT EXISTS `equipement` (`ID` int(11) NOT NULL AUTO_INCREMENT,`marque` text NOT NULL, `type` text NOT NULL, `modele` text NOT NULL, `price` int(11) NOT NULL,`img` varchar(500) NOT NULL,`taille` text NOT NULL, `stock` int(11) NOT NULL,PRIMARY KEY (`ID`)) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=15;";
mysqli_query($mysqli, $req);
$req = "INSERT INTO `equipement` (`ID`, `marque`, `type`, `modele`, `price`, `img`, `taille`, `stock`) VALUES"
	."(1, 'Segura', 'blouson', 'retro', '400', 'http://media09.motoblouz.com/images/catalogue/retro_camel_dsc1505_52efc027064cf.jpg', 'S', '3'),"
	."(2, 'Segura', 'blouson', 'retro', '400', 'http://media09.motoblouz.com/images/catalogue/retro_camel_dsc1505_52efc027064cf.jpg', 'M', '3'),"
	."(3, 'Segura', 'blouson', 'retro', '400', 'http://media09.motoblouz.com/images/catalogue/retro_camel_dsc1505_52efc027064cf.jpg', 'L', '3'),"
	."(4, 'Segura', 'blouson', 'retro', '400', 'http://media09.motoblouz.com/images/catalogue/retro_camel_dsc1505_52efc027064cf.jpg', 'XL', '3'),"
	."(5, 'Helstons', 'blouson', 'track rag', '450', 'http://media09.motoblouz.com/images/catalogue/track_cow_crust_camel.jpg', 'S', '3'),"
	."(6, 'Helstons', 'blouson', 'track rag', '450', 'http://media09.motoblouz.com/images/catalogue/track_cow_crust_camel.jpg', 'M', '3'),"
	."(7, 'Helstons', 'blouson', 'track rag', '450', 'http://media09.motoblouz.com/images/catalogue/track_cow_crust_camel.jpg', 'L', '3'),"
	."(8, 'Helstons', 'blouson', 'track rag', '450', 'http://media09.motoblouz.com/images/catalogue/track_cow_crust_camel.jpg', 'XL', '3'),"
	."(9, 'Helstons', 'bottes', 'challenge 60', '180', 'http://media09.motoblouz.com/images/catalogue/challenge_cuir_noir.jpg', 'S', '3'),"
	."(10, 'Helstons', 'bottes', 'challenge 60', '180', 'http://media09.motoblouz.com/images/catalogue/challenge_cuir_noir.jpg', 'M', '3'),"
	."(11, 'Helstons', 'bottes', 'challenge 60', '180', 'http://media09.motoblouz.com/images/catalogue/challenge_cuir_noir.jpg', 'L', '3'),"
	."(12, 'Helstons', 'bottes', 'challenge 60', '180', 'http://media09.motoblouz.com/images/catalogue/challenge_cuir_noir.jpg', 'XL', '3'),"
	."(13, 'Stylmartin', 'bottes', 'Rocket', '235', 'http://media09.motoblouz.com/images/catalogue/rocket_1_56a5fe36ca6fd.jpg', 'S', '3'),"
	."(14, 'Stylmartin', 'bottes', 'Rocket', '235', 'http://media09.motoblouz.com/images/catalogue/rocket_1_56a5fe36ca6fd.jpg', 'M', '3'),"
	."(15, 'Stylmartin', 'bottes', 'Rocket', '235', 'http://media09.motoblouz.com/images/catalogue/rocket_1_56a5fe36ca6fd.jpg', 'L', '3'),"
	."(16, 'Stylmartin', 'bottes', 'Rocket', '235', 'http://media09.motoblouz.com/images/catalogue/rocket_1_56a5fe36ca6fd.jpg', 'XL', '3'),"
	."(17, 'Helstons', 'gants', 'York', '60', 'http://media09.motoblouz.com/images/catalogue/img_6180.jpg', 'S', '3'),"
	."(18, 'Helstons', 'gants', 'York', '60', 'http://media09.motoblouz.com/images/catalogue/img_6180.jpg', 'M', '3'),"
	."(19, 'Helstons', 'gants', 'York', '60', 'http://media09.motoblouz.com/images/catalogue/img_6180.jpg', 'L', '3'),"
	."(20, 'Dainese', 'gants', 'Blackjack', '66', 'http://media09.motoblouz.com/images/catalogue/Gants-ete-Dainese-GUANTO-BLACKJACK-1.jpg', 'S', '3'),"
	."(21, 'Dainese', 'gants', 'Blackjack', '66', 'http://media09.motoblouz.com/images/catalogue/Gants-ete-Dainese-GUANTO-BLACKJACK-1.jpg', 'M', '3'),"
	."(22, 'Dainese', 'gants', 'Blackjack', '66', 'http://media09.motoblouz.com/images/catalogue/Gants-ete-Dainese-GUANTO-BLACKJACK-1.jpg', 'L', '3'),"
	."(23, 'Dainese', 'gants', 'Blackjack', '66', 'http://media09.motoblouz.com/images/catalogue/Gants-ete-Dainese-GUANTO-BLACKJACK-1.jpg', 'XL', '3');";
mysqli_query($mysqli, $req);

echo "Install [OK]";

mysqli_close($mysqli);
?>
