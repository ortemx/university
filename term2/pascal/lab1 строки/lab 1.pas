
  var
  s,s1,s2 : string;
  i : byte;
Begin
  write('Wwedite stroku so slowami razdel probelami : ');
  readln(s);
  s:=s+' '; s1:=''; s2:='';
  for i:=1 to length(s) do begin
    if s[i]<>' ' then s1:=s1+s[i] else 
    begin
      s2:=s1+' '+s2;
      s1:='';
    end;
  end;
  writeln(s2);
  readln;
end.