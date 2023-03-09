
var
  s : string;
  sign : string = ' !?_&:.,;';
  numberofwords : integer = 0;
  numberofa : integer = 0;
  numberofb : integer = 0;
  numberofoneequallast : integer = 0;
  lengthofshortest : integer = 0; 
  i, j : integer;
begin
  s := 'Aga... mama by myla ramu, esli by Big boss byl molodcom? Aga, da!';
  //s := 'arozaupalanalapuAzora';
  s := ' ' + s + ' ';
  writeln(s);
//================================================
//  1.
//================================================ 
  for i := 1 to length(s) - 1 do
    if (pos(s[i], sign) <> 0 ) and ( pos(s[i+1], sign) = 0 ) then
      inc(numberofwords);
  writeln ('number of words – ', numberofwords);
//=====================================================
//  2.
//=====================================================    
  i := length(s);
  repeat
    i -= 1; 
    if (s[i] = 'a') or (s[i] = 'A') then   
      inc(numberofa);  
  until ((pos(s[i], sign) = 0) and (pos(s[i-1], sign) <> 0 ));
  writeln ('number of letter "a" – ', numberofa); 
//=====================================================
//  3.
//=====================================================       
  for i := 1 to length(s) - 1 do 
    if ((s[i] = 'b') or (s[i] = 'B')) and ( pos(s[i-1], sign)=' ' ) then 
      inc(numberofb);
  writeln ('number of words beginning with the letter "B" – ', numberofb); 
//=====================================================
//  4) + 5)
//=====================================================
  i := 0;
  repeat    
    i += 1;
    if (pos(s[i], sign) <> 0 ) and ( pos(s[i+1], sign) = 0 ) then begin
      j := i;
    end;
  until (pos(s[i], sign) = 0 ) and ( pos(s[i+1], sign) <> 0 );
  lengthofshortest := i - j;
//==================================================================   
  i := 1;
  while (i < length(s)) do begin
    if (pos(s[i], sign) <> 0 ) and ( pos(s[i+1], sign) = 0 ) then begin
      j := i; 
      repeat        
        j += 1;        
      until (pos(s[j], sign) <> 0);
      //=== search shortest word;
      if((j - 1 - (i + 1)) < lengthofshortest) then begin
        lengthofshortest := (j  - (i + 1));
      end;
      //===
      if (s[i+1] = s[j-1]) or (ord(s[i+1]) = ord(s[j-1]) - 32) then begin
        numberofoneequallast += 1;        
      end;
    end;    
    i += 1;
  end;

writeln ('number of words beginning and ends with the same letter – ', numberofoneequallast);  
writeln ('the shortest word has ', lengthofshortest, ' symbols'); 
end.