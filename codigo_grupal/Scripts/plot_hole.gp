set grid
set style line 2 lc rgb "#0060ad" lt 1 lw 1 pt 7 ps 0.5

set xrange [0:*]
set yrange [0:*]
set xlabel 'Iterations'
set term pdf
set out 'Data/hole.pdf'

set title 'Number of particles vs Time'
set ylabel 'Number of particles'
plot 'Data/data_hole.txt' w l ls -1 lc rgb 'blue' t 'Number of particles'

set title 'Number of particles vs Time (semilog)'
set ylabel 'Number of particles (log)'
set log y
plot 'Data/data_hole.txt' w l ls -1 lc rgb 'blue' t 'Number of particles'
