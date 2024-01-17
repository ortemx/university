<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link href="style.css" rel="stylesheet" type="text/css">
  <title>ИС агенства недвижимости</title>
</head>

<body>
  <div class="wrapper">

    <header class="header">Агенство недвижимости</header>
    <div class="container">
      <?php
      if ($_COOKIE['user'] == '') :
      ?>
        <div class="reg">
          <h1>Форма регистрации</h1>
          <form id="reg_form" action="register/register.php" method="POST" >
            <div>
            <input type="text" id="name" name="name" class="input_box" placeholder="Введите имя" required>
            </div>
            <input type="text" id="login" name="login" class="input_box" placeholder="Введите логин" required>
            <input type="password" id="password" name="pass" class="input_box" placeholder="Введите пароль" required>
            <input type="submit"  id="reg_btn" class="btn"  value="Зарегистрироваться">
            
          </form>
        </div>
        <div class="auth">
          <h1>Форма входа</h1>
          <form id="auth_form" action="auth/auth.php" method="POST">
            <input type="text" id="login" name="login" class="input_box" placeholder="Введите логин" required>
            <input type="password" id="password" name="pass" class="input_box" placeholder="Введите пароль" required>
            <input type="submit" id="login_btn" class="btn" value="Войти">
          </form>
        </div>
      <?php else : ?>
        <div class="container" id="main_user">
          <?php
          $data = json_decode($_COOKIE['user_info'], true);
          if (is_array($data) && isset($data['name'])) {
            $name = $data['name'];
            echo "Здравствуйте, " . $name . "!";
          }
          ?>
          <form action="auth/logout.php" method="POST">
            <input type="submit" value="Выход" class="btn" id="logout_btn">
          </form>
          <a href="search/search.php" id="search_ref">Поиск</a>
          <a href="add/add.php" id="add_ref"> Подать обьявление</a>
        </div>

      <?php endif; ?>
    </div>

  </div>
</body>

</html>