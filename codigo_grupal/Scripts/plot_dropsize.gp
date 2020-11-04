set grid
set style line 1 lc rgb "blue" lt 1 lw 2 pt 7 ps 1
set style line 2 lc rgb "red" lt 1 lw 1 pt 7 ps 0.5
set style line 3 lc rgb "black" lt 1 lw 1 pt 7 ps 0.5

#nmolecules = int(system("sed -n 1p Data/init_data.txt | tr -d -c 0-9"))
#gridsize = int(system("sed -n 2p Data/init_data.txt | tr -d -c 0-9"))
#latticesize = int(system("sed -n 3p Data/init_data.txt | tr -d -c 0-9"))
#resolution = int(system("sed -n 6p Data/init_data.txt | tr -d -c 0-9"))

set xrange [0:*]
set yrange [0:*]
set title 'Tamaño de la gota vs Iteraciones'
set xlabel 'Iteraciones'
set ylabel 'Tamaño de la gota'
set term pdf

f(x) = A*x**B
A=90
B=0.5
set fit errorvariables
set fit quiet
fit f(x) "Data/data_dropsize_1.txt" via A, B

#Init = sprintf("Parametros iniciales\nNúmero de moleculas = %i\nNúmero de celdas = %i\nTamaño de la tasa = %i\nResolución = %i", nmolecules, gridsize, latticesize, resolution)
#Fit = sprintf("Parametros de regresión\ny = ax^b\na = %f +/- %f\nb = %f +/- %f", A, A_err, B, B_err)


set out 'Data/dropsize.pdf'
plot 'Data/data_dropsize_1.txt' w l ls 1 t 'Drop size before equilibrium', f(x) w l ls 2 t 'Fit', 'Data/data_dropsize_2.txt' w l ls 3 t 'Tamaño de la gota despues'

set log xy

#unset object 1
#unset label 1
#unset object 2
#unset label 2

set out 'Data/dropsize_log.pdf'
plot 'Data/data_dropsize_1.txt' w l ls 1 t 'Drop size before equilibrium', f(x) w l ls 2 t 'Fit', 'Data/data_dropsize_2.txt' w l ls 3 t 'Tamaño de la gota despues'
