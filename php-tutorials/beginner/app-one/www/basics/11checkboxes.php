<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<form action="11checkboxes.php" method="POST">
    <label for="">
    Apples: <input
    type="checkbox"
    name="fruits[]"
    value="apples"
    >
    </label>
 <br>
 <label for="">
    Oranges: <input
    type="checkbox"
    name="fruits[]"
    value="oranges"
    >
    </label>
 <br>
 <label for="">
    Pears: <input
    type="checkbox"
    name="fruits[]"
    value="pears"
    >
    </label>
 <br>
     <button type="submit" >SUBMIT</button>
</form>
    <?php
      $fruits = $_POST["fruits"];
      echo $fruits[0];
?>
</body>
</html>