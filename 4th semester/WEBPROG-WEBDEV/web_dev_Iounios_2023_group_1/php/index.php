<?php

echo "<!DOCTYPE html> 
<html> 
   <head> 
      <meta charset='utf-8'> 
      <title>ARXIKH</title>
   </head>
<body>
  <p><a href='kataxwrhsh.php'>kataxwrhsh</a></p>
  <p><a href='diorthwsh.php'>diorthwsh</a></p>
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

  $sql = "CREATE TABLE ics24060 (
    id INT AUTO_INCREMENT PRIMARY KEY, 
    name VARCHAR(255)
  ) AUTO_INCREMENT=0";

  if ($conn->query($sql) === TRUE) {
    echo "Table created successfully";
    } else {
    echo "Δεν δημιουργήθηκε ο πίνακας" . $conn->error;
    }

  $conn->close();
?>
