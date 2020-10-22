CXX = g++

run_coffee_random: coffee_random.x

coffee_random.x: coffee_random.cpp ../Functions/time_steps.cpp ../Functions/entropy_step.cpp ../Functions/init_entropy.cpp ../Functions/init_cells.cpp ../Functions/init_particles.cpp ../Functions/distribution.cpp ../Functions/get_data.cpp ../Functions/particle.cpp
	$(CXX) $^ -o $@
	./$@ > ../Data/entropy_data.txt
	gnuplot ../Scripts/distribution_script.gp
	xpdf ../Data/distribution_start.pdf
	xpdf ../Data/distribution_end.pdf
	gnuplot ../Scripts/entropy_script.gp
	xpdf ../Data/entropy_data.pdf
	rm $@ ../Data/entropy_data.txt ../Data/distribution_start.txt ../Data/distribution_end.txt

clean:
	rm rm -f *.x *.o a.out


