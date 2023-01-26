program prox;

type
  mas = array of array of integer;

var
  a: mas;
  b: mas;

procedure ans(a: mas; n ,m: integer);
var
  proc, i, j: integer;
begin  
  for i := 0 to n - 1 do
  begin
    for j := 0 to m - 1 do
    begin     
    end;
  end;
  //writeln(min, '[',e,',',q,']');
  //writeln;
end;

var
  proc, proc1, x, y, n, m, j, i, s, k,q: integer;  

begin
  readln(x, y);
  Setlength(a,x);
  setlength(a,y);
  //Setlength(a, x, y);
  for i := 0 to x - 1 do
  begin
    writeln;
    for j := 0 to y - 1 do
    begin
      a[i, j] := random(50) - 5;
      Write(a[i, j]:5);
    end;
  end;
  WriteLn;
  
  
  
  readln(s, k);
   Setlength(b,s);
   Setlength(b,k);
  //Setlength(b, s, k);
  for i := 0 to s - 1 do
  begin
    writeln;
    for j := 0 to k - 1 do
    begin
      b[i, j] := random(50) - 5;
      Write(b[i, j]:5);
    end;
  end;
  writeln;
  
  //ans(a, x, y, e, q);
  ans(b, s, k);
  
  writeln;
  
  readln;
end.

