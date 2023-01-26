type 
  a = array of array of integer;
  b = array of integer;
var
  arr : a;
  line : b;
  collumn : b;
  m, n, i, j, index : integer;
begin
  randomize;
  n := 4;
  m := 4;
  setlength(line, m);
  setlength(collumn, n);
  setlength(arr, n);
  for i := 0 to n-1 do begin
    setlength(arr[i], m);
  end;
  
  for i := 0 to n-1 do begin
    for j := 0 to m-1 do begin
      arr[i,j] := random(100);
    end;
  end;
  arr.Printlines;
  
  for i := 0 to n-1 do begin
    for j := 0 to m-1 do begin
      line[j] := arr[i,j];
    end;    
    //write(line.IndexMin);
    for j := 0 to m-1 do begin
      collumn[j] := arr[line.IndexMin,j];
    end;
    write(collumn);
  end;
end.
  