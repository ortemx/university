<?php

namespace gamma;

class Gamma
{
    private string $gamma = "";

    public function __construct(string $string, int $length = 10)
    {
        function chrbin(string $char): string
        {
            return sprintf("%08s\n", decbin(ord($char)));
        }

        function printReg($register): void
        {
            for ($j = 0; $j < count($register); $j++) {
                printf("%d", $register[$j]);
            }

            printf("\n");
        }

        function getRegister($string): array
        {
            $string = iconv('utf-8', 'windows-1251', $string);

            $register = [0, 0, 0, 0, 0, 0, 0, 0];
            for ($i = 0; $i < strlen($string); $i++) {
                $chrbin = chrbin($string[$i]);
                // printf("symbol: %s; bin: %s", $string[$i], $chrbin);

                for ($j = 0; $j < count($register); $j++) {
                    $register[$j] ^= (int)($chrbin[$j]);
                }

                // printReg($register);
            }

            return $register;
        }

        $register = getRegister($string);

        // printf("register = ");
        // printReg($register);

        $iter = 0;

        while ($iter <= $length) {
            $b_0 = $register[7];
            $b_7 = $register[3] ^ $register[4] ^ $register[5] ^ $register[7];

            $this->gamma .= (string) ($b_0);

            $register = array_merge(array($b_7), array_slice($register, 0, 7));
            $iter = $iter + 1;
        }
    }

    public function __toString()
    {
        return $this->gamma;
    }
}
