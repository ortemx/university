type
info = record
  group : byte;
  fio : string [50];
  ocenka : array [1..5] of integer;
  uchastie: byte;
end;
text = file of info;
//=============================
var 
f:text;
n,dva,tri,che:integer;
t:info;
//=============================//вспомогательная
procedure vyzov (var f:text);
begin
seek(f, filesize(f));
writeln('vvedite info studenta');
writeln('vvedite # gr');
readln (t.group);
writeln('vvedite fio studenta');
readln (t.fio);
writeln('vvedite ocenki studenta');
 for var i:=1 to 5 do 
  begin
    read (t.ocenka[i]);
  end;
writeln('uchastie v OR ');
readln(t.uchastie);
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
         	writeln('#gr ', t.group);				
					writeln('FIO  ', t.fio);
          writeln('ocenki   ', t.ocenka);
          writeln('uchastie   ', t.uchastie);          
          writeln;
     end;
     close(f);
end;
//=============================//работа со списком
procedure vybor(var f:text);
var gr:integer;
begin
reset(f);
writeln('vvedite # gruppy');
readln(gr);
while (not eof(f)) do
      begin
          read(f,t);
          if t.group = gr then 
          begin 
          dva:=0; tri:=0; che:=0;
          if ((t.ocenka[1]+t.ocenka[2]+t.ocenka[3]+t.ocenka[4]+t.ocenka[5])/5=5) and//5+учяастие
              (t.uchastie=1) then writeln(t.fio, ' +50%') else 
          if ((t.ocenka[1]+t.ocenka[2]+t.ocenka[3]+t.ocenka[4]+t.ocenka[5])/5=5) and//5 без участия
              (t.uchastie=0) then writeln(t.fio, ' +25%') else
             for var i:=1 to 5 do 
          begin
             if (t.ocenka[i]>3)//sum 4
             then che:=che+1;
             if (t.ocenka[i]=3)//sum 3 
             then tri:=tri+1;
             if (t.ocenka[i]=2)//sum 2
             then dva:=dva+1
          end;          
          if che=5 then writeln(t.fio, '+0%') else//4 и 5  
          if (tri = 1) and (dva=0) and (t.uchastie=1) then writeln(t.fio, ' +0%')//1 тройка+участие
           else writeln(t.fio, '-100%');
          end;         
      end;
close(f);
end;
//=============================//основная программа
begin
assign(f, 'info.txt');
repeat
  writeln('1. create');
  writeln('2. add');
  writeln('3. read');
  writeln('4. vybor');
  writeln('5. exit');  
  writeln('Choice: ');
  readln(n);
      case n of
      1: create(f);
      2: add(f);
      3: reading(f);
      4: vybor(f);
      5: exit();
      else
       writeln('Некорректный вариант!');
      end;
      writeln;
     until (n = 5);
end.