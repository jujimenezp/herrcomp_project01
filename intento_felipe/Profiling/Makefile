CXX = g++
CXXFLAGS = -std=c++17 -O3 -g
SANITFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined
DEPENDENCIES = ../Objects/CONFIG.o ../Objects/class_particle.o ../Objects/start.o ../Objects/time_step.o ../Objects/entropy.o

for: for_auto.x

p_print: print.x

for_auto.x: ../Scripts/prof_for_auto.sh for_auto.cpp
	$(CXX) for_auto.cpp -o $@
	bash $<
	gnuplot ../Scripts/prof_for_auto.gp
	xpdf ../Data/prof_for_auto.pdf &
	rm $@ ../Data/prof_for_auto.txt

print.o: print.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -c  $< -o $@

print.x: print.o $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@
	./$@ > a.txt
	emacs ../Data/prof_print.txt &
	rm a.txt print.o print.x

clean:
	rm -f ../Data/prof* *.x *.o
