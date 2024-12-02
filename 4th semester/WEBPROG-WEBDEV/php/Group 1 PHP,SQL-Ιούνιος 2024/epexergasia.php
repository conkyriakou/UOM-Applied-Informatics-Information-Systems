<!DOCTYPE html>
<html lang="el">
<head>
    <meta charset="UTF-8">
    <title>Επεξεργασία</title>
</head>
<style>
    footer{
        color: orange;
        font-size: larger;
    }
</style>
<body>
    <h1>ΕΙΣΑΓΩΓΗ και ΤΡΟΠΟΠΟΙΗΣΗ</h1>
    <form action="epexergasia.php" method="POST">
        <label for="email">Email:</label>
        <input type="email" id="email" name="email" required>
        <br><br>
        <input type="submit" name="insert" value="Εισαγωγή">
        <input type="submit" name="update" value="Τροποποίηση">
    </form>

    <?php
    $servername = "localhost";
    $username = "root";
    $password = ""; // Add your database password here
    $dbname = "iis23140";
    $tableName = "iis23140"; // Replace with your table name

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    if (isset($_POST['insert'])) {
        $email = $_POST['email'];
        $stmt = $conn->prepare("INSERT INTO $tableName (email) VALUES (?)");
        $stmt->bind_param("s", $email);

        if ($stmt->execute()) {
            echo "Πλήθος νέων εισαγωγών: 1 - Η εισαγωγή δεδομένων ΕΠΙΤΥΧΗΣ.";
        } else {
            echo "ΦΦΦ - Η εισαγωγή δεδομένων ΑΠΕΤΥΧΕ: " . $stmt->error;
        }
        $stmt->close();
    }

    if (isset($_POST['update'])) {
        $email = $_POST['email'];
        $stmt = $conn->prepare("UPDATE $tableName SET email=? WHERE id=1"); // Adjust this condition based on your specific requirement
        $stmt->bind_param("s", $email);

        if ($stmt->execute()) {
            echo "ΩΩΩ - Η τροποποίηση δεδομένων ΕΠΙΤΥΧΗΣ.";
        } else {
            echo "ΩΩΩ - Η τροποποίηση δεδομένων ΑΠΕΤΥΧΕ: " . $stmt->error;
        }
        $stmt->close();
    }

    $conn->close();
    ?>
</body>
<footer><br>ΚΩΝΣΤΑΝΤΙΝΑ ΚΥΡΙΑΚΟΥ <br> iis23140@uom.edu.gr</footer>

</html>
