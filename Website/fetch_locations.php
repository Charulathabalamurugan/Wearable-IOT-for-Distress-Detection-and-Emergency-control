<?php
// fetch_locations.php

// Include the database connection
include('db_connect.php');

// Fetch all locations from the database
$sql = "SELECT latitude, longitude, timestamp FROM locations ORDER BY timestamp DESC";
$result = $conn->query($sql);

// The `$result` variable will be used in `gps.php` to display the data

// Closing the connection is recommended here if no further database operations are needed
$conn->close();
?>
