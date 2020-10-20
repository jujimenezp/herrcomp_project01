set grid
set style line 1 lc rgb '#0060ad' pt 7 ps 0.5
set style line 2 lc rgb "#0060ad" lt 1 lw 1 pt 7 ps 0.5
set xrange [-110:110]
set yrange [-110:110]
set size square

set title 'Inicio'
set xlabel 'Eje x'
set ylabel 'Eje y'
set term pdf
set out "particles_start.pdf"
plot 'data_particles_start.txt' u 1:2 w p ls 1 t 'Particulas'


set title 'Final'
set out "particles_end.pdf"
plot 'data_particles_end.txt' u 1:2 w p ls 1 t 'Particulas'

set xrange [0:*]
set yrange [0:5]
set title 'Entropia'
set xlabel 'Iteraciones'
set ylabel 'Entropia'
set out "entropy.pdf"
plot 'data_entropy.txt' u 1:2 w l ls 2 t 'Entropia'
