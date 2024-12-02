<?php
// Database connection
$servername = "localhost";
$username = "root";  // replace with your MySQL username
$password = "";  // replace with your MySQL password
$dbname = "iis23140";  // replace with your database name

$conn = new mysqli($servername, $username, $password, $dbname);

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST["name"];
    $email = $_POST["email"];

    // Email validation
    if (filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $stmt = $conn->prepare("INSERT INTO users (name, email) VALUES (?, ?)");
        $stmt->bind_param("ss", $name, $email);

        if ($stmt->execute()) {
            echo "<p>Πλήθος νέων εγγραφών: x</p>";
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
    <h1>Insert a New Name and Email</h1>
    <form method="POST" action="eisago.php">
        <label for="name">Name:</label>
        <input type="text" id="name" name="name" required>
        <br> <br>
        <label for="email">Email:</label>
        <input type="text" id="email" name="email" required>
        <br>
        <br>
        <input type="submit" value="Submit">
    </form>
    <p><a href='emfanizo.php'>Εμφανίζω</a></p>

    <footer>
    <h1>KONSTANTINA KYRIAKOU <br>
    iis23140@uom.edu.gr</h1>
    </footer>
</body>
</html>
