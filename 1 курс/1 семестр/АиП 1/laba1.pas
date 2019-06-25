Var a,b,x,z:real;
flag:boolean;
Begin
  Writeln('Введите a');
  Readln(a);
  Writeln('Введите x');
  Readln(x);
  Writeln('Введите b');
  Readln(b);
  
  flag:=true;
  if x<=a then z:=sin(abs(x))
  else if x>=b then
    begin
      if cos(exp(x))<>0 then z:=tan(exp(x))
      else
        begin
          Writeln('Не входит в ОДЗ');
          flag:=false;
        end;
    end
       else z:=cos(abs(x));
  
  if flag then writeln('Для x=',x,' значение функции z=',z:2:2);
  Writeln('Нажмите <Enter>'); Readln
  End.
        