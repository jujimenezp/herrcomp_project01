CXX = g++

test_particle: test_particle.x

test_get_data: test_get_data.x

test_init_particles: initial_distribution.pdf

test_init_cells: initial_cells.txt

test_init_entropy: initial_entropy.txt

run_coffee_random_distribution: distribution_time.pdf

run_coffee_random_entropy: entropy_time.pdf

test_particle.x: particle_test.cpp particle.cpp
	$(CXX) $^ -o $@
	./$@

test_get_data.x: get_data_test.cpp get_data.cpp
	$(CXX) $^ -o $@
	./$@
	rm $@

initial_distribution.pdf: init_particles_test.cpp init_particles.cpp particle.cpp
	$(CXX) $^ -o test_init_particles.x
	./test_init_particles.x 10 > test_init_particles.txt
	gnuplot initial_distribution_script.gp
	xpdf $@
	rm test_init_particles.txt test_init_particles.x $@

initial_cells.txt: init_cells_test.cpp init_cells.cpp init_particles.cpp particle.cpp
	$(CXX) $^ -o test_init_cells.x
	./test_init_cells.x 10 25 100 > $@
	emacs $@ &
	rm test_init_cells.x $@

initial_entropy.txt: init_entropy_test.cpp init_entropy.cpp init_cells.cpp init_particles.cpp particle.cpp
	$(CXX) $^ -o test_init_entropy.x
	./test_init_entropy.x 10 25 100 > $@
	emacs $@ &
	rm test_init_entropy.x $@

distribution_time.pdf: coffee_random_distribution.cpp time_distribution.cpp get_data.cpp init_entropy.cpp init_cells.cpp init_particles.cpp particle.cpp
	$(CXX) $^ -o distribution_time.x
	./distribution_time.x > distribution_time.txt
	gnuplot distribution_time_script.gp
	xpdf $@
	rm distribution_time.txt distribution_time.x distribution_time.pdf

entropy_time.pdf: coffee_random_entropy.cpp time_entropy.cpp get_data.cpp init_entropy.cpp init_cells.cpp init_particles.cpp particle.cpp
	$(CXX) $^ -o entropy_time.x
	./entropy_time.x > entropy_time.txt
	gnuplot entropy_time_script.gp
	xpdf $@
	rm entropy_time.txt entropy_time.x entropy_time.pdf

clean:
	rm rm -f *.x *.o a.out
