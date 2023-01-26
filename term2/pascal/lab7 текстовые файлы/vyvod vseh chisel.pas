var 
f,g:text;
ch:set of char = ['0'..'9'];
sf,sg:string;
k:integer;
begin
 assign (f, 'f.txt');
 assign (g, 'g.txt');
 reset(f);
 rewrite(g);
 while not eof(f) do
 begin
  readln(f,sf);      
  sg:=sf;
  k:=1;
  for var i := 1 to length(sf) do
   begin            
     if sf[i] in ch then
     begin
      insert(sf[i], sg, i+k);              
      k:=k+1;              
     end;
   end;
 writeln(g,sg);
 end; 
 close(g);
 close(f); writeln(sf); writeln(sg);
end.