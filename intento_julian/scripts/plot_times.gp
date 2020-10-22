set grid
set style line 1 lc rgb '#0060ad lw 0.5
set title 'Time vs Particles'
set xlabel 'Particles number'
set ylabel 'Computing time (s)'

set term pdf
set out "data/time_particles.pdf"
plot "data/data_compute_N.txt" u 1:2 w l ls 1 t ""

set title 'Time vs Iterations'
set xlabel 'Total iterations'
set ylabel 'Computing time (s)'
set out "data/time_iterations.pdf"
plot "data/data_compute_ite.txt" u 1:2 w l ls 1 t ""
