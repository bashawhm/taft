program main(input, output);
    var a: integer;
    var b: real;

    function foo(d: integer): integer;
        var c: real;
    begin
        c := 3.14;
        foo := c
    end;

begin
    a := 12;
    b := foo(a)
end.