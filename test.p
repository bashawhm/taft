(* TEST COMMENT *)
program main(input, output);

    var a,b: integer;
    var x,y,z: real;

    (*
    
    MULTILINE TEST COMMENT
    *)

    function foo( b: integer) : integer;
        var x: real;
        procedure bar(b: real);
        begin
            z := 2.718 
        end;
    begin
        x := 3.14; 
        bar(1.1);
        foo := 2*b
    end;

    procedure boo( p: integer; q: real; r: integer);
        var a: real;
        var z: integer;
        begin
            x := 3.15; 
            writeln(p+13);
            writeln(p+13)
        end;

begin
    a := 0;
    boo( foo(13), 3.14, 4)
end.
