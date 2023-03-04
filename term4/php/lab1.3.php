<!DOCTYPE html>
<html>
<head>
    <title></title>
</head>
<body>
    <form method="POST">
        n: <input type="text" name="n"><br>
 
        <input type="submit" name="button1">
    </form>
    <?php
    if ($_POST['n'] != '' && is_numeric($_POST['n'])) {
        $str = (string)(int)$_POST['n'];
        echo $str[0] + $str[Strlen($str) - 1];
    } else {
        echo ('некорректные исходные данные');
    }
    ?>
</body>
