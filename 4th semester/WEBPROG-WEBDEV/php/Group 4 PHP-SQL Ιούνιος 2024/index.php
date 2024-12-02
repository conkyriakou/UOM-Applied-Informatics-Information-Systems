<?php
// Database connection
$servername = "localhost";
$username = "root";  // replace with your MySQL username
$password = "";  // replace with your MySQL password
$dbname = "iis23140";  // replace with your database name

// Create connection
$conn = new mysqli($servername, $username, $password);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Create database if it doesn't exist
$sql = "CREATE DATABASE IF NOT EXISTS $dbname";
if ($conn->query($sql) === TRUE) {
    $conn->select_db($dbname);
    
    // Create table if it doesn't exist
    $sql = "CREATE TABLE IF NOT EXISTS users (
        name VARCHAR(50) NOT NULL,
        email VARCHAR(50) NOT NULL
    )";

    if ($conn->query($sql) === TRUE) {
        echo "Η Βάση Δεδομένων και ο πίνακας δημιουργήθηκαν επιτυχώς.";
    } else {
        echo "Πρόβλημα στην δημιουργία πίνακα: " . $conn->error;
    }
} else {
    echo "Πρόβλημα στην δημιουργία Βάση Δεδομένων: " . $conn->error;
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Main Page</title>
</head>
<style>
    footer{
        color: brown;
        font-size: x-large;
    }
</style>
<body>
    <ul>
        <li><a href="emfanizo.php">Εμφανίζω</a></li>
        <li><a href="eisago.php">Εισαγωγή</a></li>
    </ul>
    <footer>
        <p>KONSTANTINA KYRIAKOU <br>
        iis23140@uom.edu.gr</p>
    </footer>
</body>
</html>
