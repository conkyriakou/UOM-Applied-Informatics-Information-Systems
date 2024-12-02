<?php

echo "<!DOCTYPE html>
<html>
   <head>
      <meta charset='utf-8'>
      <title>ARXIKH</title>
   </head>
<body>
<h1>KONSTANTINA KYRIAKOU</h1>
<h1>iis23140@uom.edu.gr</h1>
  <p><a href='eisago.php'>Νέα Δεδόμενα</a></p>
  <p><a href='svino.php'>Διαγραφή Δεδομένων</a></p>
</body>
</html>";


  $servername = "localhost";
  $username = "user1";
  $password = "";
  $dbname = "test";

  $conn = new mysqli($servername, $username, $password, $dbname);
  // Check connection
  if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
  }

  $sql = "CREATE TABLE iis23140 (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255)
  ) AUTO_INCREMENT=0";

  if ($conn->query($sql) === TRUE) {
    echo "Table created successfully";
    } else {
    echo "ΟΧΙ δημιουργία πίνακα" . $conn->error;
    }

  $conn->close();
?>