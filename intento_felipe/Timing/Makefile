CXX = g++
CXXFLAGS = -std=c++17 -O3 -g
SANITFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined
DEPENDENCIES = ../Objects/CONFIG.o ../Objects/class_particle.o ../Objects/start.o ../Objects/time_step.o ../Objects/entropy.o

for: ../Data/prof_for_auto.pdf

print: ../Data/prof_print.pdf

../Data/prof_for_auto.pdf: for_auto.x
	bash ../Scripts/prof_for_auto.sh
	gnuplot ../Scripts/prof_for_auto.gp
	xpdf $@ &

../Data/prof_print.pdf: p_print.out stats.x
	bash ../Scripts/prof_print.sh
	gnuplot ../Scripts/prof_print.gp
	xpdf $@ &

p_print.out: print.o $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

p_print.o: print.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -c  $< -o $@

%.x: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.x *.o *.out ../Data/prof_print.txt ../Data/prof_for_auto.txt
