CXX = g++
CXXFLAGS = -std=c++17
LIBRARIES = -lgsl -lgslcblas -lm
SANITFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined
DEPENDENCIES_0 =  Objects/0/CONFIG.o Objects/0/class_particle.o Objects/0/start.o Objects/0/entropy.o Objects/0/print_particles.o Objects/0/dropsize.o Objects/0/stability.o
DEPENDENCIES_1 =  Objects/1/CONFIG.o Objects/1/class_particle.o Objects/1/start.o Objects/1/entropy.o Objects/1/print_particles.o Objects/1/dropsize.o Objects/1/stability.o
DEPENDENCIES_2 =  Objects/2/CONFIG.o Objects/2/class_particle.o Objects/2/start.o Objects/2/entropy.o Objects/2/print_particles.o Objects/2/dropsize.o Objects/2/stability.o
DEPENDENCIES_3 =  Objects/3/CONFIG.o Objects/3/class_particle.o Objects/3/start.o Objects/3/entropy.o Objects/3/print_particles.o Objects/3/dropsize.o Objects/3/stability.o 

for: Data/for_auto_1.pdf

scale: Data/stability.pdf

Data/for_auto_1.pdf: for_auto.x
	bash Scripts/for_auto.sh > Data/data_for_auto_1.txt
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) Programs/for_auto.cpp -o $<
	bash Scripts/for_auto.sh > Data/data_for_auto_2.txt
	gnuplot Scripts/for_auto.gp
	xpdf $@ &
	xpdf Data/for_auto_2.pdf &

Data/stability.pdf: main_stability_0.x main_stability_1.x main_stability_2.x main_stability_3.x
	bash Scripts/plot_stability.sh
	gnuplot Scripts/plot_stability.gp
	xpdf $@ &

for_auto.x: Programs/for_auto.cpp
	$(CXX) $(CXXFLAGS) -O3 $(SANITFLAGS) $< -o $@

main_stability_0.x: $(DEPENDENCIES_0) Programs/main_stability.cpp
	$(CXX) $(CXXFLAGS) -O0 $(SANITFLAGS) $^ $(LIBRARIES) -o $@

main_stability_1.x: $(DEPENDENCIES_1) Programs/main_stability.cpp
	$(CXX) $(CXXFLAGS) -O1 $(SANITFLAGS) $^ $(LIBRARIES) -o $@

main_stability_2.x: $(DEPENDENCIES_2) Programs/main_stability.cpp
	$(CXX) $(CXXFLAGS) -O2 $(SANITFLAGS) $^ $(LIBRARIES) -o $@

main_stability_3.x: $(DEPENDENCIES_3) Programs/main_stability.cpp
	$(CXX) $(CXXFLAGS) -O3 $(SANITFLAGS) $^ $(LIBRARIES) -o $@

Objects/0/%.o: ../Programs/%.cpp
	$(CXX) $(CXXFLAGS) -O0 $(SANITFLAGS) -c  $< $(LIBRARIES) -o $@

Objects/1/%.o: ../Programs/%.cpp
	$(CXX) $(CXXFLAGS) -O1 $(SANITFLAGS) -c  $< $(LIBRARIES) -o $@

Objects/2/%.o: ../Programs/%.cpp
	$(CXX) $(CXXFLAGS) -O2 $(SANITFLAGS) -c  $< $(LIBRARIES) -o $@

Objects/3/%.o: ../Programs/%.cpp
	$(CXX) $(CXXFLAGS) -O3 $(SANITFLAGS) -c  $< $(LIBRARIES) -o $@

clean:
	rm -f *.x *.o *.out Data/data_*.txt
