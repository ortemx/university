type figura=(pryamoyg,treugolnik ,trapeciya, krug, sektor); var
  a, b, r, h,  S, fi: real; n:byte;
begin
  writeln('vvedite nomer figury: 1-pryamoyg, 2-treugolnik , 3-trapeciya, 4-krug, 5-sektor');
  readln(n);
  case n of
  1:    begin
    writeln('vvedite a,b');  readln(a, b); s := a * b; end;
  2:   begin
    writeln('vvedite a,h'); readln(a, h); s := a * h / 2; end;
  3:  begin
    writeln('vvedite a,b,h');  readln(a, b, h); s := (a + b) * h / 2; end;
  4:  begin
    writeln('vvedite r'); readln(r); s := pi * r * r; end;
  5:   begin
    writeln('vvedite r,fi');  readln(r, fi); s := pi * r * r * fi / 360; end; end;
  writeln('s=', s); readln(n)
end.

