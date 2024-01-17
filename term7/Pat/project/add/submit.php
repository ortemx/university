<?php

if (isset($_POST['return'])) {
    header('Location: ../index.php');
}

if (isset($_POST['submit'])) {
    $owner = $_COOKIE['login'];
    $adtype = filter_var(trim($_POST['adtype']));
    $adress = filter_var(trim($_POST['adress']));
    $price = filter_var(trim($_POST['price']));
    $description = filter_var(trim($_POST['description']));

    if ($adress == '') {
        die("Вы не ввели адрес");
    }

    if ($price == '') {
        die("Вы не ввели цену");
    }
    
    $dbHost = 'localhost';
    $dbUsername = 'root';
    $dbPassword = '';
    $dbName = 'patterns_project';

    $conn = new mysqli($dbHost, $dbUsername, $dbPassword, $dbName);

    if ($conn->connect_error) {
        die("Ошибка подключения к базе данных: " . $conn->connect_error);
    }

    $sql = <<<SQL
    INSERT INTO `ads` (`owner`, `type`, `adress`, `price`, `description`)
    VALUES ('$owner', '$adtype', '$adress', '$price', '$description')
SQL;
    if ($conn->query($sql))
    {
        header('Location: ../index.php');
    } else {
        echo "Ошибка: " . $conn->error;
    }

}