<?php

$pass = "123456";
$pass_hash = password_hash($pass, PASSWORD_DEFAULT);

echo "pass: " . $pass . "<br>pass_hash: " . $pass_hash . "<br>";

$pass2 = "123456";
$pass_hash2 = password_hash($pass2, PASSWORD_DEFAULT);

echo "pass2: " . $pass2 . "<br>pass_hash2: " . $pass_hash2 . "<br>";

if (password_verify($pass2, $pass_hash)) {
    echo "Верный пароль";
} else {
    echo "Неверный пароль";
}