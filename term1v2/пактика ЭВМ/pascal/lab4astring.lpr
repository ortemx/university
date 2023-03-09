program lab4astring;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

var text,str:string; i, k, l, temp:byte;

begin
  text := 'str? strtwo fgh... www!';

  //readln(text);
  text := text + '.';
  l := length(text);
  i := 1;
  while i <= l  do begin
    temp := ord(text[i]);

    if ((64 <temp) and (temp < 91)) or ((96 <temp) and (temp < 123)) then begin
      str += text[i];
    end
    else begin
      if (str <> '') then begin
        writeln(str);
        str := '';
        inc(k);
      end;


    end;

    inc(i);
  end;
  writeln(k, ' words');
  readln();
end.
