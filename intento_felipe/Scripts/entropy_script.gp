set xrange [0:*]
set yrange [0:*]
set grid
set xlabel 'Time'
set ylabel 'Entropy'
set term pdf 
set out '../Data/entropy_figure.pdf'
plot '../Data/entropy_data.txt' w l ls -1 lc rgb 'blue' t 'Entropy'
