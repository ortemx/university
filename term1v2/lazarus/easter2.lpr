program easter2;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

var y, y1, y2,a,b,c,d:integer;
begin
write('enter range, y1 < y2; y1='); readln(y1);
write('y2= '); readln(y2);

for y:=y1 to y2 do
begin
  a:=(19*(y mod 19) +15) mod 30;
  b:=(2*(y mod 4)+4*(y mod 7) +6*a+6) mod 7;
  c:=a+b;
  write ('year ', y);
  if c>10 then
     begin
        d:=c-9+13;
        write (' ', d - 13, ' April old style ');
        if (d > 30) then
           writeln (' ', d-30, ' may new style ')
        else
           writeln (' ', d, ' April new style ') ;
     end
  else
      begin
        write (' ',c+22, ' march old style ');
        writeln (' ',c+22+13-31, ' April new style ');
      end;
end;
readln();

end.


