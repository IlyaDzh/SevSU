Const n=10;
Var   ar,ar1: array [0..n] of integer; 
      k, x, a, b, i, i1, j, imax, imin: integer; 
      ibeg, iend: integer; 
      sum: real;
Begin     
  writeln ('Введите ', n, ' элементов массива:');
  for i:=1 to n do 
  readln(ar[i]);
  imax:=1;      
  imin:=1;      
  for i:=1 to n do 
     begin 
       if ar[i]>ar[imax] then imax:=i;
       if ar[i]<ar[imin] then imin:=i 
     end; 
  writeln ('Max=', ar[imax], ',' ,' Min=', ar[imin]);
  if imax<imin then ibeg:=imax   
               else ibeg:=imin; 
  if imax<imin then iend:=imin   
               else iend:=imax;  
  writeln ('Ibeg=', ibeg, ',', ' Iend=', iend);
  
  j:=0;
  for i := 1 to n do
   begin
    if ar[i] > 0 then
    j := i;
   end;
  sum:=0; 
  for i:=1 to j-1 do 
  sum:=sum+ar[i];
  writeln('Сумма элементов массива: ', sum);
  
  Writeln('Введите интервал:');
  readln(a,b);
  for i:=1 to n do
         if (a>abs(ar[i]))or(b<abs(ar[i])) then
            begin
                 i1:=i1+1;
                 ar1[i1]:=ar[i];
            end;
     for i:=i1+1 to n do
         ar1[i]:=0;
     for i:=1 to n do
         ar[i]:=ar1[i];
     for i:=1 to n do
         write(ar[i],' ');
         readln;
         
   for i:=2 to n do
    begin 
       x:=ar[i]; 
       ar[0]:=x;
       j:=i; 
       while x<ar[j-1] do  
       begin 
           ar[j]:=ar[j-1]; 
           j:=j-1; 
       end; 
       ar[j]:=x; 
    end;
 writeln('Сортировка:');
for i:=1 to n do
write(ar[i],' ');
end.