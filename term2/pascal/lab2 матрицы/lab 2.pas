const n =3;
var i,j,s,k:integer; A,B,C: array[1..n,1..n] of integer;
begin
A[1,1]:=5; A[1,2]:=3; A[1,3]:=-1; B[1,1]:=1; B[1,2]:=4; B[1,3]:=16;
A[2,1]:=2; A[2,2]:=0; A[2,3]:=4; B[2,1]:=-3; B[2,2]:=-2; B[2,3]:=0;
A[3,1]:=3; A[3,2]:=5; A[3,3]:=-1; B[3,1]:=5; B[3,2]:=7; B[3,3]:=2;
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

write(c[i,j]:3, ' ');
writeln;
end;

end.


