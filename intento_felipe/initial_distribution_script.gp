set xrange [-200:200]
set yrange [-200:200]
set grid
set term pdf 
set out "initial_distribution.pdf"
plot 'test_init_particles.txt' w p pt 7 ps 1 lc rgb 'black'
