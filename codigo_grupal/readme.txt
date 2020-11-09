SIMULACION DE CREMA EN SUPERFICIE DE CAFE


INTEGRANTES:
Carlos Andres Del Valle Urberuaga
Felipe Gomez Lozada
Juian David Jimenez Paz
Andres Felipe Vargas Londono



USO:

make: El comando make compila todos los archivos de la simulacion y produce 4
ejecutables correspondientes a los 4 fenomenos que se quiere estudiar

Data/init_data.txt: Este archivo contiene las condiciones iniciales del
problema, se pueden modificar sus valores manualmente

make test: Compila y ejecuta el programa que contiene todos los test de la
simulacion

make gprof: Realiza profiling con gprof a los 4 ejecutables y arroja los
resultados en 4 reportes en el directorio Data/

make cachegrind: Corre Valgrind con la herramienta cachegrind para los 4
ejecutables y arroja los resultados en 4 reportes en el directorio  Data/

make memcheck: Similar a cachegrind pero usa la herramienta memcheck

make graphs: Ejecuta los 4 programas de la simulacion, corre los scripts que
generan las graficas finales y las muestra usando XPDF

make clean: Elimina los ejecutables, los archivos *.log creados por Gnuplot y los
archivos data*.txt que son producidos por los programas y usados para las
graficas

make oclean: Borra todos los archivos objeto *.o de los subdirectorios de Objects/



MAKEFILE:

VARIABLES

CXX: compilador
CXXFLAGS: Banderas basicas de compilacion (estandar std, simbolos de debugging y
optimizacion)
LIBRARIES: Librerias necesarias para linkear en la compilacion
SANITFLAGS: Banderas de sanitizers usadas en la compilacion
MEMCHECKFLAGS: Banderas para usar la herramienta memcheck de Valgrind
DEPENDENCIES_SANITIZERS: Archivos objeto (.o) de todos los programas correspondientes a la compilacion
con sanitizers (Se encuentran en Objects/Sanitizers)
DEPENDENCIES_NORMAL: Archivos objeto (.o) de todos los programas
correspondientes a la compilacion usual (Se encuentran en Objects/Normal)
DEPENDENCIES_GPROF: Archivos objeto (.o) de todos los programas correspondientes
a la compilacion para gprof (Se encuentran en Objects/Gprof)

Se tienen 3 variables de dependencias porque para diferentes targets se necesita
compilar con diferentes banderas

TARGETS

all: LLama a los target de los ejecutables de la simulacion, en
total son 4 ejecutables correspondientes a los 4 fenomenos que se desea estudiar
(main.x, main_stability.x, main_dropsize.x, main_hole.x)

test: Llama al target de test.x y lo ejecuta, corriendo todos los test

gprof: llama  a los target gprof*.x de cada ejecutable, les realiza profiling
con gprof y arroja los resultados en 4 informes en la carpeta Data

cachegrind: Llama a los target valgrind*.x de cada ejecutable, para cada uno usa
la herramienta cachegrind de Valgrind y arroja los resultados en 4 informes en la
carpeta Data

memcheck: Similar a cachegrind pero usa la herramienta memcheck y arroja los
resultados a la pantalla

graphs: Llama a los target de los ejecutables de la simulacion y a init_data.txt
(por si cambian las condiciones iniciales). Ejecuta los 4 programas de la
simulacion y ejecuta todos los scripts
que producen las graficas de resultados (plot_particles.gp, plot_entropy.gp,
plot_dropsize.gp, plot_hole.gp, plot_stability.sh, plot_stability.gp)
y abre los archivos pdf de cada grafica

targets tipo main*.x: Llama a DEPENDENCIES_SANITIZERS y a
Objects/Sanitizers/main*.o Compila todos estos programas usando CXX, CXXFLAGS,
SANITFLAGS y LIBRARIES de ser necesario y el ejecutable es main*.x

test.x: Llama a DEPENDENCIES_NORMAL y a Objects/Normal/test.o y compila usando
CXX, CXXFLAGS, LIBRARIES y el ejecutable es test.x

targets tipo gprof*.x: Llama a DEPENDENCIES_GPROF y a Objects/Gprof/main*.o
Compila usando CXX, CXXFLAGS, -pg, LIBRARIES  de ser necesario y el ejecutable es gprof*.x

targets tipo valgrind*.x: Llama a DEPENDENCIES_NORMAL y a Objects/Normal/main*o
Compila usando CXX, CXXFLAGS, LIBRARIES de ser necesario y el ejecutable se
llama valgrind*.x

Objects/Sanitizers/%.o: Compila Programs/%.cpp con sanitizers y -c para
compilar en archivos tipo objeto

Objects/Normal/%.o: Compila Programs/%.cpp sin sanitizers y con -c para compilar
en archivos tipo objeto

Objects/gprof/%.o Compila Programs/%.cpp usando -pg para poder luego realizar
profiling con Gprof

clean: elimina ejecutables, archivos .log,  archivos txt que comiencen por data
en el directorio Data/

oclean: Elimina todos los archivos tipo objeto en los 3 directorios internos de Objects/



SCRIPTS:

plot_particles.gp: Grafica las posiciones de las particulas de los archivos
Data/data_particles_start.txt y Data/data_particles_end.txt. Con un comando de
bash extrae de Data/init_data.txt los valores de latticesize y gridsize que usa
para mostrar la frontera como un cuadrado rojo y hacer el grid del tamanio de
las celdas, el rango de x e y es 25% mas grande para mostrar que ninguna
particula este afuera. Arroja las graficas a Data/particles_start.pdf y Data/particles_end.pdf

Plot_entropy.gp: Grafica la entropia contra el tiempo del archivo Data/data_entropy.txt. Toma los
valores de nmolecules, gridsize, latticesize para mostrarlos en un recuadro en la grafica.
Arroja el resultado a Data/entropy.pdf

plot_hole.gp: Grafica el numero de particulas contra el tiempo del archivo
Data/data_hole.txt. Hace una regresion de los datos a la forma funcional
esperada, y grafica los datos y la aproximacion en escala lineal y
semilogaritmica.

plot_dropsize.gp: grafica el tamanio de la gota de crema contra el tiempo. Hace
una regresion de los datos a la forma funcionale esperada, y grafica los datos y
la aproximacion en escala lineal y logaritmica.

plot_stability.sh: Para valores de N entre 100 y 1000 en saltos de 50, reemplaza
el valor de latticesize por N y corre ./main_stability.x, los resultados los
arroja a Data/data_stability.txt y luego reestablece el latticesize a 200

plot_stability.gp: Grafica el tiempo de estabilizacion contra el latticesize.
Realiza una regresion lineal a la forma funcional esperada y grafica los datos y
la aproximacion en escala lineal y logaritmica

