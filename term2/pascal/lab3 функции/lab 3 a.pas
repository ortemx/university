//Const n=10;m=10;k=10; 
Type mas=array of integer; 
Var X,Y,Z:mas; 
i:byte; 
var n,m,k,kol:integer;

Function Sum(A:mas;n:byte):double; 
Var i,s:integer; 


Begin
//SetLength(A,n); 
s:=0;
kol:=0; 
For i:=0 to n-1 do 
if A[i]>0 then
begin
 s:=s+A[i]; kol:=kol+1;
Sum:=s/kol; 
end
End; 

Begin 
randomize; 
readln (n,m,k);

SetLength(x,n);
writeln('Массив X'); 
For i:=0 to n-1 do 
Begin 
X[i]:=random(30)-10; 
write(X[i]:4); 
End; 
writeln; 

  SetLength(y,m);
writeln('Массив Y'); 
For i:=0 to m-1 do 
Begin 
Y[i]:=random(30)-10; 
write(Y[i]:4); 
End; 
writeln; 

  SetLength(z,k);
writeln('Массив Z'); 
For i:=0 to k-1 do 
Begin 
Z[i]:=random(30)-10; 
write(Z[i]:4); 
End; 
writeln;
 
writeln('Среднее арифметическое положительных элементов массива X = ',Sum(X,n):0:3); 
writeln('Среднее арифметическое положительных элементов массива Y = ',Sum(Y,m):0:3); 
writeln('Cреднее арифметическое положительных элементов массива Z = ',Sum(Z,k):0:3); 
readln; 

End.