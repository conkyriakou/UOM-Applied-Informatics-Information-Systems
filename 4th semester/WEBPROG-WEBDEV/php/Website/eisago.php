<?php

echo "<!DOCTYPE html>
<html>
   <head>
      <meta charset='utf-8'>
      <title>EISAGO</title>
   </head>
<body>
  <form action='eisago.php' method='post'>
     <label for='email'>Email:</label>
      <input type='text' id='email' name='email' required>
      <br><br>
      <input type='submit' value='Submit'>
  </form>
  <p><a href='svino.php'>Διαγραφή Δεδομένων</a></p>
</body>
</html>";

if ($_SERVER["REQUEST_METHOD"] == "POST"){
  $nameFromuser = $_POST['email'];
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
    echo "<p>Πλήθος καταχωρήσεων = $result->num_rows</p>";
  }
  else {
    echo "ΔΕΝ ΕΓΙΝΕ η εισαγωγή δεδομένων" . $conn->error;
  }
}

?>