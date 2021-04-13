<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="6calculator.php" method="POST">
       <input type="number" name="num1">
       <br>
       <input type="number" name="num2">
       <br>
       <button type="submit" >SUBMIT</button>
    </form>

    Answer: <?php echo $_POST['num1'] + $_POST['num2']
    ?>
</body>
</html>