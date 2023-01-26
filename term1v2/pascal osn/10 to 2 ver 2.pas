var x, i, j, temp: integer;
begin
  
  write('N(10) = ');
  
  //readln();
  x := 0;
  writeln(x);
  write('N(2) = ');

  
  j := Round(ln(x+1)/ln(2)) + 1;
  
  temp := x;
  for i:= 0 to j - 2 do      
    temp := temp div 2;
  if (temp <> 0) then
    write(temp);
  j := j - 1; 
  
  repeat
    temp := x;
    for i:= 0 to j - 2 do      
      temp := temp div 2;
    if (temp mod 2 = 1) then
      write(1)
    else
      write(0);
    j := j - 1;
  until (j <= 0);
end.