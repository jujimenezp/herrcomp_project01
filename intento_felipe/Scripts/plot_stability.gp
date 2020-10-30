set grid
set style line 2 lc rgb "#0060ad" lt 1 lw 1 pt 7 ps 0.5

set xrange [0:*]
set yrange [0:*]
set xlabel 'Iterations'
set ylabel 'Entropy'
set term pdf

set out 'Data/stability.pdf'
set title 'Correlation vs Time'
plot 'Data/data_stability.txt' u 1:2 ls 2 t 'Correlation'
set title 'Slope vs Time'
plot 'Data/data_stability.txt' u 1:3 ls 2 t 'Slope'
set title 'Entropy vs Time'
plot 'Data/data_stability.txt' u 1:4 ls 2 t 'Entropy'
