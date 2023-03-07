program lab3;
var 
  a,c,k:real;
  i,n:integer;
begin
  readln(n);
  for i:=1 to n do
  begin
    a := (i - 1) / (i + 1) + sin((i - 1) * (i - 1) * (i - 1) / (i + 1));
    c := k;
    if a > 0 then 
      k := a;
    if (k > 0) and (c > 0) and (c < k) then
      k := c;
    writeln(a);
  end; 
  writeln ('min =', k:10); 
end.


