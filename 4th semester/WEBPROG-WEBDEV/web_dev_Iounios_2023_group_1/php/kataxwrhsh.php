<?php

echo "<!DOCTYPE html> 
<html> 
   <head> 
      <meta charset='utf-8'> 
      <title>KATAXWRHSH</title>
   </head>
<body>
  <form action='kataxwrhsh.php' method='post'>
     <label for='username'>Username:</label>
      <input type='text' id='username' name='username' required>
      <br><br>
      <input type='submit' value='Submit'>
  </form>
  <p><a href='diorthwsh.php'>diorthwsh</a></p>
</body>
</html>";

if ($_SERVER["REQUEST_METHOD"] == "POST"){
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

if ($_SERVER["REQUEST_METHOD"] == "POST"){
  $sql = "INSERT INTO iis23140 (name) values ('$nameFromuser')";
  if ($conn->query($sql) === TRUE) {
    $sql = "select id from iis23140";
    $result = $conn->query($sql);
    echo "<p>Total registries = $result->num_rows</p>";
  } 
  else {
    echo "Απέτυχε η εισαγωγή δεδομένων" . $conn->error;
  }
}

?>