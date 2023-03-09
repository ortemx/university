program lab3caseof;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

var weekday, t, day, month :integer;
begin
  // https://calendar.yuretz.ru/2019
  // mon  tue   wed   thu   fri   sat   sun
  // 2018 2019  2031  2026  2021  2022  2023
  randomize;
  writeln('enter weekday of 01.01');
  writeln('mon - 1, tue - 2, wed - 3, thu - 4, fri - 5, sat - 6, sun - 7');
  readln(weekday);
  //weekday := 7;
  write('enter day '); readln(day);
  write('enter month '); readln(month);
  //day := random(31) + 1; day := 30;
  //month := 4;
  case month of
    1, 10: t := 0;
    2, 3, 11: t := 2;
    4, 7: t := 5;
    5: t := 7;
    6: t := 3;
    8: t := 1;
    9, 12: t := 4;
  end;

  weekday := (weekday + t) mod 7 + 1; // weekday of 1 day of month
  weekday := (weekday + day - 2) mod 7 + 1; // weekday  of 'd' day of month

  case weekday of
    1: writeln('Monday');
    2: writeln('Tuesday ');
    3: writeln('Wednesday ' );
    4: writeln('Thursday ');
    5: writeln('Friday ');
    6: writeln('Saturday ');
    7: writeln('Sunday');
  end;
  readln();
end.
