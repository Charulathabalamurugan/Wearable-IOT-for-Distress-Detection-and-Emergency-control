<?php
// Database credentials
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "gps_data";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Fetch all locations from the database
$sql = "SELECT latitude, longitude, timestamp FROM locations ORDER BY timestamp DESC";
$result = $conn->query($sql);

// Check if there are any results
if ($result->num_rows > 0) {
    // Output the data of each row
    while($row = $result->fetch_assoc()) {
        echo "Latitude: " . $row["latitude"] . " - Longitude: " . $row["longitude"] . " - Timestamp: " . $row["timestamp"] . "<br>";
    }
} else {
    echo "No locations found!";
}

$conn->close();
?>
