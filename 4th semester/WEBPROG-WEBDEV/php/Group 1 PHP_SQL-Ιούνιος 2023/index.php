<?php
// Database connection
$servername = "localhost";
$username = "root";  // replace with your MySQL username
$password = "";  // replace with your MySQL password
$dbname = "iis23140";  // replace with your database name

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Create table
$table_name = "iis23123";
$sql = "CREATE TABLE IF NOT EXISTS $table_name (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50) NOT NULL
)";

if ($conn->query($sql) === TRUE) {
    echo "<p>Ο πίνακας δημιουργήθηκε με επιτυχία.</p>";
} else {
    echo "<p>Απέτυχε η δημιουργία πίνακα: " . $conn->error . "</p>";
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="el">
<head>
    <meta charset="UTF-8">
    <title>Αρχική Σελίδα</title>
</head>
<style>
  footer{
    color: red;
  }
</style>
<body>
    <p><a href='kataxorisi.php'>Καταχώριση</a></p>
    <p><a href='diorthosi.php'>Διόρθωση</a></p>
    <footer>
        <h1>ΚΩΝΣΤΑΝΤΙΝΑ ΚΥΡΙΑΚΟΥ <br>iis23140@uom.edu.gr</h1>
    </footer>
</body>
</html>
