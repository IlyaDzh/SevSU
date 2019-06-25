program lab2;
const e = 0.0001;
var t, xn, xk, x, s, h: real;
    n: integer;
begin
    repeat
    write('¬ведите начало интервала в (-1;1) xn=');
    readln(xn);
    until abs(xn) < 1;
    repeat
    write('¬ведите конец интервала, ', xn:0:2, '<xk<1 xk=');
    readln(xk);
    until (xk > xn) and (xk < 1);
    repeat
    write('¬ведите шаг табул€ции, h<', xk - xn:0:2, ' h=');
    readln(h);
    until h < xk - xn;
    x := xn;
    writeln('“абулирование функции F(x)=ln((1+x)/(1-x)),');
    writeln('на интервале с ', xn:0:1, ' до ', xk:0:1, ' с шагом ', h:0:2);
    writeln;
    writeln('    -------------------------');
    writeln('    |   X   |    S    |  n  | ');
    writeln('    -------------------------');
    while x <= xk + h / 2 do
      begin
       n := 0;
       t := x;    {нулевой член р€да}
       s := t;    {сумма при n=0}
       while abs(t / (2 * n + 1)) >= e do   {пока очередной член больше точности}
          begin
           n := n + 1;    {увеличиваем номер}
           t := t * x * x;    {домножаем на x^2}
           s := s + t / (2 * n + 1);    {суммируем и делим на нечетное число}
          end;
       writeln('    |', x:6:2, ' |', s:8:4, ' |', n:5, '|');
       x := x + h;
      end;
     writeln('    -------------------------');
     readln
end.