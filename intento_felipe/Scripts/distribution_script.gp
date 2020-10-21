set xrange [-125:125]
set yrange [-125:125]
set xtics 25
set ytics 25
set grid
set size square
set object 1 rect from -100,-100 to 100,100 lw 3 fs empty border lc rgb 'red'
set term pdf
set out '../Data/distribution_figure.pdf'
plot '../Data/distribution_data.txt' w p pt 7 ps 0.5 lc rgb 'black' t 'Particles'