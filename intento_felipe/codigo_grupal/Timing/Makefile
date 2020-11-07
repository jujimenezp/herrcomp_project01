CXX = g++
CXXFLAGS = -std=c++17 -g
OPTIMIZATIONFLAGS = -O3
SANITFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined
DEPENDENCIES = 

for: Data/for_auto_1.pdf

Data/for_auto_1.pdf: for_auto.x
	bash Scripts/for_auto.sh > Data/data_for_auto_1.txt
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) Programs/for_auto.cpp -o $<
	bash Scripts/for_auto.sh > Data/data_for_auto_2.txt
	gnuplot Scripts/for_auto.gp
	xpdf $@ &
	xpdf Data/for_auto_2.pdf &

%.x: Programs/%.cpp
	$(CXX) $(CXXFLAGS) $(OPTIMIZATIONFLAGS) $(SANITFLAGS) $< -o $@

clean:
	rm -f *.x *.o *.out Data/data_*.txt
