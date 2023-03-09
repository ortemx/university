var w,x,z:real;

begin
  x := 5;
  z := x * x;  
  for i:integer:=8 downto 1 do
  begin
    z := x * x + exp(i*ln(2)) / z;    
  end;
  writeln(x/z);
  w := x/(x*x +2/(x*x +4/(x*x+16/(x*x+32/(x*x+64/(x*x+128/(x*x+256/x*x)))))));
  writeln(w);
end.