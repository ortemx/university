const n =3;
var i,j,s,k:integer; C: array [1..n, 1..n]of integer;
a:array [1..n, 1..n] of integer=((5,3,-1),(2,0,4),(3,5,-1)); 
b:array [1..n, 1..n] of integer=((1,4,16),(-3,-2,0),(5,7,2)); 
begin

for i:=1 to n do
for j:=1 to n do
begin
s:=0;
for k:=1 to n do
  s:=s+A[i,k]*b[k,j];
c[i,j]:=2*a[i,j]-b[i,j]+s;
end;

for i:=1 to n do
begin
for j:=1 to n do
write(c[i,j]:4);
writeln;
end;
    readln;
end.


