set g
set ls 1 lc rgb "black" lt 1 lw 1 pt 1
set ls 2 lc rgb "green" lt 1 lw 1 pt 2
set ls 1 lc rgb "blue" lt 1 lw 1 pt 5
set ls 2 lc rgb "red" lt 1 lw 1 pt 6

nmolecules = int(system("sed -n 1p ../Data/init_data.txt | tr -d -c 0-9"))

set xr []
set yr []
set title 'Tiempo de computo vs Tiempo de estabilización'
set xl 'Tiempo de estabilización'
set yl 'Tiempo de computo'
set k b r
set term pdf

Init = sprintf(" {/:Bold Parámetros iniciales} \n Número de partículas = %i", nmolecules)

set obj 1 rect from graph 0, 1 to graph 0.36, 0.86 fc rgb "white"
set lab 1 Init at graph 0, 0.96

set o "Data/stability.pdf"
p "Data/data_stability_0.txt" ls 1 t "O-0", "Data/data_stability_1.txt" ls 2 t "O-1", "Data/data_stability_2.txt" ls 3 t "O-2", "Data/data_stability_3.txt" ls 4 t "O-3"
