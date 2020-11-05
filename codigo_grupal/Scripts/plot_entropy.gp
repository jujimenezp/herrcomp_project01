set g
set ls 1 lc rgb "blue" lt 1 lw 0.5

nmolecules = int(system("sed -n 1p Data/init_data.txt | tr -d -c 0-9"))
gridsize = int(system("sed -n 2p Data/init_data.txt | tr -d -c 0-9"))**2
latticesize = int(system("sed -n 3p Data/init_data.txt | tr -d -c 0-9"))

set xr []
set yr []
set title 'Entropía vs Iteraciones'
set xl 'Iteraciones'
set yl 'Entropía'
set k t l
set term pdf

Init = sprintf(" {/:Bold Parámetros iniciales} \n Número de partículas = %i \n Tamaño de la taza = %i \n Cantidad de celdas = %i", nmolecules, latticesize, gridsize)

set obj 1 rect from graph 1, 0 to graph 0.64, 0.24 fc rgb "white"
set lab 1 Init at graph 0.64, 0.20

set o 'Data/entropy.pdf'
p 'Data/data_entropy.txt' w l ls 1 t 'Entropía'
