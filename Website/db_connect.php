<?php
// db_connect.php

$servername = "localhost"; // Change this if you're not using localhost
$username = "root";        // Your MySQL username
$password = "";            // Your MySQL password
$dbname = "gps_data";      // Your database name

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>
