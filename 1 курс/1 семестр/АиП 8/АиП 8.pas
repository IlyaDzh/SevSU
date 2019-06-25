Uses Crt;
type
  Zap = Record  {Описание  записи о студенте}
    Fam: string[13];
    Imya: string[10];
    Otch: string[13];
    Mat: string[3]; 
    Ist: string[3];
    Fiz: string[3];
  End;
  TreePtr = ^Tree;{Описание узла дерева}
  Tree = Record 
    Data: Zap;
    Left, Right: TreePtr;                
  End;

var
  Top, p1: Treeptr;
  Z: Zap;
  i: Integer;
  x: string;
  Number: Integer;

function AddTree(Top: TreePtr; Newnode: Zap): TreePtr;
begin
  if Top = nil THEN {Если дерево пустое то создаём его корень}
  begin
    New(Top); {Выделяем память}
    Top^.Data := Newnode; {Добавляем данные}
    Top^.Left := nil; {Зануляем указатели левого}
    Top^.Right := nil; {Зануляем указатели правого}
  end
  ELSE
  if Top^.Data.Fam > Newnode.Fam Then Top^.Left := AddTree(Top^.Left, Newnode) {если меньше корня то в левое поддерево}
  Else Top^.Right := AddTree(Top^.Right, Newnode); {если больше корня то в правое поддерево}
  Addtree := Top
end;

procedure OrgTree;
begin
  Writeln('Выполняется процедура организации дерева');
  Writeln('Для выхода из процедуры вводите символ * ');
  Writeln('======================================== ');
  Top := nil;
  while True Do 
  begin
    Writeln('Введите фамилию:');
    Readln(Z.Fam);
    Writeln('Введите имя:');
    Readln(Z.Imya);
    Writeln('Введите отчество:');
    Readln(Z.Otch);
    Writeln('Введите оценку по Математике:');
    Readln(Z.Mat);
    Writeln('Введите оценку по Истории:');
    Readln(Z.Ist);
    Writeln('Введите оценку по Физике:');
    Readln(Z.Fiz);
    Writeln('======================================== ');
    if Z.Fam = '*' Then Exit;
    Top := Addtree(Top, Z); 
  end
end;

procedure Prosmotr(Top: TreePtr);{Просмотр узлом слева на право}
begin
  if Top <> nil Then
  begin
    Prosmotr(Top^.Left);
    Writeln(i, ' ', Top^.Data.Fam, ' ', Top^.Data.Imya, ' ', Top^.Data.Otch, ' ', Top^.Data.Mat, ' ', Top^.Data.Ist, ' ', Top^.Data.Fiz);
    i := i + 1;
    Prosmotr(Top^.Right)
  end; 
end;

procedure Otobr(top: TreePtr; Otstup: Integer);{Вывод дерева}
var
  i: Integer;
begin
  if Top <> nil Then
  begin
    Otobr(Top^.Right, otstup + 4);
    for i := 1 To otstup Do Write(' ');
    Writeln(Top^.Data.Fam);
    Otobr(Top^.Left, otstup + 4);
  end;
end;

function Search(Top: Treeptr; x: string): Treeptr;
var
  p: Treeptr;
begin
  if Top = nil then
  begin
    Search := nil; 
    exit;
  end;
  if x = Top^.Data.Fam then  {если искомый элемент равен корню дерева то }
    p := Top  {запоминаем его адрес }
     else
  if x < Top^.Data.Fam then
    p := Search(Top^.Left, x) {то ищем его в левом поддереве}
  else 
    p := Search(Top^.Right, x);  {ищем в правом поддереве }
  Search := p; {присваеваем переменной с именем функции результат работы}
end;

{==============основная программа================}

begin
  repeat
    ClrScr;
    Writeln('1-Создание дерева');
    Writeln('2-Вывод дерева');
    Writeln('3-Поиск по Фамилии');
    Writeln('4-Выход');
    Writeln('-------------------------------');
    Writeln('Введите номер пункта меню');
    Readln(Number);
    case Number Of
      1: OrgTree;
      2:
        begin
          Writeln('Выполняется процедура просмотра дерева');
          Writeln('======================================== ');
          i := 0;
          Prosmotr(Top);
          Otobr(Top, 1);
          Writeln('Нажмите клавишу Enter');
          Readln
        end;
      3:
        begin
          Writeln('Введите элемент для поиска:');
          Readln(x);
          p1 := Search(Top, x);
          if p1 <> nil then
            Writeln('Найден.')
          else Writeln('Такого элемента нет.');
          Readkey;
        end;
    End; 
  until Number = 4;
end.