var s, i, temp: integer; x :string; t :char;

begin 
    x := '15';
    s := 0;
   
    for i := length(x) downto 1 do begin    
      t := x[length(x) - i + 1];
      
      if (ord(t) > 64) then
        temp := ord(t) - 55
      else 
        temp := ord(t) - 48;
      //writeln('temp = ', temp);
      s := s + temp * round(power (16, i - 1));
    end;
   
    writeln('N(10) = ', s);  
    readln();
end.