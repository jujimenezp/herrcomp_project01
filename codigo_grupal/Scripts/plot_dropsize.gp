set grid
set style line 1 lc rgb "blue" lt 1 lw 1 pt 7 ps 0.5
set style line 2 lc rgb "red" lt 1 lw 1 pt 7 ps 0.5
set style line 3 lc rgb "black" lt 1 lw 1 pt 7 ps 0.5

set title 'Dropsize vs Time'
set xrange [0:*]
set yrange [0:*]
set xlabel 'Iterations'
set ylabel 'Size'
set term pdf

f(x) = A*x**B
A=90
B=0.5
fit f(x) "Data/data_dropsize_1.txt" via A, B

set out 'Data/dropsize.pdf'
plot 'Data/data_dropsize_1.txt' w l ls 1 t 'Drop size before equilibrium', f(x) w l ls 2 t 'Fit', 'Data/data_dropsize_2.txt' w l ls 3 t 'Drop size after equilibrium
