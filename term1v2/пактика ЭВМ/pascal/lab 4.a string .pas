var text,str:string; i, k, l, temp:byte;

begin
  text := 'str//strtwo///345v. www';
  
  //readln(text);
  text := text + '.';
  l := length(text);
  writeln(l);
  i := 1;
  while i <= l  do begin
    temp := ord(text[i]);
    
    if ((64 <temp) and (temp < 91)) or ((96 <temp) and (temp < 123)) then begin
      str += text[i];
    end
    else begin
      if (str <> '') then begin
        writeln(str);
        str := '';
        inc(k);
      end;
      

    end;
    
    inc(i);
  end;
  writeln(k, ' words');
end.