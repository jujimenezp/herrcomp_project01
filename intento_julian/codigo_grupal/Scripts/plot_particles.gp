set grid
set style line 1 lc rgb '#0060ad' pt 7 ps 0.5

bord = int(system("sed -n 2p Data/init_data.txt | tr -d -c 0-9"))*0.5
ti = int(system("sed -n 5p Data/init_data.txt | tr -d -c 0-9"))

ran = bord*(1.25)
set xrange [-ran:ran]
set yrange [-ran:ran]
set xtics 2*bord/ti
set ytics 2*bord/ti
set xlabel 'Eje x'
set ylabel 'Eje y'
set term pdf

set size square
set object 1 rect from -bord,-bord to bord,bord lw 3 fs empty border lc rgb 'red'

set title 'Inicio'
set out "Data/particles_start.pdf"
plot 'Data/data_particles_start.txt' w p ls 1 t 'Particulas'


set title 'Final'
set out "Data/particles_end.pdf"
plot 'Data/data_particles_end.txt' w p ls 1 t 'Particulas'
