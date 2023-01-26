program year;
var y,a,b,c,d:integer;
begin
readln (y);
a:=(19*(y mod 19) +15) mod 30;
b:=(2*(y mod 4)+4*(y mod 7) +6*a=6) mod 7;
c:=a+b;
if c>10 then write (c-9, 'апреля по старому стилю') else write (c+22, 'марта по старому стилю'); write (c+22+13-31, 'апреля по новому стилю');
d:=c-9+13;
if d<=30 then write (d, 'апреля по новому стилю') else write (d-30, 'мая по новому стилю');
end.

