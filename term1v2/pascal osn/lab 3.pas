var n:integer; s, q, q_max:real;

begin
  Randomize;
  
  q := random*(20)-10;
  q_max := abs(q);
  s := sqr(q);
  n := 100;
  for i:integer := 0 to n-1 do 
  begin
    q := random*(20)-10;
    if q_max < abs(q) then
      q_max := abs(q);
    s := s + sqr(q);
  end;
  writeln (q_max, ' ', s);
end.