program project16to10;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

var s, i, temp: integer; x :string; t :char;

begin
    write ('N(16)= '); readln (x);
    //x := '1';
    s := 0;

    for i := length(x) downto 1 do begin
      t := x[length(x) - i + 1];

      if (ord(t) > 64) then
        temp := ord(t) - 55
      else
        temp := ord(t) - 48;
      s := s + temp * round(exp((i-1)*(ln(16))));
      //s := s + temp * round(power (16, i - 1));
    end;

    writeln('N(10) = ', s);
    readln();
end.
