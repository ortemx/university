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
     writeln('������� ��������� 1-��� ���������');
     write('������� a='); readln(a);
     write('������� b='); readln(b);
     write('������� c='); readln(c);
     kv(a,b,c);
     writeln('������� ��������� 2-��� ���������');
     write('������� a='); readln(a);
     write('������� b='); readln(b);
     write('������� c='); readln(c);
     kv(a,b,c);
End.     