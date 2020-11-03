set grid
set style line 1 lc rgb "blue" lt 1 lw 1 pt 7 ps 0.5
set style line 2 lc rgb "red" lt 1 lw 1 pt 7 ps 0.5

nmolecules = int(system("sed -n 1p Data/init_data.txt | tr -d -c 0-9"))
gridsize = int(system("sed -n 2p Data/init_data.txt | tr -d -c 0-9"))
latticesize = int(system("sed -n 3p Data/init_data.txt | tr -d -c 0-9"))
seed = int(system("sed -n 5p Data/init_data.txt | tr -d -c 0-9"))
resolution = int(system("sed -n 6p Data/init_data.txt | tr -d -c 0-9"))
holesize = latticesize/5

set xrange [0:*]
set yrange [10:*]
set title 'Número de particulas vs Iteraciones'
set xlabel 'Iteraciones'
set ylabel 'Número de particulas'
set term pdf

f(x) = A*exp(-x/B)
A = nmolecules
B = 5e7
set fit errorvariables
set fit quiet
fit f(x) 'Data/data_hole.txt' via A, B

Init = sprintf("Parametros iniciales\nNúmero de moleculas = %i\nNúmero de celdas = %i\nTamaño de la taza = %i\nSemilla = %i\nResolución = %i\nTamaño del hueco = %i", nmolecules, gridsize, latticesize, seed, resolution, holesize)
Fit = sprintf("Parametros de regresión\ny = ae^{-x/b}\na = %f +/- %f\nb = %e +/- %e", A, A_err, B, B_err)

set object 1 rect from 6e7, 300 to 1e8, 150 fc rgb "white" 
set label 1 at 6e7, 290 Init

set object 2 rect from 0, 100 to 5.5e7, 0 fc rgb "white" 
set label 2 at 1e6, 90 Fit

set out 'Data/hole.pdf'
plot 'Data/data_hole.txt' w l ls 1 t 'Number of particles', f(x) w l ls 2 t 'Fit'

set log y

unset object 1
unset label 1
unset object 2
unset label 2

set object 3 rect from 0, 80 to 4.5e7, 0 fc rgb "white" 
set label 3 at 1e6, 60 Init

set object 4 rect from 6.5e7, 500 to 1.2e8, 150 fc rgb "white" 
set label 4 at 6.6e7, 430 Fit

set out 'Data/hole_log.pdf'
plot 'Data/data_hole.txt' w l ls 1 t 'Number of particles', f(x) w l ls 2 t 'Fit'
