<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="5userinputs.php" method="POST">
       <label for="">
       Name:
       <input
       type="text"
       name="name"
         />
       </label>
    <br>
       <label for="">
       Age:
       <input
       type="number"
       name="age"
         />
       </label>
      <button type="submit" >SUBMIT</button>
    </form>
    <br>
    Your name is <?php echo $_POST['name']; ?>
    <br>
    Your name is <?php echo $_POST['age']; ?>
</body>
</html>