var 
  f, g: text; 
  string_f, string_g, temp: string; 
  signs : string = ' !?_&:.,;';
  i : integer;
//===================
begin 
  Assign(f, 'f.txt');
  Reset(f); 
  Assign(g, 'g.txt'); 
  Rewrite(g); 
//===================
  while not EOF(f) do begin
    readln(f, string_f);
    string_g := '';
    for i := 1 to length(string_f) - 1 do begin
      if (not((string_f[i] = ' ') and (string_f[i+1] = ' '))) then
        string_g := string_g + string_f[i];
    end;
    string_g := ' ' + string_g;    
    temp := '';
    for i := 2 to length(string_g) - 1 do begin
      if not((pos(string_g[i], signs) = 0) and
      (not(pos(string_g[i+1], signs) <> 0)) or
      (not(pos(string_g[i-1], signs) <> 0)))then
        temp := temp + string_g[i]
    end;    
    writeln(temp);
    writeln(g, temp);
  end;
  writeln('Done!!!');
  close(f);
  close(g);
end.