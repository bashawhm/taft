program main(input, output);
    var in, x1, x2, next, i: integer;
begin
    x1 := 0;
    x2 := 1;
    read(in);
    writeln(0);
    writeln(1);
    for i := 2; i < in; i := i + 1 do
    begin
        next := x1 + x2;
        x1 := x2;
        x2 := next;
        writeln(next)
    end
end.