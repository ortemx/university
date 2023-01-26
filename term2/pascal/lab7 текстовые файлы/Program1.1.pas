var
 s,sn:string;
 f,g:text; 
 begin
 assign (f, 'f.txt');
 assign (g, 'g.txt');
 reset(f);
 rewrite(g);
 while not (Eoln(f)) do
       begin
       readln(f,s);
       for var i:=1 to length(s) do
           if s[i] in ['0'..'9'] then
              sn:=sn+s[i]+s[i] else sn:=sn+s[i];
       writeln(g,sn);
       end;
 close(f);
 close(g);
 writeln(s);
 writeln(sn);
 end.