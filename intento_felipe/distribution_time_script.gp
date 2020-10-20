set xrange [-120:120]
set yrange [-120:120]
set grid
set term pdf 
set out "distribution_time.pdf"
plot 'distribution_time.txt' w p pt 7 ps 1 lc rgb 'black'
