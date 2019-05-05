program main(input, output);
    var x, i: integer;
begin
    i := 0;
    read(x);
    while i < 2*x do
    begin
        if i < x then
            writeln(i)
        else
            writeln(x);
        i := i + 1
    end
end.