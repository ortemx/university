program functiongetmem;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

type
  ar1 = array [1..1] of integer;
  ar2 = ^ar1;
  ar3 = array [1..1] of ar2;
  mas = ^ar3;
// pricedure  outsideofcircle(a : mas; n, r : integer);
function outsideofcircle(a : mas; n, r : integer) : integer;
var i, count : integer;
begin
  for i:= 1 to n do begin
    if (sqr(a^[i]^[1] - 1) + sqr(a^[i]^[1] - 1) > r*r) then
    inc(count);
  end;
  // writeln('count of points X[i] outside the circle', count);
  outsideofcircle := count;
end;
var
  x : mas;
  y : mas;
  n, m, i , r: integer;
begin
  //n := 2;
  //m := 2;
  //r := 3;

  write('n = '); readln(n);
  write('m = '); readln(m);
  write('r = '); readln(r);
  getmem(x, n * sizeof(integer));
  for i:= 1 to n do
    getmem(x^[i], 2 * sizeof(integer));
  getmem(y, m * sizeof(integer));
  for i:= 1 to m do
    getmem(y^[i], 2 * sizeof(integer));

  for i:= 1 to n do begin
    write('enter coord x', i+1, ' ');
    readln(x^[i]^[1], x^[i]^[2]);
  end;
  for i:= 1 to m do begin
    write('enter coord y', i+1, ' ');
    readln(y^[i]^[1], y^[i]^[2]);
  end;

  writeln('count of points X[i] outside the circle ', outsideofcircle(x, n, r));
  writeln('count of points Y[i] outside the circle ', outsideofcircle(y, m, r));
  readln();
end.
