program lab3;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

function z(i:integer; x:real): real;
begin
  if i = 256 then
    z := 256/(x*x)
  else
    z := x * x + i / (x * x + z(i*2, x))
end;

var x:real;
begin
  x := 5;
  //write('x= ');
  //readln(x);
  write(x/+z(2,x):0:5);
  readln();

end.
