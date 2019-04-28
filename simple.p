program main(input, output);
    var x: integer;
begin
    read(x);
    while x > 0 do
    begin
        writeln(x);
        x := x - 1
    end;
    writeln(x)
end.