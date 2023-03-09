program lab3cycle;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

var x,z,y:real; i: integer;

begin
  write('enter x '); readln(x);
  //x := 5;
  z := x * x;
  y := 256;
  for i:=8 downto 1 do
  begin
    z := x * x + y / z;
    y := y / 2;
  end;
  writeln(x/z:0:10);
  readln();
end.
