<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="9getorpost.php" method="get">
       <label for="">
          Password: <input 
          type="password" 
           name="password"
          >
          <button type="submit" >SUBMIT</button>
       </label> 
    </form>
    <br>
    <?php echo $_GET["password"] ?>
</body>
</html>