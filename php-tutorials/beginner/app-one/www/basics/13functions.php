<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<form action="13functions.php" method="POST">
   <input type="text" name="name">
   <input type="number" name="age">
   <button type="submit">SUBMIT</button>
</form>
    <?php 
       function sayHi($name, $age){
           echo "hello $name <br>";
           echo "my age is $age <br>";
       }
       sayHi($_POST["name"], $_POST["age"]);
    ?>
</body>
</html>