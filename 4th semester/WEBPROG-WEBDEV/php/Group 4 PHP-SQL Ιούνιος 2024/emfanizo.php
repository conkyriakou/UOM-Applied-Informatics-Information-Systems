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

$sql = "SELECT name, email FROM users";
$result = $conn->query($sql);

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Name List</title>
</head>
    <style>
            footer{
                color: brown;
                font-size: large;
            }
    </style>
<body>
    <h1>Names in Database</h1>

    <?php
    if ($result->num_rows > 0) {
        echo "<ul>";
        while($row = $result->fetch_assoc()) {
            echo "<li>" . $row["name"] .  "</li>";
        }
        echo "</ul>";
    } else {
        echo "<p>Δεν υπάρχουν εγγραφές στον πίνακα</p>";
    }
    $conn->close();
    ?>
  <p><a href='eisago.php'>Εισαγωγή</a></p>

<footer>
<h1>KONSTANTINA KYRIAKOU <br>
iis23140@uom.edu.gr</h1>
</footer>
</body>
</html>
