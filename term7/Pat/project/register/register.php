<?php

$username = filter_var((trim($_POST['name'])));
$login = filter_var((trim($_POST['login'])));
$password = filter_var((trim($_POST['pass'])));

if (mb_strlen($username) < 5 || mb_strlen($username) > 15) {
    echo "Имя пользователя должно содержать от 5 до 15 символов";
    exit();
}

if (mb_strlen($login) < 5 || mb_strlen($login) > 15) {
    echo "Логин должен содержать от 5 до 15 символов";
    exit();
}

if (mb_strlen($password) < 5) {
    echo "Пароль должен содержать от 5";
    exit();
}


$dbHost = 'localhost';
$dbUsername = 'root';
$dbPassword = '';
$dbName = 'patterns_project';

$conn = new mysqli($dbHost, $dbUsername, $dbPassword, $dbName);
if ($conn->connect_error) {
    die("Ошибка подключения к базе данных: " . $conn->connect_error);
}

$conn->query("SELECT * FROM `users` WHERE `login` = '$login'");

if ($conn->affected_rows > 0) {
    echo "Пользователь с таким логином уже существует";
    exit();
}

$password = password_hash($password, PASSWORD_DEFAULT);
$sql = <<<SQL
INSERT INTO `users` (`name`, `login`, `pass`)
VALUES ('$username', '$login', '$password')
SQL;
$conn->query($sql);

header("Location: ../index.php");
