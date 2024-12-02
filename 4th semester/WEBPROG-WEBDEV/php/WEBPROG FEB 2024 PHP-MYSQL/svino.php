<?php
// Database connection
$host = 'localhost';
$user = 'root';
$password = '';
$dbname = 'iis23140';

$conn = new mysqli($host, $user, $password, $dbname);

if ($conn->connect_error) {
    die('Connection failed: ' . $conn->connect_error);
}

// Delete record
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $id = $_POST['id'];

    // Prepare the statement to prevent SQL injection
    $stmt = $conn->prepare("DELETE FROM iis23140 WHERE id =  ( ?)");
    $stmt->bind_param("i", $id);

    if ($stmt->execute()) {
        if ($stmt->affected_rows > 0) {
            echo "Διαγράφηκαν " . $stmt->affected_rows . " εγγραφές.";
        } else {
            echo "Δεν βρέθηκε καμία εγγραφή με το συγκεκριμένο ID.";
        }
    } else {
        echo "Απέτυχε η διαγραφή δεδομένων: " . $conn->error;
    }

    $stmt->close();
}

// Close connection
$conn->close();
?>

<!DOCTYPE html>
<html lang="el">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Διαγραφή Δεδομένων</title>
    <style>
        footer {
            color: brown;
            font-size: large;
        }
    </style>
</head>
<body>
    <h1>Εισάγετε ID για διαγραφή</h1>
    <form method="POST" action="svino.php">
        <label for="id">ID:</label>
        <input type="text" id="id" name="id" required>
        <br><br>
        <input type="submit" value="Υποβολή">
    </form>
    <p><a href='eisago.php'>Νέα Δεδομένα</a></p>

    <footer>
        <h1>KONSTANTINA KYRIAKOU <br>
        iis23140@uom.edu.gr</h1>
    </footer>
</body>
</html>
