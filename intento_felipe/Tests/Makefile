CXX = g++

t_particle: particle.x

t_get_data: get_data.x

t_init_particles: init_particles.x

t_init_cells: init_cells.txt

t_init_entropy: init_entropy.txt

t_entropy_step: entropy_step.x

particle.x: particle_test.cpp ../Functions/particle.cpp
	$(CXX) $^ -o $@
	./$@
	rm $@

get_data.x: get_data_test.cpp ../Functions/get_data.cpp
	$(CXX) $^ -o $@
	./$@
	rm $@

init_particles.x: init_particles_test.cpp ../Functions/init_particles.cpp ../Functions/distribution.cpp ../Functions/particle.cpp
	$(CXX) $^ -o init_particles.x
	./init_particles.x
	gnuplot ../Scripts/distribution_script.gp
	xpdf ../Data/distribution_start.pdf
	rm init_particles.x 

init_cells.txt: init_cells_test.cpp ../Functions/init_cells.cpp ../Functions/init_particles.cpp ../Functions/particle.cpp
	$(CXX) $^ -o test_init_cells.x
	./test_init_cells.x > $@
	emacs $@
	rm test_init_cells.x $@

init_entropy.txt: init_entropy_test.cpp ../Functions/init_entropy.cpp ../Functions/init_cells.cpp ../Functions/init_particles.cpp ../Functions/particle.cpp
	$(CXX) $^ -o test_init_entropy.x
	./test_init_entropy.x > $@
	emacs $@
	rm test_init_entropy.x $@

entropy_step.x: entropy_step_test.cpp ../Functions/entropy_step.cpp ../Functions/init_entropy.cpp ../Functions/init_cells.cpp ../Functions/particle.cpp
	$(CXX) $^ -o $@
	./$@
	rm $@

clean:
	rm rm -f *.x *.o a.out
