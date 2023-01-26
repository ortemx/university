var x, i, j, temp: integer;
begin
  x := 0; 
  //readln(x);
  j := Round(ln(x)/ln(2)) + 1;
  repeat
    temp := x;
    for i:= 0 to j - 2 do      
      temp := temp div 2;
    if (temp mod 2 = 1) then
      write(1)
    else
      write(0);
    j := j - 1;
  until (j = 0);
end.