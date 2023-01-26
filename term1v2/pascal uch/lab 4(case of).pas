var weekday, t, d, m :integer;
begin
  d := 9;
  m := 11;
  weekday := 7;
  case m of
  1: weekday := weekday;
  2: weekday := (weekday + 2) mod 7 + 1;
  3: weekday := (weekday + 2) mod 7 + 1;
  4: weekday := (weekday + 5) mod 7 + 1;
  5: weekday := (weekday + 7) mod 7 + 1;
  6: weekday := (weekday + 3) mod 7 + 1;
  7: weekday := (weekday + 5) mod 7 + 1;
  8: weekday := (weekday + 1) mod 7 + 1;
  9: weekday := (weekday + 4) mod 7 + 1;
  10: weekday := weekday;
  11: weekday := (weekday + 2) mod 7 + 1;
  12: weekday := (weekday + 4) mod 7 + 1;
  end;
  
  weekday := (weekday + d - 1) mod 7;
  writeln(weekday);

 
end.