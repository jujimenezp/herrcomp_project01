set grid
set style line 1 lc rgb "blue" lt 1 lw 1 pt 7 ps 0.5
set style line 2 lc rgb "red" lt 1 lw 1 pt 7 ps 0.5

set xrange [0:*]
set yrange [0:*]
set title 'Steadying time vs Lattice size'
set xlabel 'Lattice size'
set ylabel 'Steadying time'

f(x) = A*x**B
A=15
B=2
fit f(x) "Data/data_stability.txt" u 1:2:3 yerrors via A, B

set term pdf
set out "Data/stability.pdf"
plot "Data/data_stability.txt" u 1:2:3 with errorbars ls 1 t "Steadying time", f(x) w l ls 2 t 'Fit'
