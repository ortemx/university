var 
A : array [1..3, 1..3] of integer = ((7,2,0), (-7,-2,1), (1,1,1));
B : array [1..3, 1..3] of integer = ((0,2,3), (1,0,-2), (3,1,1));
C : array [1..3, 1..3] of integer = ((0,0,0), (0,0,0), (0,0,0));
D, F : array [1..3,1..3] of integer;
i, j, k, p, t : integer;
begin  
  for i := 1 to 3 do begin
    for j := 1 to 3 do begin
      D[i,j] := A[i,j] + B[i,j];
      p := 0;
      t := 0;
      for k := 1 to 3 do begin
        p := p + A[i,k] * A[k,j];
        t := t + B[i,k] * B[k,j];
      end;
      F[i,j] := p - t;
    end;
  end;
  for i := 1 to 3 do begin
    for j := 1 to 3 do begin 
      for k := 1 to 3 do begin
        C[i,j] := C[i,j] + F[i,k] * D[k,j];
      end;
    end;
  end;
for i:=1 to 3 do
  begin
    for j:=1 to 3 do    
      write(c[i,j]:5);    
    writeln;
  end;
end.
