Const n=3;
Type matrix=array[1..n,1..n] of Integer; 
     vector=array[1..n] of LongInt; 
Var a:matrix;        
    v:vector; 
    
{ïğîöåäóğà ââîäà èñõîäíîé ìàòğèöû} 
Procedure Vvod (Var a:matrix); 
Var i, j: Integer; 
Begin   
  Writeln('Ââåäèòå ıëåìåíòû ìàññèâà:'); 
  For i:=1 to n do    
    For j:=1 to n do 
      Readln(a[i,j]); 
End; 

{ïğîöåäóğà âû÷èñëåíèÿ ñóììû ıëåìåíòîâ ñòîëáöîâ} 
Procedure SummaStolb(Const a:matrix; Var v:vector); 
Var i, j: Integer; 
Begin   
  For j:=1 to n do    
    Begin 
      v[j]:=0;   
      For i:=1 to n do
        begin
        if (a[i,j]>0) then v[j]:=v[j]+a[i,j]
                      else 
                        begin
                          v[j]:=0;
                          v[j]:=v[j]*a[i,j];
                        end;
        end;
    End; 
End;

{ïğîöåäóğà âûâîäà ìàòğèöû}
Procedure Vyvod (Const a:matrix; Const v:vector); 
Var i, j:Integer; 
Begin   
  For i:=1 to n do     
    Begin       
      For j:=1 to n do 
        Write(a[i,j], ' '); 
        Writeln; 
    End;   
  For i:=1 to n do 
    Write('Ñóììà:',v[i], ' '); 
    Writeln; 
End;

{ïğîöåäóğà âû÷èñëåíèÿ ìèíèìàëüíîé ñóììû ìîäóëåé íà äàèãîíàëÿõ, ïàğàëëåëüíûõ ïîáî÷íîé äèàãîíàëè}
procedure min(a:matrix; n:integer);
var i,j,l,sum, mn:integer;
begin
mn:=abs(a[1,1]);
for i:=n-1 downto -n+1 do
 begin
  sum:=0;
  for j:=1 to n do
    if (j-i>0) and (j-i<=n) then sum:=sum+abs(a[j-i,n-j+1]);
  if sum<mn then mn:=sum;
 end;
writeln('Ìèíèìàëüíàÿ ñóììà ìîäóëåé íà äèàãîíàëÿõ, ïàğàëëåëüíûõ ïîáî÷íîé=',mn);
end;

Begin
  Vvod(a); {ââîä ìàòğèöû} 
  SummaStolb(a,v); {âû÷èñëåíèå ñóììû ıëåìåíòîâ ñòîëáöîâ} 
  Vyvod(a,v); {âûâîä ìàòğèöû}
  Min(a,n); {âû÷èñëåíèÿ ìèíèìàëüíîé ñóììû ìîäóëåé íà äèàãîíàëÿõ, ïàğàëëåëüíûõ ïîáî÷íîé äèàãîíàëè}
End.