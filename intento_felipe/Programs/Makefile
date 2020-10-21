CXX = g++

run_coffee_random: coffee_random.x

coffee_random.x: coffee_random.cpp ../Functions/time_steps.cpp ../Functions/entropy_step.cpp ../Functions/init_entropy.cpp ../Functions/init_cells.cpp ../Functions/init_particles.cpp ../Functions/distribution.cpp ../Functions/get_data.cpp ../Functions/particle.cpp
	$(CXX) $^ -o $@
	./$@
	gnuplot ../Scripts/distribution_script.gp
	xpdf ../Data/distribution_figure.pdf
	gnuplot ../Scripts/entropy_script.gp
	xpdf ../Data/entropy_figure.pdf
	rm $@

clean:
	rm rm -f *.x *.o a.out


