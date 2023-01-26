var x, i, j, k, temp: integer;
begin
  for k := 0 to 8 do begin
    x := k; 
    write ('x(10) = ', x, '; x(16) = ');    
    j := trunc(logn(2, x+1)) + 1;
    
    temp := x;
    for i:= 1 to j - 1 do      
      temp := temp div 2;
    if temp <> 0 then 
       write(temp);
    j := j - 1;
    
    repeat
      temp := x;
      for i:= 1 to j - 1 do      
        temp := temp div 2;
      
      temp := temp mod 2;
      write(temp);
      j := j - 1;
    until (j <= 0);
    writeln();
  end; 
end.