<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="17switchcase.php" method="POST">
      <label for="">Grade: <input type="text" name="grade" id=""></label>
    
    <button type="submit" >SUBMIT</button>
    </form>
   <?php
   $grade = $_POST["grade"];
   switch($grade){
       case "A":
       echo "YOU did amazing";
       break;
       case "B":
       echo "YOU did pretty good";
       break;
   }
    ?>
</body>
</html>