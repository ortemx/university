var 
  
  s,p,d,d1: string;
  i,j,n,m:integer;
  f,g: text;
begin
  assign(f,'f.txt');
  assign(g, 'g.txt');
  
  reset(f);
  
  j := 1;
  while (not eof(f)) do
    begin
     readln(f,s);
     n := length(s);
      writeln(n);
      rewrite(g);
      for i := 1 to n do
        begin
            if (s[i] <> ' ') then
              p := p + s[i]
            else
              begin
                if (length(p) > 1) then
                    begin
                        
                        d := d +  p + ' ';
                        
                    end;
                   p := ''; 
              end;
              if (s[i] = s[n]) then
                begin
                  
                  writeln(g,d);
                  
                end;
        end;
        close(g);
    end;
  close(f);
  writeln('Откройте файл g');
end.

  