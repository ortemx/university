var x2, y2, z2, temp:integer;

begin
  randomize();
  x2 := random(100);
  y2 := random(100);
  z2 := random(100);
  writeln(x2, ' ', y2, ' ', z2);
  if (x2 < y2) then
  begin
    temp := x2;
    x2 := y2;
    y2 := temp;
  end;
  
  if (x2 < z2) then 
  begin
    temp := x2;
    x2 := z2;
    z2 := y2;
    y2 := temp;
  end
  
  else if (y2 < z2) and (z2 < x2) then
  begin
    temp := y2;
    y2 := z2;
    z2 := temp;
  end;
    
  writeln(x2, ' ', y2, ' ', z2);
  
end.