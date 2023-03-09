var x, i, j, k, temp: integer;
begin
  write('enter x '); readln(x);
  if (x = 0) then 
    writeln( 'x(10) = 0; x(16) = 0')
  else begin
  write('x(10) = ', x, '; x(16) = ');
   // for k := 1 to 255 do begin
      //x := k; 
     // write ('x(10) = ', x, '; x(16) = '); 
      j := trunc(logn(16, x)) + 1;
      
      repeat
        temp := x;
        for i:= 1 to j - 1 do      
          temp := temp div 16;
        
        temp := temp mod 16;
        case temp of
          10: write('A');
          11: write('B');
          12: write('C');
          13: write('D');
          14: write('E');
          15: write('F');
          else write (temp);
        end;
        j := j - 1;
      until (j = 0);
      //writeln();
       
    end;    
  //end;
end.