program project2;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

var x, y, z, temp:real;
begin
  randomize;

  //x := random(10);
 // y := random(10);
  //z := random(10);
 // writeln(x, ' ', y, ' ', z, ' ');

  write(' x = '); readln (x);
  write(' y = '); readln (y);
  write(' z = '); readln (z);
  if x < y then
    begin
    temp := x;
    x := y;
    y := temp;
    end;

  if x < z then
    begin
      temp := x;
      x := z;
      z := y;
      y := temp;
    end
  else if (y < z) then
    begin
      temp := y;
      y := z;
      z := temp;
    end;



  writeln('now x = ',x:0:0, ' y = ', y:0:0, ' z = ', z:0:0);
  readln();
end.

