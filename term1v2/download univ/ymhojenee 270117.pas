const
 n=3; m=4; 
 
 var
  a:array[1..n,1..m] of integer;
  b:array[1..m,1..n] of integer;
  i,j,k:integer;
 begin
 //���������� ������� ���������� ������� �� 1 �� n*m
  k:=1;
  for i:=1 to n do
    for j:=1 to m do
     begin
      
      a[i,j]:=k;
      inc(k);
      end;
      
    // ����� �������  
      for i:=1 to n do
     begin
    for j:=1 to m do
    write(a[i,j]:5);
    writeln;
    end;
      //���������������� �������
      
      for i:=1 to n do
         for j:=1 to m do
            b[j,i]:=a[i,j];
    
   // ����� �������
  writeln; 
     for i:=1 to m do
     begin
    for j:=1 to n do
    write(b[i,j]:5);
    writeln;
    end;
    end.
  
  