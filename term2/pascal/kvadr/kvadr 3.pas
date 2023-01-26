var
  a1, b1, c1, a2, b2, c2: integer; 
  z,t,q1,q2, d1, d2: real;
//===========================================================
function   dis(a, b, c: integer): real;
begin
  dis := sqr(b) - 4 * a * c;
end;
//===========================================================
procedure   ans(a, b, d: real; var s:real);
var
  x1, x2: real;
begin     
  x1 := (-b + sqrt(d)) / (2 * a);
  x2 := (-b - sqrt(d)) / (2 * a);
  s:=x1+x2;
  writeln(x1, ' ', x2, 's=', s); 
end;
//===========================================================
begin
  //=======================
  writeln('vvedite a1,b1,c1');
  readln(a1, b1, c1);
  d1 := dis(a1, b1, c1); 
  
  if d1 >= 0 then
    ans(a1, b1, d1,t)
  else writeln('Korney net');
  q1:=t; 
  //=======================
  
  writeln;
  
  //=======================
  writeln('vvedite a2,b2,c2');
  readln(a2, b2, c2);
  d2 := dis(a2, b2, c2);   
  
  if d2 >= 0 then
    ans(a2, b2, d2,t)
  else writeln('Korney net');
  q2:=t;
  //=======================  
  z:=q1/q2;
  writeln(z);  
  readln;   
end.