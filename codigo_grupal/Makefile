CXX = g++
CXXFLAGS = -std=c++17 -O3 -g
LIBRARIES = -lgsl -lgslcblas -lm
SANITFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined
MEMCHECKFLAGS = --tool=memcheck --track-origins=yes --leak-check=full
DEPENDENCIES_SANITIZERS = Objects/Sanitizers/CONFIG.o Objects/Sanitizers/class_particle.o Objects/Sanitizers/start.o Objects/Sanitizers/entropy.o Objects/Sanitizers/print_particles.o Objects/Sanitizers/dropsize.o 
DEPENDENCIES_NORMAL = Objects/Normal/CONFIG.o Objects/Normal/class_particle.o Objects/Normal/start.o Objects/Normal/entropy.o Objects/Normal/print_particles.o Objects/Normal/dropsize.o
DEPENDENCIES_GPROF = Objects/Gprof/CONFIG.o Objects/Gprof/class_particle.o Objects/Gprof/start.o Objects/Gprof/entropy.o Objects/Gprof/print_particles.o Objects/Gprof/dropsize.o 

all: main.x main_stability.x main_dropsize.x main_hole.x

test: test.x
	./$<

gprof: gprof.x gprof_stability.x gprof_dropsize.x gprof_hole.x  
	./$<
	gprof ./$< > Data/gprof-report.txt
	rm gmon.out
	./gprof_stability.x
	gprof ./gprof_stability.x > Data/gprof_stability-report.txt
	rm gmon.out
	./gprof_dropsize.x
	gprof ./gprof_dropsize.x > Data/gprof_dropsize-report.txt
	rm gmon.out
	./gprof_hole.x
	gprof ./gprof_hole.x > Data/gprof_hole-report.txt
	rm gmon.out

cachegrind: valgrind.x valgrind_stability.x valgrind_dropsize.x valgrind_hole.x
	valgrind --tool=cachegrind ./$<
	cg_annotate $$(ls -t cachegrind.out.* | head -n 1) > Data/cachegrind-report.txt
	rm -f cachegrind.out.*
	valgrind --tool=cachegrind ./valgrind_stability.x
	cg_annotate $$(ls -t cachegrind.out.* | head -n 1) > Data/cachegrind-report_stability.txt
	rm -f cachegrind.out.*
	valgrind --tool=cachegrind ./valgrind_dropsize.x
	cg_annotate $$(ls -t cachegrind.out.* | head -n 1) > Data/cachegrind-report_dropsize.txt
	rm -f cachegrind.out.*
	valgrind --tool=cachegrind ./valgrind_hole.x
	cg_annotate $$(ls -t cachegrind.out.* | head -n 1) > Data/cachegrind-report_hole.txt
	rm -f cachegrind.out.*

memcheck: valgrind.x valgrind_stability.x valgrind_dropsize.x valgrind_hole.x
	valgrind $(MEMCHECKFLAGS) ./$<
	valgrind $(MEMCHECKFLAGS) ./valgrind_stability.x
	valgrind $(MEMCHECKFLAGS) ./valgrind_dropsize.x
	valgrind $(MEMCHECKFLAGS) ./valgrind_hole.x

graphs: main.x main_stability.x main_dropsize.x main_hole.x Data/init_data.txt
	./$<
	gnuplot Scripts/plot_particles.gp
	gnuplot Scripts/plot_entropy.gp
	xpdf Data/particles_start.pdf &
	xpdf Data/particles_end.pdf &
	xpdf Data/entropy.pdf &
	./main_dropsize.x
	gnuplot Scripts/plot_dropsize.gp
	xpdf Data/dropsize.pdf &
	xpdf Data/dropsize_log.pdf &
	./main_hole.x
	gnuplot Scripts/plot_hole.gp
	xpdf Data/hole.pdf &
	xpdf Data/hole_log.pdf &
	bash Scripts/plot_stability.sh
	gnuplot Scripts/plot_stability.gp
	xpdf Data/stability.pdf &
	xpdf Data/stability_log.pdf &

main.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/main.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

main_stability.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/stability.o Objects/Sanitizers/main_stability.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ $(LIBRARIES) -o $@

main_dropsize.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/stability.o Objects/Sanitizers/main_dropsize.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ $(LIBRARIES) -o $@

main_hole.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/main_hole.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

test.x: $(DEPENDENCIES_NORMAL) Objects/Normal/stability.o Objects/Normal/test.o
	$(CXX) $(CXXFLAGS) $^ $(LIBRARIES) -o $@

gprof.x: $(DEPENDENCIES_GPROF) Objects/Gprof/main.o
	$(CXX) $(CXXFLAGS) -pg $^ -o $@

gprof_stability.x: $(DEPENDENCIES_GPROF) Objects/Gprof/stability.o Objects/Gprof/main_stability.o
	$(CXX) $(CXXFLAGS) -pg $^ $(LIBRARIES) -o $@

gprof_dropsize.x: $(DEPENDENCIES_GPROF) Objects/Gprof/stability.o Objects/Gprof/main_dropsize.o
	$(CXX) $(CXXFLAGS) -pg $^ $(LIBRARIES) -o $@

gprof_hole.x: $(DEPENDENCIES_GPROF) Objects/Gprof/main_hole.o
	$(CXX) $(CXXFLAGS) -pg $^ -o $@

valgrind.x: $(DEPENDENCIES_NORMAL) Objects/Normal/main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

valgrind_stability.x: $(DEPENDENCIES_NORMAL) Objects/Normal/stability.o Objects/Normal/main_stability.o
	$(CXX) $(CXXFLAGS) $^ $(LIBRARIES) -o $@

valgrind_dropsize.x: $(DEPENDENCIES_NORMAL) Objects/Normal/stability.o Objects/Normal/main_dropsize.o
	$(CXX) $(CXXFLAGS) $^ $(LIBRARIES) -o $@

valgrind_hole.x: $(DEPENDENCIES_NORMAL) Objects/Normal/main_hole.o
	$(CXX) $(CXXFLAGS) $^ -o $@

Objects/Sanitizers/%.o: Programs/%.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -c  $< -o $@

Objects/Normal/%.o: Programs/%.cpp
	$(CXX) $(CXXFLAGS) -c  $< -o $@

Objects/Gprof/%.o: Programs/%.cpp
	$(CXX) $(CXXFLAGS) -pg -c  $< -o $@

clean:
	rm -f *.x Data/data*.txt *.log

oclean:
	rm -f Objects/Sanitizers/*.o Objects/Normal/*.o Objects/Gprof/*.o
