CXX = g++

for: for_auto.x

for_auto.x: ../Scripts/prof_for_auto.sh for_auto.cpp
	$(CXX) for_auto.cpp -o $@
	bash $<
	gnuplot ../Scripts/prof_for_auto.gp
	xpdf ../Data/prof_for_auto.pdf &
	rm $@ ../Data/prof_for_auto.txt
