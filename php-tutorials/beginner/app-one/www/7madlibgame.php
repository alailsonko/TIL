<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="7madlibgame.php" method="POST">
        
        <label for="">
        Color:
        <input 
         type="text"
         name="color"
         >   
        </label> <br>
        <label for="">
        Plural Noun:
        <input 
         type="text"
         name="pluralNoun"
         >   
        </label> <br>
        <label for="">
        Celebrity:
        <input 
         type="text"
         name="celebrity"
         >   
        </label> <br>
        <button type="submit" >SUBMIT</button>
    </form>
    <br> <br>
    <?php
        $color = $_POST["color"];
        $pluralNoun = $_POST["pluralNoun"];
        $celebrity = $_POST["celebrity"];
        echo "Roses are $color <br>";
        echo "$pluralNoun are blue <br>";
        echo "I love $celebrity <br>";
    ?>
</body>
</html>