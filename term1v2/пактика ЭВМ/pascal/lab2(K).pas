var a, K, c: integer;

begin
  c := 0;
  write ('K = '); readln (K);
  write ('a = ');
  repeat
    begin
    read (a);
    if (a < K) then 
      inc(c);
    end
  until (a = 0);
    
  write (c);
  
end.