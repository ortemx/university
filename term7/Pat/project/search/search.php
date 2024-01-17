<html>
    <head>
        <meta charset="UTF-8">
        <link href="../style.css" rel="stylesheet" type="text/css">
        <link href="https://fonts.googleapis.com/css?family=Montserrat" rel="stylesheet">
        <title>Поиск недвижимости</title>     
    </head>
    <body>
        <?php
        if($_COOKIE['user'] == '') {
            echo "Вы не авторизованы";
            exit();
        }

        $adress = $_GET['adress'];
        $minprice = $_GET['minprice'];
        $maxprice = $_GET['maxprice'];
        $selected = $_GET['adtype'] == "sale" ? ["", "selected"] : ["selected", ""];
        echo<<<HTML
        <div class="wrapper" id="search_wrapper">          
            <header id='header_search'>Поиск недвижимости</header>  
            <form action="" method="GET" class="form" id="form_search">

            <div>    
            <span class="info">Тип объявления</span>
                <SELECT id="adtype" NAME="adtype" class="selector">
                    <option value="rent" $selected[0]>Аренда</option>
                    <option value="sale" $selected[1]>Продажа</option>
                </SELECT>
            </div>
            <div>                
                <span class="info">Адрес</span>
                <input type="text" id="adress" name="adress" value="$adress">
            </div>
            <div>
                <span class="info">Цена</span>
                от<input type="number" id="minprice" name="minprice" value="$minprice">
                до<input type="number" id="maxprice" name="maxprice" value="$maxprice">
            </div>
            <div>
                <a href="../index.php" id="return_from_search">ВЕРНУТЬСЯ</a>
                <input type="submit" name="submit" class= 'btn submit' id="submit_search" value="Найти">
            </div>

            </form>
        
HTML;
        if (isset($_GET['submit'])) {
            require_once "../View/View.php";
            $adtype = filter_var(trim($_GET['adtype']));
            $adress = filter_var(trim($_GET['adress']));
            $minprice = filter_var(trim($_GET['minprice']));
            $maxprice = filter_var(trim($_GET['maxprice']));

            $dbHost = 'localhost';
            $dbUsername = 'root';
            $dbPassword = '';
            $dbName = 'patterns_project';

            $conn = new mysqli($dbHost, $dbUsername, $dbPassword, $dbName);
            
            if ($conn->connect_error) {
                die("Connection failed: " . $conn->connect_error);
            }

            $sql =
            "SELECT * from `ads` WHERE type = '$adtype'";
            if($adress != '') {
                $sql .= " AND adress = '$adress'";
            }
            if($minprice != '') {
                $sql .= " AND price >= '$minprice'";
            }
            if($maxprice != '') {
                $sql .= " AND price <= '$maxprice'";
            }
            $result = $conn->query($sql);
            $ads = $result->fetch_all(MYSQLI_ASSOC);

            if(count($ads) == 0) {
                echo "Ничего не найдено по заданным параметрам";
            }
            $view = new View();
            foreach ($ads as $ad) {
                $view->show_ad($ad);
            }
        }
        ?>
        </div>
    </body>
</html>