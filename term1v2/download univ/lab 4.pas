function asin(X: Real): Real;
begin
 if X <= -1.0 then
   asin := -Pi / 2
 else if X < -Sqrt(2) / 2 then
   asin := -Pi / 2 - ArcTan(Sqrt(1 - Sqr(X)) / X) { левый край }
 else if X <= Sqrt(2) / 2 then
   asin := ArcTan(X / Sqrt(1 - Sqr(X))) { центр }
 else if X < 1.0 then
   asin := Pi / 2 - ArcTan(Sqrt(1 - Sqr(X)) / X) { правый край }
 else
   asin := Pi / 2
end;

var a,b,c: real; x:integer;

begin
  randomize; 
  a := random*(20)-10;
  b := random*(20)-10;
  c := random*(20)-10;
  readln(x);
  case x of
  10..19:
  begin
    writeln('Введите a b c:'); readln(a, b, c);
    writeln(a+b*x+c*x*x);
  end;
  20..29:
  begin
    writeln('Введите a b:'); readln(a, b);
    writeln(exp(2*ln(a*sin(x*b))));
  end;
  30..39:
  begin
    writeln('Введите a b c:'); readln(a, b, c);
    writeln(sqrt(abs(a+b*x*x*x)+c));
  end;
  40..49:
  begin
    writeln('Введите a b c:'); readln(a, b, c);
    writeln(a*ln(abs(b+c/(2*x))));
  end;
  50..59:
  begin
    writeln('c= '); readln(c);
    writeln(exp(asin(x))+c*c*c);
  end;  
  else 
    writeln('значение вне диапазона');  
  end;
end.