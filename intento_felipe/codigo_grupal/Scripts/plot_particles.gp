set g
set ls 1 lc rgb 'blue' pt 7 ps 0.5

latticesize = int(system("sed -n 3p Data/init_data.txt | tr -d -c 0-9"))
gridsize = int(system("sed -n 2p Data/init_data.txt | tr -d -c 0-9"))

bord = latticesize*0.5
ran = bord*1.25

set xr [-ran:ran]
set yr [-ran:ran]
set xtics latticesize/gridsize
set ytics latticesize/gridsize
set xl 'Eje x'
set yl 'Eje y'
set term pdf

set size square
set obj 1 rect from -bord,-bord to bord,bord lw 3 fs empty border lc rgb 'red'

set title 'Inicio'
set o "Data/particles_start.pdf"
p 'Data/data_particles_start.txt' w p ls 1 t 'Partículas'


set title 'Final'
set o "Data/particles_end.pdf"
p 'Data/data_particles_end.txt' w p ls 1 t 'Partículas'
