<html>
    <head>
        <meta charset="UTF-8">
        <link href="../style.css" rel="stylesheet" type="text/css">
        <link href="https://fonts.googleapis.com/css?family=Montserrat" rel="stylesheet">
        <title>Подача объявления</title>     
    </head>
    <body>
        <?php
        echo<<<HTML
        <div class="wrapper" id="add_wrapper">
            <header id='header_add'>Подача объявления</header>
            <form action="submit.php" method="POST" class="form" id="form_add">
                <span class="info">Тип объявления</span>
                <SELECT id="adtype" NAME="adtype" class="selector">
                    <option value="rent">Аренда</option>
                    <option value="sale">Продажа</option>
                </SELECT>
                <span class="info">Адрес</span>
                <input type="text" id="adress" name="adress">
                <span class="info">Цена</span>
                <input type="number" id="price" name="price">
                <span class="info">Описание</span>
                <input type="text" id="description" name="description">
                <div>
                <input type="submit" name="return" class= 'btn' id="return_from_add" value="Назад">
                <input type="submit" name="submit" class= 'btn' id="submit_add" value="Подтвердить">
                </div>
            </form>
        </div>
HTML;
        ?>
    </body>
</html>