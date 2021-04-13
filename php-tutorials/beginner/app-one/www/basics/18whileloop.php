<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="18whileloop.php" method="POST">
    
    <button type="submit" >SUBMIT</button>
    </form>
     <?php
        $index = 1;
        while($index <= 100) {
           echo $index;
           echo "<br>";
           $index++;
        }
    ?>
</body>
</html>