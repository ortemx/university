var
  t, k, n: integer;  
  mes: array [1..12] of integer = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);
begin
  readln(n);
  
  if n = 3 then  inc(k);
  
  for var i := 2  to 12 do
  begin
    t := n + mes[i - 1];
    if t mod 7 = 3 then 
      inc(k);
    n := t mod 7;
    writeln('i=', i:2, ' n=', n, ' mes[i]=', mes[i]:2, ' k=', k);
  end; 
  writeln(k);
end.