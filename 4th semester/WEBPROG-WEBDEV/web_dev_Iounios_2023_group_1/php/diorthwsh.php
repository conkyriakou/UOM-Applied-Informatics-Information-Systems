<?php

echo "<!DOCTYPE html> 
<html> 
   <head> 
      <meta charset='utf-8'> 
      <title>DIORTHWSH</title>
   </head>
<body>
  <form action='diorthwsh.php' method='post'>
    <label for='id'>Id:</label>
      <input type='text' id='id' name='id' required>
      <br><br>
     <label for='username'>Username:</label>
      <input type='text' id='username' name='username' required>
      <br><br>
      <input type='submit' value='Submit'>
  </form>
  <p><a href='kataxwrhsh.php'>kataxwrhsh</a></p>
</body>
</html>";

if ($_SERVER["REQUEST_METHOD"] === "POST"){
  $idFromuser = $_POST['id'];
  $nameFromuser = $_POST['username'];
}

$servername = "localhost";
$username = "user1";
$password = "";
$dbname = "test";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if($_SERVER["REQUEST_METHOD"] === "POST"){
  $sql = "UPDATE ics24060 SET name='$nameFromuser' WHERE id='$idFromuser'";
  if ($conn->query($sql) === TRUE) {
    echo "Πλήθος εγγραφών που τροποοίηθηκαν =  ?";
  } 
  else {
    echo "Απέτυχε η τροποποίηση δεδομένων" . $conn->error;
  }
}
?>