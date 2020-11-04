set g
set ls 1 lc rgb "blue" lt 1 lw 2
set ls 2 lc rgb "red" lt 1 lw 1
set ls 3 lc rgb "black" lt 1 lw 0.5

nmolecules = int(system("sed -n 1p Data/init_data.txt | tr -d -c 0-9"))
gridsize = int(system("sed -n 2p Data/init_data.txt | tr -d -c 0-9"))
latticesize = int(system("sed -n 3p Data/init_data.txt | tr -d -c 0-9"))
resolution = int(system("sed -n 6p Data/init_data.txt | tr -d -c 0-9"))

set xr []
set yr [:800*0.45]
set title 'Tamaño de la gota vs Iteraciones'
set xl 'Iteraciones'
set yl 'Tamaño de la gota'
set k t l
set term pdf

f(x) = A*x**B
A = 90
B = 0.5
set fit errorvar
set fit quiet
fit f(x) "Data/data_dropsize_1.txt" via A, B

Init = sprintf(" {/:Bold Parámetros iniciales} \n Número de partículas = %i \n Tamaño de la taza = %i ", nmolecules, latticesize)
Fit = sprintf(" {/:Bold Parámetros de regresión} \n y = ax^b \n a = %g +/- %g \n b = %g +/- %g", A, A_err, B, B_err)

set obj 1 rect from graph 1, 0.25 to graph 0.6, 0.45 fc rgb "white" 
set lab 1 Init at graph 0.6, 0.4

set obj 2 rect from graph 1, 0 to graph 0.6, 0.25 fc rgb "white" 
set lab 2 Fit at graph 0.6, 0.2

set o 'Data/dropsize.pdf'
p 'Data/data_dropsize_1.txt' w l ls 1 t 'Tamaño de la gota antes del equilibrio', f(x) w l ls 2 t 'Fit', 'Data/data_dropsize_2.txt' w l ls 3 t 'Tamaño de la gota despues del equilibrio'

set log xy
set xr []
set yr [:800*0.45]

set o 'Data/dropsize_log.pdf'
rep
