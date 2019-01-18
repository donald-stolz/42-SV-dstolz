<?PHP
echo "Please write your login:\n";
$login = trim(fgets(STDIN));
echo "Please write your password:\n";
$password = trim(fgets(STDIN));
$connect = mysqli_connect('local.42.fr', $login, $password);
$sql="CREATE DATABASE IF NOT EXISTS spacedb";
if (mysqli_query($connect, $sql))
	echo "Database created successfully\n\n";
else
	echo "Error creating database\n\n";
echo "Please write your admin-login:\n";
$admin_login = trim(fgets(STDIN));
echo "Please write your admin-password:\n";
$admin_password = hash("whirlpool", trim(fgets(STDIN)));
$connect = mysqli_connect('local.42.fr', $login, $password, "spacedb");
$sql="CREATE TABLE user(login CHAR(30),passwd CHAR(128),admin CHAR(1), root_access INT)";
if (mysqli_query($connect, $sql))
	echo "Table created successfully\n\n";
else
	echo "Error creating table\n\n";
$sql = "INSERT INTO `spacedb`.`user` (`login`, `passwd`, `admin`, `root_access`) VALUES ('$admin_login', '$admin_password', '1', '0')";
if (mysqli_query($connect, $sql))
	echo "Admin added successfully\n\n";
else
	echo "Error adding admin\n\n";
$sql="CREATE TABLE product(id CHAR(30), name varchar(255) NOT NULL, image text NOT NULL, price int(15) NOT NULL";
if (mysqli_query($connect, $sql))
	echo "Table created successfully\n\n";
else
	echo "Error creating table\n\n";
?>
