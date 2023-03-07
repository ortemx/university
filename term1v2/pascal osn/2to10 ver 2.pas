unit to10ver2;
interface implementation;
var 
  x, i, j, k, temp, temp2: integer;
begin 
  x := 101010110;
  j:= 0;
  temp := x;
  repeat
    j := j + 1;
    temp := temp div 10;
  until temp = 0;
  
  for i := 0 to j-1 do begin    
    k := x mod 10;
    write( k, ' ' );
    temp := temp + k * round(power (2, i));
    x := x div 10;
  end;  
  writeln('temp = ', temp);
end.