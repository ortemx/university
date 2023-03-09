var weekday, t, d, m :integer;
begin
  d := 10;
  m := 12;
  weekday := 1;
  case m of
  2: t := weekday + 30;
//  3: 
//  4:
//  5:
//  6:
//  7:
//  8:
//  9:
//  10:
//  11:
//  12:
  end;
  weekday := t mod 7;
  writeln(weekday);

end.