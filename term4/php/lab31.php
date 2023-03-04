<!DOCTYPE html>
<html>
<head>
    <title>Lab-3.1</title>
</head>
<body>
    <?php
    if (file_exists("rusvuzinfo.txt")) {
        if (is_readable("rusvuzinfo.txt")) {
            $file = file("rusvuzinfo.txt");
            echo "<table border = '2'><tr bgcolor = 'seablue'>";
            $temp = explode("\t", $file[0]);
            for ($i = 0; $i < count($temp); $i++) {
                echo "<th>" . $temp[$i] . "</th>";
            }
            echo "</tr>";
            for ($i = 1; $i < count($file); $i++) {
                echo "<tr>";
                $temp = explode("\t", $file[$i]);
                for ($j = 0; $j < count($temp); $j++) {
                    echo "<td>" . $temp[$j] . "</td>";
                }
                echo "</tr>";
            }
            echo "</table>";
        } else {
            die("Невозможно прочитать файл");
        }
    } else {
            die("Невозможно открыть файл");
    }
    ?>
</body>
</html>
