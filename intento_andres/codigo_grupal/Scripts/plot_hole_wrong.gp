set g
set ls 1 lc rgb "blue" lt 1 lw 1
set ls 2 lc rgb "red" lt 1 lw 1

nmolecules = int(system("sed -n 1p Data/init_data.txt | tr -d -c 0-9"))
latticesize = int(system("sed -n 3p Data/init_data.txt | tr -d -c 0-9"))
holesize = latticesize/5

set xr []
set yr []
set title 'Número de partículas vs Iteraciones'
set xl 'Iteraciones'
set yl 'Número de partículas'
set k t r
set term pdf

f(x) = A*exp(-x/B)
A = nmolecules
B = 1.15e8
set fit errorvar
set fit quiet
fit f(x) 'Data/data_hole.txt' via A, B

Init = sprintf(" {/:Bold Parámetros iniciales} \n Número de partículas = %i \n Tamaño de la taza = %i \n Tamaño del hueco = %i", nmolecules, latticesize, holesize)
Fit = sprintf(" {/:Bold Parámetros de regresión} \n y = ae^{-x/b} \n a = %g +/- %g \n b = %g +/- %g", A, A_err, B, B_err)

set obj 1 rect from graph 0, 0.25 to graph 0.35, 0.5 fc rgb "white" 
set lab 1 Init at graph 0, 0.45

set obj 2 rect from graph 0, 0 to graph 0.35, 0.25 fc rgb "white" 
set lab 2 Fit at graph 0, 0.2

set o 'Data/hole_wrong.pdf'
plot 'Data/data_hole_wrong.txt' w l ls 1 t 'Número de partículas', f(x) w l ls 2 t 'Fit'

set log y
set xr []
set yr []

set o 'Data/hole_wrong_log.pdf'
rep
