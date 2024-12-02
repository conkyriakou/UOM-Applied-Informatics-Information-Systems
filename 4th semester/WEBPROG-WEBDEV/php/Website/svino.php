<?php

echo "<!DOCTYPE html>
<html>
   <head>
      <meta charset='utf-8'>
      <title>SVINO</title>
   </head>
<body>
  <form action='svino.php' method='post'>
     <label for='id'>Id:</label>
      <input type='text' id='id' name='id' required>
      <br><br>
      <input type='submit' value='Submit'>
  </form>
  <p><a href='eisago.php'>Νέα Δεδόμενα</a></p>
</body>
</html>";

if ($_SERVER["REQUEST_METHOD"] == "POST"){
  $nameFromuser = $_POST['id'];
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
// sql to delete a record 
$sql = "DELETE FROM MyGuests WHERE id=3"; 
if ($conn->query($sql) === TRUE) { 
 echo "ΔΙΑΓΡΑΦΤΙΚΑΝ ΤΑ ΔΕΔΟΜΕΝΑ"; 
} else { 
 echo "Απέτυχε η διαγραφή δεδομένων" . $conn->error; 
} 
$conn->close(); 
?> 