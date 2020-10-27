set grid
set style line 1 lc rgb "red" lt 1 lw 1
set style line 2 lc rgb "black" lt 1 lw 1

set xrange [0:*]
set yrange [0:*]
set title 'Profiling cout vs iostream'
set xlabel 'Iterations'
set ylabel 'Computing time (s)'

set term pdf
set out "../Data/prof_print.pdf"
plot "../Data/prof_print.txt" u 1:2:4 with errorbars ls 1 t "cout", "../Data/prof_print.txt" u 1:3:5 with errorbars ls 2 t "iostream"
