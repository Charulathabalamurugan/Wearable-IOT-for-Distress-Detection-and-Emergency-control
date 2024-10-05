<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>GPS Locations - GPS Tracker</title>
    <link rel="stylesheet" href="styles.css">
    <style>
        /* Table styling */
        table {
            width: 100%;
            border-collapse: collapse;
            margin: 20px 0;
        }
        table, th, td {
            border: 1px solid #ddd;
        }
        th, td {
            padding: 12px;
            text-align: center;
        }
        th {
            background-color: #f2a3c2;
            color: white;
        }
        tr:nth-child(even) {
            background-color: #f9f9f9;
        }
        tr:hover {
            background-color: #f1f1f1;
        }
    </style>
</head>
<body>

    <!-- Navigation Bar -->
    <nav class="navbar">
        <div class="container">
            <h1 class="logo">GPS Tracker</h1>
            <ul class="nav-links">
                <li><a href="index.html">Home</a></li>
                <li><a href="gps.php">View GPS Locations</a></li>
                <li><a href="about.html">About Us</a></li>
            </ul>
        </div>
    </nav>

    <!-- GPS Locations Section -->
    <section class="content-section active">
        <div class="container">
            <h2>Recent GPS Locations</h2>
            <div id="gps-data">
                <!-- Include the data retrieval logic -->
                <?php
                include('fetch_locations.php');

                // Check if we have results and display them in a table
                if ($result->num_rows > 0) {
                    echo '<table>';
                    echo '<thead><tr><th>Latitude</th><th>Longitude</th><th>Timestamp</th></tr></thead>';
                    echo '<tbody>';
                    
                    // Loop through and display each row in the table
                    while ($row = $result->fetch_assoc()) {
                        echo "<tr>
                                <td>{$row['latitude']}</td>
                                <td>{$row['longitude']}</td>
                                <td>{$row['timestamp']}</td>
                              </tr>";
                    }
                    echo '</tbody>';
                    echo '</table>';
                } else {
                    echo '<p>No GPS locations found!</p>';
                }
                ?>
            </div>
        </div>
    </section>

</body>
</html>
