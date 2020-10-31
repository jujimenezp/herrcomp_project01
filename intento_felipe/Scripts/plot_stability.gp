set grid
set style line 1 lc rgb "blue" lt 1 lw 1

set xrange [0:*]
set yrange [0:*]
set title 'Steadying time vs Lattice size'
set xlabel 'Lattice size'
set ylabel 'Steadying time'

set term pdf
set out "Data/stability.pdf"
plot "Data/data_stability.txt" u 1:2:3 with errorbars ls 1 t "Steadying time"
