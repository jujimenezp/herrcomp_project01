set g
set ls 1 lc rgb "blue" lt 1 lw 1

nmolecules = int(system("sed -n 1p Data/init_data.txt | tr -d -c 0-9"))
gridsize = int(system("sed -n 2p Data/init_data.txt | tr -d -c 0-9"))**2
latticesize = int(system("sed -n 3p Data/init_data.txt | tr -d -c 0-9"))

set xr []
set yr []
set title 'Entropía vs Iteraciones'
set xl 'Iteraciones'
set yl 'Entropía'
set k b r
set term pdf

Init = sprintf(" {/:Bold Parámetros iniciales} \n Número de partículas = %i \n Tamaño de la taza = %i \n Cantidad de celdas = %i", nmolecules, latticesize, gridsize)

set obj 1 rect from graph 0, 1 to graph 0.36, 0.7 fc rgb "white"
set lab 1 Init at graph 0, 0.96

set o 'Data/entropy.pdf'
p 'Data/data_entropy.txt' w l ls 1 t 'Entropía'
