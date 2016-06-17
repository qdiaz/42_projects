<?php
session_start();
include'config.php';
?>
<html>
	<head>
		<title>Motorhead</title>
		<link rel="stylesheet" type="text/css" href="style.css">
	</head>
	<body>
		<a href="http://e1r2p18.42.fr:8080/rush/index.php"><div class="banner">Motorhead</div></a>
		<div class="leftmodule">
			<div class="blocs">Moto:</div><br /><br />
			<ul id="menu" class="classe">
				<li>
					<a href="#">Marques &rsaquo;</a>
					<ul>
						<a href="#"><li>Yamaha</li></a>
						<a href="#"><li>Guzzi</li></a>
						<a href="#"><li>Kawasaki</li></a>
						<a href="#"><li>Suzuki</li></a>
						<a href="#"><li>Ducati</li></a>
						<a href="#"><li>Bmw</li></a>
						<a href="#"><li>Triumph</li></a>
					</ul>
				</li>
			</ul><br />
			<ul class="classe" id="menu">
				<li>
					<a href="#">Ann&eacute;es  &rsaquo;</a>
					<ul id="year">
						<a href="#"><li>- 2009 -</li></a>
						<a href="#"><li>- 2010 -</li></a>
						<a href="#"><li>- 2012 -</li></a>
						<a href="#"><li>- 2014 -</li></a>
						<a href="#"><li>- 2015 -</li></a>
					</ul>
				</li>
			</ul><br />
			<ul class="classe" id="menu">
				<li>
					<a href="#:\">Cylindr&eacute;es &rsaquo;</a>
					<ul id="year">
						<a href="#"><li>600cc</li></a>
						<a href="#"><li>750cc</li></a>
						<a href="#"><li>900cc</li></a>
						<a href="#"><li>1200cc</li></a>
					</ul>
				</li>
			</ul><br /><br />
			<div class="blocs">Accessoires:</div><br /><br />
			<ul class="classe" id="menu">
				<li>
					<a href="#">Casques &rsaquo;</a>
					<ul>
						<a href="#"><li>Caca</li></a>
						<a href="#"><li>Caca</li></a>
						<a href="#"><li>Caca</li></a>
						<a href="#"><li>Caca</li></a>
						<a href="#"><li>Caca</li></a>
					</ul>
				</li>
			</ul><br />
			<ul class="classe" id="menu">
				<li>
					<a href="#">Equipements &rsaquo;</a>
					<ul>
						<a href="#"><li>Caca</li></a>
						<a href="#"><li>Caca</li></a>
						<a href="#"><li>Caca</li></a>
						<a href="#"><li>Caca</li></a>
						<a href="#"><li>Caca</li></a>
					</ul>
				</li>
			</ul><br /><br />
		</div>
		<div class="rightmodule">
			<form action"index.php" method="POST" class="log">
			Identifiant: <br /><input type="text" name="login" value="" placeholder="Identifiant" class="sub"><br />
			Mot de passe: <br /><input type="password" name ="passwd" value="" placeholder="Mot de passe" class="sub"><br /><br />
			<input type="submit" name="submit" value="Connexion" class="sub">
			</form>
			<div class="modif">
				<a href="create.html" class="ident">S'inscrire</a><br /><p>Ou</p>
				<a href="modif.html" class="ident">Modifier son mot de passe</a><br />
			</div>
			<div class="log"><br />
				<a href="#" class="panier">Mon panier</a><p>Total des achats:</p>
				<input readonly type="text" name="total" value="12.5&#8364;" class="achat">
			</div>
		</div>
	</body>
</html>
