<?php

class MyClass
{
    private static int $num = 1;
    public static string $name = "name";
    public function __toString()
    {
        return (string)self::$num . self::$name;
    }
}

$class = new MyClass();

printf("%s\n", $class);

// Fatal error
// MyClass::$num = 1;
MyClass::$name = "mane";

printf("%s\n", $class);
