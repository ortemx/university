program fael_lazarus;
var
  f, g : text;
  string_f, string_g, temp : string;
  signs : string = ' !?_&:.,;';
  i : integer;
begin
  Assign(f, 'f.txt');
  Reset(f);
  Assign(g, 'g.txt');
  Rewrite(g);
  while not EOF(f) do begin
    readln(f, string_f);
    string_g := '';
    for i := 1 to length(string_f) - 1 do begin
      if (not((string_f[i] = ' ') and (string_f[i+1] = ' '))) then
        string_g := string_g + string_f[i];
    end;
    string_g := ' ' + string_g + ' ';
    i := 2;
    while(i < length(string_g)) do begin
       writeln(string_g);
       if ((string_g[i] <> ' ') and
           (string_g[i-1] =  ' ' ) and
           (string_g[i+1] =  ' ')) then begin
             Delete(string_g, i-1, 2);
             i := i-1;
       end;
       inc(i);
    end;
    if string_g[1] = ' ' then
      Delete(string_g, 1, 1);
    //writeln(string_g);
    writeln(g, string_g);
  end;

  close(f);
  close(g);
  readln();
end.

