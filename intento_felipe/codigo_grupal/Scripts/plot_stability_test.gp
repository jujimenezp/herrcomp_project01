set g
set ls 1 lc rgb "blue" lt 1 lw 1 pt 7 ps 0.5
set ls 2 lc rgb "red" lt 1 lw 1 pt 7 ps 0.5
set ls 3 lc rgb "black" lt 1 lw 1 pt 1 ps 1

nmolecules = int(system("sed -n 1p Data/init_data.txt | tr -d -c 0-9"))
gridsize = int(system("sed -n 2p Data/init_data.txt | tr -d -c 0-9"))**2
latticesize = int(system("sed -n 3p Data/init_data.txt | tr -d -c 0-9"))

set xr []
set xl 'Iteraciones'
set k t l
set term pdf

Init = sprintf(" {/:Bold Parámetros iniciales} \n Número de partículas = %i \n Tamaño de la taza = %i \n Cantidad de celdas = %i", nmolecules, latticesize, gridsize)

set obj 1 rect from graph 1, 1 to graph 0.64, 0.76 fc rgb "white"
set lab 1 Init at graph 0.64, 0.96

set o 'Data/stability_v1.pdf'
set title 'Diferencial porcentual vs Iteraciones'
set yr [0:0.01]
set yl 'Diferencia porcentual'
p 'Data/data_stability_v1.txt' ls 1 t 'Diferencia porcentual'

set o 'Data/stability_v21.pdf'
set title 'Desviaciones vs Iteraciones'
set yr [0:0.01]
set yl 'Desviación'
p 'Data/data_stability_v2.txt' u 1:2 ls 1 t 'Desviación distribución

set o 'Data/stability_v22.pdf'
set title 'Desviaciones vs Iteraciones'
set yr [0:0.04]
set yl 'Desviación'
p 'Data/data_stability_v2.txt' u 1:3 ls 2 t 'Desviación fit'

set obj 1 rect from graph 0, 1 to graph 0.36, 0.76 fc rgb "white"
set lab 1 Init at graph 0, 0.96

set o 'Data/stability_v23.pdf'
set title 'Contadores vs Iteraciones'
set yr [0:*]
set yl 'Contador'
set k b r
p 'Data/data_stability_v2.txt' u 1:4 ls 1 t 'Contador distribución', 'Data/data_stability_v2.txt' u 1:5 ls 2 t 'Contador fit', 'Data/data_stability_v2.txt' u 1:6 ls 3 t 'Contador conjunto'
