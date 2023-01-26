program proc;
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
     writeln('¬ведите кофиценты 1-ого уравнени€');
     write('¬ведите a='); readln(a);
     write('¬ведите b='); readln(b);
     write('¬ведите c='); readln(c);
     kv(a,b,c);
     writeln('¬ведите кофиценты 2-ого уравнени€');
     write('¬ведите a='); readln(a);
     write('¬ведите b='); readln(b);
     write('¬ведите c='); readln(c);
     kv(a,b,c);
End.     