program main(input,output);
 var a,b,c: integer;
 var x,y,z: real;
 var p: array[3 .. 11] of integer;
 function foo(c:integer):integer;
   var b: integer;
 begin
   b := (13+1)*(13-1)+1; 
   foo := b
 end;    
 function moo:integer;
 begin
   moo := 1  
 end;    
begin
 read(a);
 b := foo(p[3]);
 write(b)       
end.
