Uses Crt;
type
  Zap = Record  {Описание  записи о грузополучателе}
    FIO: string[15];
    Adr: string[30];              
  End;
  TreePtr = ^Tree;{Описание узла дерева}
  Tree = Record 
    Data: Zap;
    Left, Right: TreePtr;                
  End;

var
  Top: Treeptr;
  Z: Zap;
  Level, N, i: Integer;
  Number: Integer;

function AddTree(Top: TreePtr; Newnode: Zap): TreePtr;
begin
  if Top = nil THEN 
  begin
    New(Top);
    Top^.Data := Newnode;
    Top^.Left := nil;
    Top^.Right := nil; 
  end
  ELSE
  if Top^.Data.Fio > Newnode.Fio Then Top^.Left := AddTree(Top^.Left, Newnode)
  Else Top^.Right := AddTree(Top^.Right, Newnode);
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
    Writeln('Введите фамилию и инициалы грузополучателя');
    Readln(Z.Fio);
    Writeln('Введите адрес грузополучателя');
    Readln(Z.Adr);
    if Z.Fio = '*' Then Exit;
    Top := Addtree(Top, Z); 
  end
end;

procedure DobL;
begin
  Writeln('Выполняется процедура добавления листа');
  Writeln('Для выхода из процедуры вводите символ * ');
  Writeln('======================================== ');
  Writeln('Введите фамилию и инициалы грузополучателя');
  Readln(Z.Fio);
  Writeln('Введите адрес грузополучателя');
  Readln(Z.Adr);
  if Z.Fio = '*' Then Exit;
  Top := Addtree(Top, Z); 
end;

procedure Prosmotr(Top: TreePtr);{Процедура просмотра значений узлов дерева слева направо}
begin
  if Top <> nil Then 
  begin
    Prosmotr(Top^.Left);
    Writeln(i, ' ', Top^.Data.Fio, ' ', Top^.Data.Adr);
    i := i + 1;
    Prosmotr(Top^.Right)
  end; 
end;

procedure Otobr(Top: TreePtr; Otstup: Integer);{Процедура отображения структуры дерева.       
Дерево отображается повернутым на 90 градусов против часовой стрелки. 
Узлы дерева, находящиеся на одном уровне, отображаются с  одинаковым отступом от края экрана.}
begin
  if Top <> nil Then 
  begin
    Otstup := Otstup + 3;
    Otobr(Top^.Right, Otstup);
    Writeln(' ':Otstup, Top^.Data.Fio);
    Otobr(Top^.Left, Otstup); 
  end
end;

procedure NodeCount(Top: TreePtr; Level: Integer; var N: Integer);{Процедура подсчета количества вершин уровня Level}
begin
  if (Level >= 1) and (Top <> nil) Then 
  begin
    if Level = 1 Then N := N + 1;
    NodeCount(Top^.Left, Level - 1, N);
    NodeCount(Top^.Right, Level - 1, N); 
  end
end;

{==============основная программа================}

begin
  repeat
    ClrScr;
    Writeln('1-Организация двоичного дерева');
    Writeln('2-Добавление листа к дереву');
    Writeln('3-Просмотр дерева');
    Writeln('4-Подсчет количества вершин на n-oм уровне');
    Writeln('5-Выход');
    Writeln('-------------------------------');
    Writeln('Введите номер пункта меню');
    Readln(Number);
    case Number Of
      1: OrgTree;
      2: Dobl;
      3:
        begin
          Writeln('Выполняется процедура просмотра дерева');
          Writeln('======================================== ');
          i := 0;
          Prosmotr(Top);
          Otobr(Top, 1);
          Writeln('Нажмите клавишу Enter');
          Readln
        end;
      4:
        begin
          Writeln('Выполняется процедура подсчета количества');
          Writeln('вершин на n-ом уровне');
          Writeln('======================================== ');
          Write('Введите значение уровня-->');
          Read(Level);
          N := 0;
          NodeCount(Top, Level, N);
          Writeln;
          Writeln('На уровне ', Level, ' находится ', N, ' вершин');
          Writeln('Нажмите клавишу Enter');
          ReadKey
        end;
    End; 
  until Number = 5; {выход из цикла, если введено 5}
end.