var a1,b1,c1,a2,b2,c2:integer; x11,x12,x21,x22,d1,d2:real;

procedure   ans(a,b,c:integer);   
 var d,x1,x2: real;
begin
d:=sqr(b)-4*a*c;
//if d>=0 then 
//begin
x1:=(-b+sqrt(d))/(2*a);
x2:=(-b-sqrt(d))/(2*a); 
writeln(x1, ' ', x2);
//end;
end;

begin

readln (a1,b1,c1);
readln (a2,b2,c2);
ans(a1,b1,c1);
ans(a2,b2,c2);
end.