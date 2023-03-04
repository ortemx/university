<!DOCTYPE html>
<html>
<head>
    <title></title>
</head>
<body>
    <form method="POST">
        R: <input type="text" name="r"><br>
        a: <input type="text" name="a"><br>
        <input type="submit" name="button1">
    </form>
    <?php
    if ($_POST['r'] != '' && $_POST['a'] != '') {
        if (is_numeric($_POST['r']) && is_numeric($_POST['a'])) {
            $radius = $_POST['r'];
            $a = $_POST['a'];
            if ($radius > $a / sqrt(3)) {
                echo ('поместится');
            } else {
                echo ('не поместится');
            }
        } else {
            echo ('некорректные исходные данные');
        }
    }
    ?>
</body>
