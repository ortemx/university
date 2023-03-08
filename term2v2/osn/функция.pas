type 
  mas = array of array of integer;
function outsideofcircle(a : mas; n, r : integer) : integer;
var i, count : integer;
begin
  for i:= 0 to n-1 do begin
    if (sqr(a[i][0] - 1) + sqr(a[i][1] - 1) > r*r) then
    inc(count);
  end;
  outsideofcircle := count;
end; 
var 
  x : mas;
  y : mas;
  n, m, i , r: integer;
begin
  n := 2;
  m := 2;
  r := 3;
  write('n = '); readln(n);
  write('m = '); readln(m);
  write('r = '); readln(r);
  setlength(x, n);
  for i:= 0 to n-1 do
    setlength(x[i], 2); 
  setlength(y, m);
  for i:= 0 to m-1 do
    setlength(y[i], 2);
    
  for i:= 0 to n-1 do begin
    write('enter coord x', i+1, ' ');
    readln(x[i][0], x[i][1]);
  end;
  for i:= 0 to m-1 do begin
    write('enter coord y', i+1, ' ');
    readln(y[i][0], y[i][1]);
  end; 
  
  writeln('count of points X[i] outside the circle ', outsideofcircle(x, n, r));
  writeln('count of points Y[i] outside the circle ', outsideofcircle(y, m, r));
end.