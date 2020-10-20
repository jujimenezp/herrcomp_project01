set xrange [0:10000000]
set yrange [0:5]
set grid
set term pdf 
set out "entropy_time.pdf"
plot 'entropy_time.txt' w l ls -1 lc rgb 'black'
