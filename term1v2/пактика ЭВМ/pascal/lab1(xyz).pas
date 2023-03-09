var x, y, z, max, temp:real;

begin;

randomize;

x := random(10);
y := random(10);
z := random(10);
writeln(x, ' ', y, ' ', z, ' ');

write(' x = '); readln (x);
write(' y = '); readln (y);
write(' z = '); readln (z);
if x < y then
  begin
  temp := x;
  x := y;
  y := temp;  
  end;
  
if x < z then
  begin
    temp := x;
    x := z;
    z := y;
    y := temp;
  end
else if (z < x) and (z > y) then
  begin
    temp := y;
    y := z;
    z := temp;
  end;
 
writeln('now x = ',x, ' y = ', y, ' z = ', z);
end.