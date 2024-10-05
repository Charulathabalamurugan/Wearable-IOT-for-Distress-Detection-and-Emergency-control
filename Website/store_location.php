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

// Get the latitude and longitude from the URL
if (isset($_GET['latlng'])) {
    // Split the latlng string into latitude and longitude
    list($latitude, $longitude) = explode(",", $_GET['latlng']);

    // Prepare and bind the SQL statement
    $stmt = $conn->prepare("INSERT INTO locations (latitude, longitude) VALUES (?, ?)");
    $stmt->bind_param("dd", $latitude, $longitude);

    // Execute the statement
    if ($stmt->execute()) {
        echo "Location stored successfully!";
    } else {
        echo "Error: " . $stmt->error;
    }

    // Close the statement and connection
    $stmt->close();
} else {
    echo "No location data received!";
}

$conn->close();
?>
