
var x, i, j, k, temp, temp2: integer;
a: array[1..16] of integer = (0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111);
begin 
  //for n :integer := 1 to 16 do 
  //begin  
    //x := a[n];
    write('enrer x(2): '); readln(x);
    if x = 0 then
      writeln('x(10) = ', x)
    else begin
      j:= 0;
      temp := x;
      repeat
        j := j + 1;
        temp := temp div 10;
      until (temp = 0);
     
      for i := 0 to j-1 do begin    
        k := x mod 10;
        temp := temp + k * round(power (2, i));
        x := x div 10;
      end;
     
      writeln('x(10) = ', temp);      
    end;
    readln();
 
end.