set grid
set style line 2 lc rgb "#0060ad" lt 1 lw 1 pt 7 ps 0.5

set xrange [0:*]
set yrange [0:6]
set title 'Entropia'
set xlabel 'Iteraciones'
set ylabel 'Entropia'

set term pdf
set out "data/entropy.pdf"

plot 'data/data_entropy.txt' u 1:2 w l ls 2 t 'Entropia'
