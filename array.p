program main(input, output);
    var a: array [0 .. 5] of integer;
    var i: integer;
begin
    for i := 0; i < 5; i := i + 1 do
    begin
        a[i] := i;
        writeln(a[i])
    end
end.