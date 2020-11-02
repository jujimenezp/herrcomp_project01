set grid
set style line 1 lc rgb "blue" lt 1 lw 1 pt 7 ps 0.5
set style line 2 lc rgb "red" lt 1 lw 1 pt 7 ps 0.5

set xrange [0:*]
set yrange [0:*]
set xlabel 'Iterations'
set term pdf

f(x) = A*exp(-x/B)
A=int(system("sed -n 1p Data/init_data.txt | tr -d -c 0-9"))
B=5e7
fit f(x) 'Data/data_hole.txt' via A, B

set title 'Number of particles vs Time'
set out 'Data/hole.pdf'
set ylabel 'Number of particles'
plot 'Data/data_hole.txt' w l ls 1 t 'Number of particles', f(x) w l ls 2 t 'Fit'

set title 'Number of particles vs Time (semilog)'
set out 'Data/hole_log.pdf'
set ylabel 'Number of particles (log)'
set log y
plot 'Data/data_hole.txt' w l ls 1 t 'Number of particles', f(x) w l ls 2 t 'Fit'
