program z_1;
var k:byte;
Begin
writeln('Введите возраст от 1 до 100');readln(k);
If (k<=14) and (k>11) Then writeln('мне',k,'лет')
Else
  Case k mod 10 of
    1:write('мне ',k,' год');
    2..4:write('мне ',k,' года');
  Else write('мне ',k,' лет');
  end;
end.