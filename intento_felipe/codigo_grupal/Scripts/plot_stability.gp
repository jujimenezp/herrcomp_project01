set g
set ls 1 lc rgb "blue" lt 1 lw 1 pt 7 ps 0.5
set ls 2 lc rgb "red" lt 1 lw 1

nmolecules = int(system("sed -n 1p Data/init_data.txt | tr -d -c 0-9"))

set xr [0:1100]
set yr []
set title 'Tiempo de estabilización vs Tamaño de la taza'
set xl 'Tamaño de la taza'
set yl 'Tiempo de estabilización'
set k b r
set term pdf

f(x) = A*x**B
A = 10
B = 2
set fit errorvar
set fit quiet
fit f(x) "Data/data_stability.txt" u 1:2:3 yerrors via A, B

Init = sprintf(" {/:Bold Parámetros iniciales} \n Número de partículas = %i", nmolecules)
Fit = sprintf(" {/:Bold Parámetros de regresión} \n y = ax^b \n a = %g +/- %g \n b = %g +/- %g", A, A_err, B, B_err)

set obj 1 rect from graph 0, 1 to graph 0.36, 0.86 fc rgb "white"
set lab 1 Init at graph 0, 0.96

set obj 2 rect from graph 0, 0.86 to graph 0.36, 0.6 fc rgb "white"
set lab 2 Fit at graph 0, 0.82

set o "Data/stability.pdf"
p "Data/data_stability.txt" u 1:2:3 w errorb ls 1 t "Tiempo de estabilización", f(x) w l ls 2 t 'Fit'

set log xy
set xr [90:1100]
set yr [7e5:]

set o "Data/stability_log.pdf"
rep
