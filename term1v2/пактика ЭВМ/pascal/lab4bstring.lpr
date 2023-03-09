program lab4bstring;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };
var text, str, revstr: string; i, l, l2, j, temp:integer;

begin
  text := 'mama, 123! myla!!! 3ramu?';
  text := text + ' ';
  l := length (text);
  for i := 1 to l do begin
    temp := ord(text[i]);
    if ((64 <temp) and (temp < 91)) or ((96 <temp) and (temp < 123)) then begin
        str := str + text[i];
    end
    else begin

      if (str <> '') then begin
          l2 := length(str);
          for j := 1 to l2 do begin
            revstr += str[l2 - j + 1];
          end;
          str := '';
          write(revstr);
          revstr := '';
      end;
      write(text[i]);
    end;

  end;
  readln();
end.
