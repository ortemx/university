type 
  mas = array of array of integer;
  lin= array of integer;  
var 
  //a : mas;
  a : array [0..2,0..3] of integer = ((2, 3, 5, 2), (2, 4, 6, 0), (-2, 7, 2, 2));
  line, collumn, arrayindex : lin;
  i, j, n, m, k, min, max, numberofmin: integer;
begin
  n := 3; 
  m := 4;
  //readln(n, m);  
  setlength(collumn, n);
  setlength(line, m);
  
  //setlength(a, n); 
  //for i := 0 to n-1 do
     //setlength(a[i], m);
     
  //a := ((5, 6, 4, 5), (-2, 5, 3, 7), (8, 7, -2, 6));   
  for i := 0 to n-1 do 
    for j := 0 to m-1 do begin
      //write ('enter a[', i,',', j, ']');
      //readln(a[i,j]);
    end;
  
  // === проход по строкам ======================================
  for i := 0 to n-1 do begin
    // 1 копирование в строку
    for j := 0 to m-1 do
      line[j] := a[i, j];
    min := line[0];
    numberofmin := 1;
  // 2 =============================================================  
    for j := 1 to m-1 do
      if (line[j] = min) then
        inc(numberofmin)
      else
        if line[j] < min then begin
          min := line[j];
          numberofmin := 1;
        end;
  // 3 =============================================================    
    setlength(arrayindex, numberofmin);
    k := 0;
    for j := 0 to m-1 do begin
      if line[j] = min then begin
        arrayindex[k] := j;
        inc(k);
      end; 
      
    end;
// 4 =============================================================   55      
    for j := 0 to length(arrayindex)-1 do begin
      max := line[arrayindex[j]];
      for k := 0 to n-1 do
        if a[k][arrayindex[j]] > max then
          max := a[k][arrayindex[j]];
      if min = max then 
        writeln('saddle point ', min, '(', i+1, ',', arrayindex[j]+1, ')');
      end;      
  end;
end.