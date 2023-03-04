<!DOCTYPE html>
<html>
<head>
    <title>Lab-3.2</title>
</head>
<body>
    <?php

    function show_form()
    {
        echo <<< END
			<form action = "$_SERVER[PHP_SELF]" method = "post" enctype = "multipart/form-data">
			Файл: <input type = "file" name = "file" accept = "text/plain">
			<br> Разделитель: <input type = "text" name = "separator">
			<br> <input type="submit" name="sumbit"/>
END;
    }

    if (!(empty($_FILES))) {
        $file_path = $_FILES['file']['tmp_name'];
        if (file_exists($file_path) && !empty($_POST['separator'])) {
            if (isset($_POST['sumbit'])) {
                show_form();
                $file = file($file_path);
                $separator = str_replace(
                    array('\t', '\n'),
                    array("\t", "\n"),
                    $_POST['separator']
                );
                echo "<table border = '2'><tr bgcolor = 'seablue'>";
                $temp0 = explode($separator, $file[0]);
                for ($i = 0; $i < count($temp0); $i++) {
                    echo "<th>" . $temp0[$i] . "</th>";
                }
                for ($i = 1; $i < count($file); $i++) {
                    echo "<tr>";
                    $temp = explode($separator, $file[$i]);
                    for ($j = 0; $j < count($temp0); $j++) {
                        if (array_key_exists($j, $temp)) {
                            echo "<td>" . $temp[$j] . "</td>";
                        } else {
                            echo "<td></td>";
                        }
                    }
                    echo "</tr>";
                }
                echo "</table>";
            } else {
                show_form();
            }
        } else {
            show_form();
            echo "<br>Разделитель не указан или файла с таким именем не существует";
        }
    } else {
        show_form();
    }
    ?>
</body>
</html>
