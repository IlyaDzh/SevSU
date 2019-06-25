Uses Crt;
Type
  aeroflot = record  {записи рейсов}
             Pynkt: string[15];  {Пункт назначения}
             Numb: integer;  {Номер рейса}
             Tip: string[15];  {Тип самолета} 
             End;
Var
  f: file of aeroflot;
  Elem1, Elem2: aeroflot;
  number: integer;

      {Создание файла}
procedure Create_file;
begin
  Seek(f, FileSize(f));
  Writeln('Вводите сведения о рейсах');
  Writeln('Для выхода вместо названия пункта назначения напечатайте символ *');
  Writeln('----------------------------------------------------------------');
  while True Do
  begin
    Write('Введите название пункта назначения рейса: '); 
    Readln(Elem1.Pynkt); 
    if Elem1.Pynkt = '*' Then Break;
    Write('Введите номер рейса: '); 
    Readln(Elem1.Numb); 
    Write('Введите тип самолета: '); 
    Readln(Elem1.Tip);  
    Writeln('-----------------------');
    Write(f, Elem1)
  end
end;

      {Сортировка по пункту назначения}
procedure Sort_file;
var
  i, j: integer;
begin
  Seek(f, 0);
  for i := filesize(f) - 1 downto 1 do
    for j := 0 to i - 1 do
    begin
      Seek(f, j);
      Read(f, Elem1, Elem2);
      if Elem1.Pynkt > Elem2.Pynkt then
      begin
        Seek(f, j);
        Write(f, Elem2, Elem1);
      end
    end
end;

      {Вывод файла}
procedure Print_file;
begin
  Seek(f, 0);
  Writeln('Пункты назначения ':20, '| ', 'Номер рейса':5, ' |', 'Тип самолета':13);
  Writeln('  ----------------------------------------------');
  while not eof(f) do
  begin
    Read(f, Elem1);
    Writeln(Elem1.Pynkt:20, '| ', Elem1.Numb:11, ' |', Elem1.Tip:13);
  end;
  Readkey;
end;

      {Поиск информации по типу самолёта}
procedure Search_tip;
var
  Found: boolean;
  S_tip: string[15];  {Строка с типом}
  a: aeroflot;
begin
  write('Введите тип самолёта: ');
  read(S_tip);
  assign(f, 'aeroflot.txt');
  reset(f);
  Found:= false;
  writeln('  Пункт назначения | Номер рейса');
  Writeln('  ------------------------------');
  while not eof(f) do
  begin
    read(f, a);
    with a do
      if a.tip = S_tip then
      begin
        write(a.pynkt:18);
        writeln(' | ', a.numb:11);
        Found:= true;
      end;
  end;
  if not Found then write('Самолётов данного типа не найдено.');
  Readkey;
end;

      {Основная программа}
Begin
  Assign(f, 'aeroflot.txt');
  {$I-}
  Reset(f);
  {$I+}
  Rewrite(f);
  while True Do 
  begin
    ClrScr;
    Writeln('1-Создание файла');
    Writeln('2-Сортировка файла по пункту назначения');
    Writeln('3-Вывод содержимого файла');
    Writeln('4-Поиск информации по типу самолёта');
    Writeln('5-Выход');
    Writeln('-------------------------------');
    Writeln('Введите номер пункта меню:');
    Readln(Number);
    case Number Of
      1: Create_file;  {Создание файла}
      2: Sort_file;  {Сортировка файла}
      3: Print_file;  {Просмотр файла}
      4: Search_tip;  {Поиск по типу самолёта}
      5: Exit  {Выход из файла} 
    end
  end; 
End.