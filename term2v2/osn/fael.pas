type
abonent = record
  surname : string [20];
  year : integer;  
  number: string[11];
end;
text = file of abonent;
//=============================
var 
f:text;
n:integer;
t:abonent;
//=============================//вспомогательная
procedure vyzov(var f:text);
begin
  seek(f, filesize(f));
  writeln('enter abonent info');
  write('enter surname : ');
  readln (t.surname);
  write('enter year of installation : ');
  readln (t.year);
  write('enter number : ');
  readln(t.number);
  write(f,t);
end;
//=============================//создание
procedure create (var f:text);
begin
  rewrite (f);
  vyzov (f);
  close(f);
end;
//=============================//добавление
procedure add(var f:text);
begin
  reset(f);
  vyzov(f);
  close(f);
end;
//=============================//чтение
procedure reading(var f:text);
begin
     reset(f);
     while not eof(f) do
     begin
          read(f, t);
         	writeln('surname : ', t.surname);				
					writeln('year of installation : ', t.year);
          writeln('number  : ', t.number);          
          writeln;
     end;
     close(f);
end;
//=============================//работа со списком
procedure number_by_surname(var f:text);
var 
  surname : string[20];
  flag : boolean = true;
begin
  reset(f);
  write('enter surname : ');
  readln(surname);
  while (not eof(f)) do begin
    read(f,t);
    if (t.surname = surname) then begin 
      flag := false;
      writeln(t.number);
    end;         
  end;
  if (flag) then 
    writeln('abonent not found');
  close(f);
end;

procedure count_by_year(var f:text);
var 
  count, year : integer;
begin
  reset(f);
  write('enter year : ');
  readln(year);
  while (not eof(f)) do begin
    read(f,t);
    if (t.year >= year) then begin 
      inc(count);
    end;         
  end;
  writeln('count_by_year : ', count);
  close(f);  
end;
//=============================//основная программа

begin
assign(f, 'info.txt');
repeat
  writeln('1. create');
  writeln('2. add');
  writeln('3. read');
  writeln('4. number_by_surname');
  writeln('5. count_by_year');
  writeln('6. exit');  
  writeln('Choice: ');
  readln(n);
      case n of
      1: create(f);
      2: add(f);
      3: reading(f);
      4: number_by_surname(f);
      5: count_by_year(f);
      6: exit();
      else
        writeln('invalid input!');
      end;
      writeln;
     until (n = 5);
end.