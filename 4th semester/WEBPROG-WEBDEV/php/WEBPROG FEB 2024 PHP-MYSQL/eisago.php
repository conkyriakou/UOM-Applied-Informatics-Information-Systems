<?php
// Database connection
$servername = "localhost";
$username = "root";  // replace with your MySQL username
$password = "";  // replace with your MySQL password
$dbname = "iis23140";  // replace with your database name

$conn = new mysqli($servername, $username, $password, $dbname);

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $email = $_POST["email"];

    // Email validation
    if (filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $stmt = $conn->prepare("INSERT INTO users (email) VALUES (?)");
        $stmt->bind_param("s", $email);

        if ($stmt->execute()) {
            // Count the affected rows
            $affectedRows = $conn->affected_rows;
            echo "<p>Πλήθος νέων εγγραφών: " . $affectedRows . "</p>";
        } else {
            echo "<p>ΟΔ - ΠΡΟΒΛΗΜΑ στην εισαγωγή δεδομένων</p>";
        }
        $stmt->close();
    } else {
        echo "<p>Invalid email format</p>";
    }
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Εισαγωγή</title>
    <style>
            footer{
                color: brown;
                font-size: large;
            }
    </style>
</head>
<body>
    <h1>Insert a Email</h1>
    <form method="POST" action="eisago.php">
        <label for="email">Email:</label>
        <input type="text" id="email" name="email" required>
        <br>
        <br>
        <input type="submit" value="Submit">
    </form>
    <p><a href='svino.php'>Διαγραφή Δεδομένων</a></p>

    <footer>
    <h1>KONSTANTINA KYRIAKOU <br>
    iis23140@uom.edu.gr</h1>
    </footer>
</body>
</html>