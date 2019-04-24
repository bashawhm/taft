(* TEST COMMENT *)
program main(input, output);

    var a,b: integer;
    var x,y,z: real;

    (*
    
    MULTILINE TEST COMMENT
    *)

    procedure bar(i: real);
    begin
    end;

    function baz : integer;
        var t: real;
        var x: array [0..20] of real;
    begin
        t := 25.5;
        x[5] := x[9] + x[10];
        bar(x[2])
    end;

    function foo( b: integer) : integer;
        var x: real;
        procedure bar2(b: real);
        begin
            z := 2.718 
        end;
    begin
        x := 3.14;
        bar(1.1);
        foo := 2*b
    end;

    procedure boo( p: integer; q: real; r: integer; s: integer);
        var a: real;
        var z: integer;
        begin
            x := 3.15; 
            writeln(p+13);
            writeln(p+13);
            writeln(42)
        end;

begin
    a := 0;
    b := 0;
    boo( foo(13), 3.14, 4, a);
    writeln(51);
    if a = 0 then
        a := 5
    else
        a := 7
end.
