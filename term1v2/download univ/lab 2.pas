
function z(i:integer; x:real): real;
begin
  if i = 256 then
    z := 256/(x*x)
  else
    z := x * x + i / (x * x + z(i*2, x))
end;

var x:real;
begin
  //write('x= ');
  //readln(x);
  write(5/+z(2,5));
  
end.