<?php
$servername = "localhost";
$username = "root";
$password = ""; // Add your database password here
$dbname = "iis23140";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// SQL to create table
$tableName = "iis23140"; // Replace with your uom mail name
$sql = "CREATE TABLE IF NOT EXISTS $tableName (
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    email VARCHAR(255) NOT NULL
)";

if ($conn->query($sql) === TRUE) {
    echo "Ο πίνακας δημιουργήθηκε επιτυχώς.";
} else {
    echo "ΔΔΔ - ΠΡΟΒΛΗΜΑ στη δημιουργία του πίνακα: " . $conn->error;
}

$conn->close();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Αρχική Σελίδα</title>
</head>
<style>
    footer{
        color: orange;
        font-size: larger;
    }
</style>
<body>
    <br><br>
    <a href="epexergasia.php">Επεξεργασία</a>
    
</body>
<footer><br>ΚΩΝΣΤΑΝΤΙΝΑ ΚΥΡΙΑΚΟΥ <br> iis23140@uom.edu.gr</footer>
</html>

