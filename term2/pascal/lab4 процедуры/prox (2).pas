program prox;
type 
mas =array of array of integer;
var a:mas;b :mas;

procedure fag(a:mas; n,m:integer);
 var r,q,i,j,min:integer;
 begin
 min:=a[1,1];
for i:=0 to n-1 do
  begin
   for j:=0 to m-1 do
   begin 
   if min>a[i,j] then
   begin
   min:=a[i,j];
   r:=i;
   q:=j;
   end;
   end;
   end;
   writeln(min, '[' , r , ',' , q , ']'); 
   writeln;
   end;
     

var n,m,j,i,s,k:integer;

begin 
readln(n , m);
 Setlength(a,n);
 Setlength(a,m);
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
