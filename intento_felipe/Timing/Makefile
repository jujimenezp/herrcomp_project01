CXX = g++
CXXFLAGS = -std=c++17 -O3 -g
SANITFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined
DEPENDENCIES = ../Objects/Sanitizers/CONFIG.o ../Objects/Sanitizers/class_particle.o ../Objects/Sanitizers/start.o ../Objects/Sanitizers/time_step.o ../Objects/Sanitizers/entropy.o

for: ../Data/prof_for_auto.pdf

print: ../Data/prof_print.pdf

../Data/prof_for_auto.pdf: for_auto.x
	bash ../Scripts/prof_for_auto.sh > ../Data/prof_for_auto_1.txt
	$(CXX) $(SANITFLAGS) for_auto.cpp -o $<
	bash ../Scripts/prof_for_auto.sh > ../Data/prof_for_auto_2.txt
	gnuplot ../Scripts/prof_for_auto.gp
	xpdf $@ &

../Data/prof_print.pdf: p_print.out stats.x
	bash ../Scripts/prof_print.sh
	gnuplot ../Scripts/prof_print.gp
	xpdf $@ &

%.x: %.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $< -o $@

for_auto.out: for_auto.cpp
	$(CXX) $(SANITFLAGS) $< -o $@

p_print.out: p_print.o $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

p_print.o: print.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -c  $< -o $@

clean:
	rm -f *.x *.o *.out ../Data/prof_*.txt
