<?php
// Database connection
$servername = "localhost";
$username = "root";  // replace with your MySQL username
$password = "";  // replace with your MySQL password
$dbname = "iis23140";  // replace with your database name

$conn = new mysqli($servername, $username, $password, $dbname);

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST["name"];

    // Name validation (ensure it's not empty and only contains valid characters)
    if (!empty($name) && preg_match("/^[a-zA-Z\\s]+$/", $name)) {
        $stmt = $conn->prepare("INSERT INTO iis23123 (name) VALUES (?)");
        $stmt->bind_param("s", $name);
        
        if ($stmt->execute()) {
            echo "<p>Επιτυχής εισαγωγή δεδομένων. Πλήθος νέων εγγραφών: " . $conn->affected_rows . "</p>";
        } else {
            echo "<p>Απέτυχε η εισαγωγή δεδομένων</p>";
        }
        $stmt->close();
    } else {
        echo "<p>Invalid name format</p>";
    }
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="el">
<head>
    <meta charset="UTF-8">
    <title>Καταχώριση</title>
</head>
<style>
  footer{
    color: red;
  }
</style>
<body>
    <h1>Εισάγετε ένα Όνομα</h1>
    <form method="POST" action="kataxorisi.php">
        <label for="name">Name:</label>
        <input type="text" id="name" name="name" required>
        <br><br>
        <input type="submit" value="Καταχώριση">
    </form>
    <p><a href='diorthosi.php'>Διόρθωση</a></p>

    <footer>
        <h1>ΚΩΝΣΤΑΝΤΙΝΑ ΚΥΡΙΑΚΟΥ <br>iis23140@uom.edu.gr</h1>
    </footer>
</body>
</html>
