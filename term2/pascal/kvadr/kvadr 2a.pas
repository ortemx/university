var
  a1, b1, c1, a2, b2, c2: integer;
  d1, d2: real;

function   dis(a, b, c: integer): real;
begin
  dis := sqr(b) - 4 * a * c;
end;

procedure   ans(a, b, d: real);
var
  x1, x2: real;
begin 
  if d < 0 then writeln('nou')
  else
  if d = 0 then writeln('x=', (-b / (2 * a)):0:3)
  else
  begin    
    x1 := (-b + sqrt(d)) / (2 * a);
    x2 := (-b - sqrt(d)) / (2 * a); 
    writeln('x1=',x1, ' x2=', x2);
  end;
end;

begin
  
  readln(a1, b1, c1);   
  d1 := dis(a1, b1, c1);
  ans(a1, b1, d1);
  
  readln(a2, b2, c2);  
  d2 := dis(a2, b2, c2);
  ans(a2, b2, d2);
  
end.