var 
  str, az :string;
  i, k, j, kmax, length, a, b:integer;
  // ord(a..z) = 97..122
  // ord(A..Z) = 65..90
  
begin
  az := 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
  str := 't54h7745,477gv8755hg4g54g,if85gj6588';
  length := str.Length;
  str += 'a'; 
  
  k:= 0;
  kmax := 0;
   
  for i := 1 to length do begin
    if (pos(str[i], az) = 0) then begin
      a := i;
      b := a;
      repeat
        b += 1;
      until ((pos(str[b], az) <> 0)); 
      writeln('a= ',a,' b= ',b);
      k:= b - a;      
      if (k > kmax) then
        kmax := k;
    end;
  end;
  writeln('kmax = ', kmax); 
  
end.