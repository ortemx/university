program project3;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };
var a, K, c: integer;
begin
  c := 0;
  write ('K = '); readln (K);
  writeln ('enter values of a');
  repeat

    readln (a);
    if (a < K) then
      inc(c);

  until (a = 0);

  write ('c = ', c);
  readln;
end.

