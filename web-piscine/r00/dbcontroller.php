<?php
class DBController {
    $host = "localhost:8100";
    $user = "root";
    $password = "root";
    $database = "spacedb";

    $connect = mysqli_connect('localhost:8100', $user, $password);
    $sql="CREATE DATABASE IF NOT EXISTS spacedb";
    if (mysqli_query($connect, $sql))
    echo "Database created successfully\n\n";
    else
     echo "Error creating database\n\n";

    function construct() {
        $connection = $connectDB();
    }

    function connectDB() {
        $connection = mysqli_connect($host, $user, $password, $database);
        return $connection;
    }

    function runQuery($query) {
        $result = mysqli_query($connection, $query);
        while ($row = mysqli_fetch_assoc($result)) {
            $setresult[] = $row;
        }
        if (!empty($setresult))
            return $setresult;
    }

    function Rows($query) {
        $result = mysqli_num_rows($result);
        return $rowcount;
    }
}
?>

