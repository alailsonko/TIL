<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="12associativearray.php" method="POST">
       <input type="text" name="student">
       <button type="submit" >SUBMIT</button>
    </form>
    <?php 
    //  echo "hello";
    $grades = array(
        "Jim" => "A+", 
        "Pam" => "B-",
        "Oscar" => "C+"
    );
   echo $grades[$_POST["student"]]
    ?>
</body>
</html>