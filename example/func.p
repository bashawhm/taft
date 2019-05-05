program main(input, output);
    var a: integer;
    function bar: integer;
    begin
        bar := 5
    end;
    function foo(b: integer): integer;
        var a: integer;
    begin
        a := bar();
        foo := 12 + a * 2
    end;
begin
    a := foo(5);
    writeln(a)
end.