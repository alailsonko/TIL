<?php  

$mysql = new mysqli("127.0.0.1", "mysql", "", "crud", 3007);

if ($mysql->connect_error){
    exit("Error connecting to database.");
}