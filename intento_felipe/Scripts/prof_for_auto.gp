set grid
set style line 1 lc rgb "red" lt 1 lw 1
set style line 2 lc rgb "black" lt 1 lw 1
set style line 3 lc rgb "blue" lt 1 lw 2
set style line 4 lc rgb "green" lt 1 lw 2

set xrange [0:*]
set yrange [0:*]
set title 'Time vs Particles'
set xlabel 'Number of particles'
set ylabel 'Computing time (s)'

set term pdf
set out "../Data/prof_for_auto.pdf"
plot "../Data/prof_for_auto_1.txt" u 1:2:4 with errorbars ls 1 t "Normal(-O3)", "../Data/prof_for_auto_1.txt" u 1:3:5 with errorbars ls 2 t "Auto(-O3)"
plot "../Data/prof_for_auto_2.txt" u 1:2:4 with errorbars ls 3 t "Normal", "../Data/prof_for_auto_2.txt" u 1:3:5 with errorbars ls 4 t "Auto"
