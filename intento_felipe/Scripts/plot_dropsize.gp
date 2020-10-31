set grid
set style line 1 lc rgb "red" lt 1 lw 1 pt 7 ps 0.5
set style line 2 lc rgb "blue" lt 1 lw 1 pt 7 ps 0.5

set title 'Dropsize vs Time'
set xrange [0:*]
set yrange [0:*]
set xlabel 'Iterations'
set ylabel 'Size'
set term pdf

set out 'Data/dropsize.pdf'
plot 'Data/data_dropsize_1.txt' w l ls 1 t 'Drop size before equilibrium', 'Data/data_dropsize_2.txt' w l ls 2 t 'Drop size after equilibrium'
