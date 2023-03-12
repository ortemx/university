<?php

namespace App;

require("StackInterface.php");

class Stack implements StackInterface
{
    private array $stack = [];

    public function __construct(mixed ...$elements)
    {
        $this->push(...$elements);
    }

    public function push(mixed ...$elements): void
    {
        foreach ($elements as $elem) {
            $this->stack[] = $elem;
        }
    }

    public function pop(): mixed
    {
        return array_pop($this->stack);
    }

    public function top(): mixed
    {
        $lastIndex = count($this->stack) - 1;
        if ($lastIndex < 0) {
            return null;
        } else {
            return $this->stack[$lastIndex];
        }
    }

    public function isEmpty(): bool
    {
        return count($this->stack) === 0;
    }

    public function copy(): Stack
    {
        return new Stack(...$this->stack);
    }

    public function __toString(): string
    {
        $string = "[";
        for ($i = count($this->stack) - 1; $i >= 1; $i--) {
            $string .= $this->stack[$i] . "->";
        }

        return $string . (isset($this->stack[0]) ? $this->stack[0] : "") . "]";
    }
}

function checkIfBalanced(string $expression): bool
{
    $openParenthesises = ["(", "{", "[", "<"];
    $closingParenthesises = [")", "}", "]", ">"];
    $Parenthesises = [
        ")" => "(",
        "}" => "{",
        "]" => "[",
        ">" => "<"
    ];

    $stack = new Stack();

    for ($i = 0; $i < strlen($expression); $i++) {
        if (in_array($expression[$i], $openParenthesises)) {
            $stack->push($expression[$i]);
        } elseif (in_array($expression[$i], $closingParenthesises)) {
            if ($Parenthesises[$expression[$i]] === $stack->top()) {
                $stack->pop();
            } else {
                return false;
            }
        }
    }

    return $stack->isEmpty();
}

$stack = new Stack(1, "1aaa");

print $stack;
