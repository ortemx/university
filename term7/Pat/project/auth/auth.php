<?php

$login = filter_var((trim($_POST['login'])));
$password = filter_var((trim($_POST['pass'])));

$dbHost = 'localhost';
$dbUsername = 'root';
$dbPassword = '';
$dbName = 'patterns_project';

$conn = @new mysqli($dbHost, $dbUsername, $dbPassword, $dbName);
if ($conn->connect_error) {
    die("Ошибка подключения к базе данных: " . $conn->connect_error);
}

$sql = <<<SQL
SELECT * FROM `users` WHERE `login` = '$login'
SQL;

$result = $conn->query($sql);

$user = $result->fetch_assoc();

if (@count($user) == 0) {
    echo "Пользователь не найден";
    exit();
} else {
    if (password_verify($password, $user['pass'])) {
        echo "Верный пароль";
        setcookie('user', $user['name'], time() + 3600 * 24 * 30, "/");
        setcookie('login', $user['login'], time() + 3600 * 24 * 30, "/");
        $user_info = ["name" => $user['name'], "login" => $user['login']];
        setcookie('user_info', json_encode($user_info), time() + 3600 * 24 * 30, "/");
        header("Location: ../index.php");
    } else {
        echo "Неверный пароль";
    }
}


