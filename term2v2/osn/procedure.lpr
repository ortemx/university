program procedure1;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

procedure zzz(a, b, c : integer; var x1, x2 : double; var flag : boolean);
var d : double;
begin
  d := b*b-4*a*c;
  if (d > 0) then begin
    x1 := (-b - sqrt(d))/(2*a);
    x2 := (-b + sqrt(d))/(2*a);
  end
  else if (d = 0) then begin
    x1 := -b/(2*a);
    x2 := x1;
  end
  else begin
    writeln('no roots');
    flag := false;
    //x1 := 0/0;
    //x2 := 0/0;
  end;

end;
var
  a1, b1, c1, a2, b2, c2 : integer;
  x1, x2, y1, y2, z : double;
  flag : boolean = true;
begin
  a1 := 1;
  b1 := 1;
  c1 := -6;
  a2 := 1;
  b2 := 1;
  c2 := 2;

  zzz(a1, b1, c1, x1, x2, flag);
  zzz(a2, b2, c2, y1, y2, flag);
  //writeln(x1, ' ',x2);
  //writeln(y1, ' ',y2);


  if not (flag) then
     writeln('z = NaN, couse equation_1 or equation_2 has no roots ')
  else  begin
        z := (x1+y1)/(x2-y2);
        writeln('z = ', z);
  end;
  readln();
end.
