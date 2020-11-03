set grid
set style line 1 lc rgb "blue" lt 1 lw 1 pt 7 ps 0.5
set style line 2 lc rgb "red" lt 1 lw 1 pt 7 ps 0.5

nmolecules = int(system("sed -n 1p Data/init_data.txt | tr -d -c 0-9"))
gridsize = int(system("sed -n 2p Data/init_data.txt | tr -d -c 0-9"))
resolution = int(system("sed -n 6p Data/init_data.txt | tr -d -c 0-9"))

set xrange [100:*]
set yrange [90000:*]
set title 'Tiempo de estabilización vs Tamaño de la taza'
set xlabel 'Tamaño de la taza'
set ylabel 'Tiempo de estabilización'
set term pdf

f(x) = A*x**B
A = 10
B = 2
set fit errorvariables
set fit quiet
fit f(x) "Data/data_stability.txt" u 1:2:3 yerrors via A, B

Init = sprintf("Parametros iniciales\nNúmero de moleculas = %i\nNúmero de celdas = %i\nResolución = %i", nmolecules, gridsize, resolution)
Fit = sprintf("Parametros de regresión\ny = ax^b\na = %f +/- %f\nb = %f +/- %f", A, A_err, B, B_err)

set object 1 rect from 100, 1.8e7 to 505, 1.35e7 fc rgb "white" 
set label 1 at 110, 1.75e7 Init

set object 2 rect from 100, 1.2e7 to 505, 7.5e6 fc rgb "white" 
set label 2 at 110, 1.15e7 Fit

set out "Data/stability.pdf"
plot "Data/data_stability.txt" u 1:2:3 with errorbars ls 1 t "Tiempo de estabilización", f(x) w l ls 2 t 'Fit'

set log xy

unset object 1
unset label 1
unset object 2
unset label 2

set object 3 rect from 100, 1e8 to 240, 2e7 fc rgb "white" 
set label 3 at 101, 8e7 Init

set object 4 rect from 100, 1e7 to 240, 2e6 fc rgb "white" 
set label 4 at 101, 8e6 Fit

set out "Data/stability_log.pdf"
plot "Data/data_stability.txt" u 1:2:3 with errorbars ls 1 t "Tiempo de estabilización", f(x) w l ls 2 t 'Fit'
