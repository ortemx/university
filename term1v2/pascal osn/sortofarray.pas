var 
  a : array [1..10] of integer;
  b : array [1..10] of integer;
  i, j, temp, min, indexmin, c: integer;
  flag : boolean;
begin
  randomize;
  for i := 1 to 10 do begin  
    a[i] := random (100);
    b[i] := a[i];
  end;   
  println(b); 
// ============ selection sort =============
  for i := 1 to 10 do begin
    min := b[i];
    indexmin := i;
    for j := i to 10 do begin  
      if b[j] < min then begin
        min := b[j];
        indexmin := j;
      end;
    end;
    temp := b[i];
    b[i] := b[indexmin];
    b[indexmin] := temp
  end;
  println(b); 
// ============ Insertion sort =============
  for i := 1 to 10 do begin
    b[i] := a[i];
  end;   
  //println(b);
  for j := 2 to 10 do begin
    temp := b[j];
    i :=  j - 1;
    while ((i > 0) and (b[i] > temp)) do begin
      b[i + 1] := b[i];
      i := i - 1;
    end;
    b[i+1] := temp;
    //println(b); 
  end; 
  println(b);
// ============ bubble sort =============
  for i := 1 to 10 do 
    b[i] := a[i];

  c := 0;
  for i := 1 to 9 do begin
    flag := True;
    for j := 1 to 10-i do begin
      inc(c);
      if (b[j] > b[j+1]) then begin
        flag := false;
        temp:= b[j];
        b[j] := b[j+1];
        b[j+1] := temp;        
      end;
    end;
    if (flag) then 
      //break;
  end;   
  println(c, b);
// ============ bubble sort 2=============
  for i := 1 to 10 do
    b[i] := a[i];
  c := 0;
  for i := 10 downto 1 do begin
    flag := True;
    for j := 10 downto 10-i+2 do begin
      inc(c);
      if (b[j-1] > b[j]) then begin
        flag := false;
        temp:= b[j];
        b[j] := b[j-1];
        b[j-1] := temp;        
      end;
    end;
    if (flag) then 
      break;
  end;   
  println(c, b);
end.