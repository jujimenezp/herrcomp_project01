set g
set ls 1 lc rgb "red" lt 1 lw 1
set ls 2 lc rgb "black" lt 1 lw 1
set ls 3 lc rgb "blue" lt 1 lw 2
set ls 4 lc rgb "green" lt 1 lw 2

set xr []
set yr []
set title 'Tiempo vs Número de partículas'
set xl 'Número de partículas'
set yl 'Tiempo (s)'
set term pdf

set o "Data/for_auto_1.pdf"
p "Data/data_for_auto_1.txt" u 1:2:4 with errorbars ls 1 t "Normal(-O3)", "Data/for_auto_1.txt" u 1:3:5 with errorbars ls 2 t "Auto(-O3)"

set o "Data/for_auto_2.pdf"
p "Data/data_for_auto_2.txt" u 1:2:4 with errorbars ls 3 t "Normal", "Data/for_auto_2.txt" u 1:3:5 with errorbars ls 4 t "Auto"
