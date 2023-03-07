unit unit1;
interface implementation
var
  a, a_min, c:real
  i, n:integer; 
begin
  //readln(n);
  n := 10000;
  while (i <= n) do begin
    a := (i - 1) / (i + 1) + sin(exp(3 * ln(i - 1)) / (i + 1));
    c := a_min;
    if a > 0 then
      a_min := a;
    if (c > 0) and (c < a_min) then begin
      a_min := c;
    end;      
    i := i + 1;
  end;
  writeln (a_min);
end.
