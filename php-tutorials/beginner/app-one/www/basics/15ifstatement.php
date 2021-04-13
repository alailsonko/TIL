<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php

$isMale = true;
$isTall = false;
if ($isMale && $isTall) {
    echo "You are a tall male";
} elseif($isMale && !$isTall) {
    echo "You are a short male";
} elseif(!$isMale && $isTall) {
    echo "You are a tall and not male";
} else {
    echo "You are female";
}

   function getMax($num1, $num2, $num3) {
       if ($num1 >= $num2 && $num1 >= $num3 ) {
           return $num1;
       }  elseif ($num1 < $num2 && $num3 < $num2) {
        return $num2;
       } elseif($num3 >= $num1 && $num3 >= $num2) {
           return $num3;
       }
           return "not valid";
   }

   echo "<br>";
   echo "<br>";

   echo getMax(5,10, 8);
?>
</body>
</html>