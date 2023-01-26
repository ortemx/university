program proc;
function fnc(x,y,z:real):real;
begin 
procedure kv(x,y,z:real);
Var  d,x1,x2:real;
Begin 
     d:=sqr(y)-4*x*z;
     x1:=(-y+sqrt(d))/2*x;
     x2:=(-y-sqrt(d))/2*x;
     writeln('x1=',x1,' x2=',x2);
End;
Var  a,b,c:real;
Begin
     writeln('Введите кофиценты 1-ого уравнения');
     write('Введите a='); readln(a);
     write('Введите b='); readln(b);
     write('Введите c='); readln(c);
     desk:=d(a,b,c);
     if fnc>0 then kv(a,b,c)
     else wtiteln('Корней нет');
     writeln('Введите кофиценты 2-ого уравнения');
     write('Введите a='); readln(a);
     write('Введите b='); readln(b);
     write('Введите c='); readln(c);
     desk:=d(a,b,c);
     if fnc>0 then kv(a,b,c)
     else wtiteln('Корней нет');
End.
