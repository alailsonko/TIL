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
$phrase = "Giraffe Academy";
echo strtoupper($phrase);
echo "<br>";
echo strlen($phrase);
echo "<br>";
echo $phrase[0];
echo "<br>";
echo "Alailson"[0];
echo "<br>";
$phrase[0] = "B";
echo $phrase;
echo "<br>";
echo str_replace("Biraffe", "Panda", $phrase);
echo "<br>";
echo substr($phrase, 5, 4);
?>
</body>
</html>