var
m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12:integer;
nm,t,k,n:integer;
d1,d2,d3,d4,d5,d6,d7:integer;
mes:array [1..12] of integer=(31,28,31,30,31,30,31,31,30,31,30,31);
 begin
 m1:=31;m3:=31;m5:=31;m7:=31;m8:=31;m10:=31;m11:=31;m12:=31;
 m4:=30;m6:=30;m9:=30;m11:=30;
 m2:=28;
 readln (n);
 
 if n = 3 then k:=1;      //yan
 
 if (n+m1) mod 7 = 2 then //fev
 begin
 k:=k+1;
 n:=n+1;
 end;
 
 if (n+m2) mod 7 = 2 then  //mar
 begin
 k:=k+1;
 n:=n+1;
 end; 
 
 {for var i:=2 to 12 do
 begin
  t:=(n+mes[i]) mod 7 ;
  if t = 3 then k:=k+1;   
  writeln('i=',i:2, '  n do=',n, mes[i]:3, n+mes[i]:3, t :3,k:3);
  n:=(n+mes[i]) mod 7; 
 end;}
 
 
 writeln(k);
 end.