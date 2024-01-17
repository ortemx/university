<?php

class View
{
    public static function show_ad($ad)
    {
        $owner = $ad['owner'];
        $types = ["rent" => "Аренда", "sale" => "Продажа"];
        $type = $ad['type'];
        $adress = $ad['adress'];
        $price = $ad['price'];
        $description = $ad['description'];
        echo<<<HTML
        <div class="ad">
            <span class="info">Владелец: $owner</span>
            <span class="info">Тип: $types[$type]</span>
            <span class="info">Адрес: $adress</span>
            <span class="info">Цена: $price</span>
            <span class="info">Описание: $description</span>
        </div>
        <br>
HTML;
    }
}
