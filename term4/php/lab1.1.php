<!DOCTYPE html>
<html>
<head>
    <title></title>
</head>
<body>
    <form method="POST">
        b<sub>1</sub>: <input type="text" name="b1"><br>
        q: <input type="text" name="q"><br>
        n: <input type="text" name="n"><br>
        <input type="submit" name="button1">
    </form>
    <?php
    if ($_POST['b1'] != '' && $_POST['q'] != '' && $_POST['n'] != '') {
        if (is_numeric($_POST['b1']) && is_numeric($_POST['q']) && is_numeric($_POST['n'])) {
            $b1 = $_POST['b1'];
            $q = $_POST['q'];
            $n = $_POST['n'];
            echo ($b1 * (1 - $q ** $n) / (1 - $q));
        } else {
            echo ('некорректные исходные данные');
        }
    }
    ?>
</body>
