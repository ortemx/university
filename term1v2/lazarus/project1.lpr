program project1;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };


var a,b,t,y, w: real;

begin
  //a := -0.5;
  //b := 1.7;
  //t := 0.44;
  write('a='); readln(a);
  write('b='); readln(b);
  write('t='); readln(t);
  y := exp(-b * t) * sin(a * t + b) - sqrt(abs(b * t + a));
  w := b * sin(a * t * t * cos(2 * t)) - 1;
  writeln('y= ', y:0:3);
  writeln('w= ', w:0:3);
  readln();
end.

