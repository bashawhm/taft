program main(input, output);
    var x: integer;
    function foo(a: integer): integer;
    begin
        writeln(43);
        foo := 5
    end;
begin
    x := 99+3*47;
    writeln(x);
    x := foo(57);
    writeln(x);
    x := 6+17;
    writeln(x)
end.