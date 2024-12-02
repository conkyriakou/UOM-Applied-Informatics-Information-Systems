<?php
// Database connection
$servername = "localhost";
$username = "root";  // replace with your MySQL username
$password = "";  // replace with your MySQL password
$dbname = "iis23140";  // replace with your database name

$conn = new mysqli($servername, $username, $password, $dbname);

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $id = $_POST["id"];
    $name = $_POST["name"];

    // ID and Name validation
    if (!empty($id) && !empty($name) && preg_match("/^[a-zA-Z\\s]+$/", $name)) {
        $stmt = $conn->prepare("UPDATE iis23123 SET name = ? WHERE id = ?");
        $stmt->bind_param("si", $name, $id);

        if ($stmt->execute()) {
            echo "<p>Επιτυχής τροποποίηση δεδομένων. Πλήθος εγγραφών που τροποποιήθηκαν: " . $stmt->affected_rows . "</p>";
        } else {
            echo "<p>Απέτυχε η τροποποίηση δεδομένων</p>";
        }
        $stmt->close();
    } else {
        echo "<p>Invalid ID or Name format</p>";
    }
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="el">
<head>
    <meta charset="UTF-8">
    <title>Διόρθωση</title>
</head>
<style>
  footer{
    color: red;
  }
</style>
<body>
    <h1>Διορθώστε ένα Όνομα</h1>
    <form method="POST" action="diorthosi.php">
        <label for="id">ID:</label>
        <input type="text" id="id" name="id" required>
        <br><br>
        <label for="name">Νέο Όνομα:</label>
        <input type="text" id="name" name="name" required>
        <br><br>
        <input type="submit" value="Τροποποίηση">
    </form>
    <p><a href='kataxorisi.php'>Καταχώριση</a></p>

    <footer>
        <h1>ΚΩΝΣΤΑΝΤΙΝΑ ΚΥΡΙΑΚΟΥ <br>iis23140@uom.edu.gr</h1>
    </footer>
</body>
</html>
