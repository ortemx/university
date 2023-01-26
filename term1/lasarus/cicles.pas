program cicles;
uses crt;
var q,r,b,c,d,x0,x1,x:real;
    n:integer;
    i:byte;

begin
clrscr;
writeln('vvedite q,r,b,c,d');
read(q,r,b,c,d);
repeat
 write('n>1 n=');
 read(n);
until n>1;
x0:=c;
x1:=d;
for i:=2 to n do
 begin
  x:=q*x0+r*x1+b;
  x0:=x1;
  x1:=x
 end;
write('x',n,'=',x:0:2);
readln (n);
end.
