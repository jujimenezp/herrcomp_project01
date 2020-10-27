set grid
set style line 2 lc rgb "#0060ad" lt 1 lw 1 pt 7 ps 0.5

set xrange [0:*]
set yrange [0:*]
set xlabel 'Iterations'
set ylabel 'Entropy'
set term pdf

set title 'Entropy vs Time'
set out 'Data/entropy.pdf'
plot 'Data/data_entropy.txt' w l ls -1 lc rgb 'blue' t 'Entropy'
