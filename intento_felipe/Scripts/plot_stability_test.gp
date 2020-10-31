set grid
set style line 1 lc rgb "#0060ad" lt 1 lw 1 pt 7 ps 0.5
set style line 2 lc rgb "red" lt 1 lw 1 pt 7 ps 0.5
set style line 3 lc rgb "black" lt 1 lw 1 pt 1 ps 1

set xrange [0:*]
set xlabel 'Iterations'
set term pdf

set out 'Data/stability_test.pdf'

set title 'Slope vs Time'
set yrange [0:*]
set ylabel 'Slope'
plot 'Data/data_stability_test.txt' u 1:2 ls 1 t 'Slope'


set title 'Deviation vs Time'
set yrange [0:*]
set ylabel 'Deviation'
plot 'Data/data_stability_test.txt' u 1:3 ls 1 t 'Deviation'

set title 'Counter vs Time'
set yrange [0:*]
set ylabel 'Counter'
plot 'Data/data_stability_test.txt' u 1:4 ls 1 t 'Counter slope', 'Data/data_stability.txt' u 1:5 ls 2 t 'Counter deviation', 'Data/data_stability.txt' u 1:6 ls 3 t 'Counter'
