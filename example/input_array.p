program main(input, output);
    var a: array [0 .. 3] of integer;
    var i: integer;
begin
    for i := 0; i < 3; i := i + 1 do
    begin
        read(a[i]);
        writeln(a[i])
    end
end.