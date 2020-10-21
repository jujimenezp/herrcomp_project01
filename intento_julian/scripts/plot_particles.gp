set grid
set style line 1 lc rgb '#0060ad' pt 7 ps 0.5

bord = int(system("sed -n 2p data/init_data.txt | tr -d -c 0-9"))*0.5
ti = int(system("sed -n 5p data/init_data.txt | tr -d -c 0-9"))

set xtics ti
set ytics ti

set object 1 rect from -bord,-bord to bord,bord lw 3 fs empty border lc rgb 'red'

ran=bord*(1.1)
set xrange [-ran:ran]
set yrange [-ran:ran]


set title 'Inicio'
set xlabel 'Eje x'
set ylabel 'Eje y'
set term pdf
set out "data/particles_start.pdf"
plot 'data/data_particles_start.txt' u 1:2 w p ls 1 t 'Particulas'


set title 'Final'
set out "data/particles_end.pdf"
plot 'data/data_particles_end.txt' u 1:2 w p ls 1 t 'Particulas'

