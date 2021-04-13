<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="16bettercalculation.php" method="POST">
      <label for="">First Num: <input type="number" name="num1" id=""></label>
      <label for="">OP: <input type="textbox" name="op" id=""></label>
      <label for="">Second Num: <input type="number" name="num2" id=""></label>
    
    <button type="submit" >SUBMIT</button>
    </form>
    <?php 
       $num1 = $_POST['num1'];
       $num2 = $_POST['num2'];
       $op = $_POST['op'];
       if ( $op == "+") {
          echo $num1 + $num2;
       } elseif ($op == "-") {
        echo $num1 - $num2;

       } elseif ($op == "/") {
        echo $num1 / $num2;

       }elseif ($op == "*") {
        echo $num1 * $num2;
       
    } else {
     echo "Invalid operator";
       }
    ?>
</body>
</html>