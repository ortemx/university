program prox;
type 
mas =array of array of integer;
var a:mas;b :mas;
n,m,j,i,s,k:integer;

procedure fag(a:mas; n,m:byte;var  min:Integer);
begin
for var i:=0 to n-2 do
  begin
  writeln;
    for var j:=0 to m-2 do  
     begin
     //min:=a[0,0]
     if a[i,j]<a[i+1,j+1] then min:=a[i,j]
     end;
     end;
end;



begin 
readln(n , m);
 Setlength(a,n,m);
  for i:=0 to n-1 do
  begin
  writeln;
    for j:=0 to m-1 do  
     begin
       a[i,j]:=random(10)-5;
       Write(a[i,j]:5);
     end;
   end;
     WriteLn;
     
   
     
 readln(s, k);
 Setlength(b,s,k);
  for i:=0 to s-1 do
  begin
  writeln;
    for j:=0 to k-1 do  
     begin
       b[i,j]:=random(10)-5;
       Write(b[i,j]:5);
     end;
   end;
     readln    
  
end.
