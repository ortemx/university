var 
f,g:text;
//ch:set of 0..9;
ch:set of char = ['0'..'9'];
sf,sg:string;
n,k:integer;
begin
 assign (f, 'f.txt');
 assign (g, 'g.txt');
 reset(f);
 rewrite(g);
 while not (eof(f)) do
 begin
   readln(f,sf);
     n:= length(sf);
      writeln(n);     
      sg:=sf;
      k:=1;
      for var i := 1 to n do
        begin            
            if sf[i] in ch = true then
            begin
              insert(sf[i], sg, i+k);              
              k:=k+1;              
            end;
        end;        
    end;
    close(f);
    writeln(g,sg);
    close(g);
    writeln(sf);
    writeln(sg);
 end.