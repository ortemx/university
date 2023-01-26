program lab3;
var a,a1,a2,a3,a4,a5,a6,a7,a8,a9,c,k:real; i,n:integer;
 begin
 readln(n);
 //ap:=1; // (i-1)/(i+1)+sin((exp(3*ln(i-1)))/(i+1))
 for i:=1 to n do
 begin
    a:=(i-1)/(i+1)+sin( (i-1)*(i-1)*(i-1) / (i+1) );
    c:=k;
    if a>0 then 
      k:=a;
    if (k>0) and (c>0) and (c<k) then
      k:=c;
   writeln(a);
 end; 
  writeln ('min=',k:10); 
  end.


