program qqq;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

var i, n:integer; s, q, q_max:real;

begin
  Randomize;

  //q := random*(20)-10;
  //q_max := abs(q);
  //s := sqr(q);
  //n := 100;
  write ('enter number of elements ');  readln(n);
  write (1,'. enter q '); readln (q);
  q_max := abs(q);
  s := sqr(q);
  for i := 1 to n-1 do
  begin
    q := random*(20)-10;
    write (i+1,'. enter q '); readln (q);
    if q_max < abs(q) then
      q_max := abs(q);
    s := s + sqr(q);
  end;
  writeln ('|q| max =  ', q_max:0:2, ' s= ', s:0:2);
  readln();
end.
