CXX = g++
CXXFLAGS = -std=c++17 -O3
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined

t_particle: particle.x

t_get_data: get_data.x

t_init_particles: init_particles.x

t_init_cells: init_cells.txt

t_init_entropy: init_entropy.txt

t_entropy_step: entropy_step.x


Objects/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $( -c $^ -o $@

../Functions/Objects/%.o: ../Functions/%.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -c $^ -o $@


particle.x: Objects/particle_test.o ../Functions/Objects/particle.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $() $^ -o $@
	./$@
	rm $@

get_data.x: Objects/get_data_test.o ../Functions/Objects/get_data.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@
	./$@
	rm $@

init_particles.x: Objects/init_particles_test.o ../Functions/Objects/init_particles.o ../Functions/Objects/distribution.o ../Functions/Objects/particle.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o init_particles.x
	./init_particles.x
	gnuplot ../Scripts/distribution_script.gp
	xpdf ../Data/distribution_start.pdf
	rm init_particles.x ../Data/distribution_start.txt ../Data/distribution_end.txt

init_cells.txt: Objects/init_cells_test.o ../Functions/Objects/init_cells.o ../Functions/Objects/init_particles.o ../Functions/Objects/particle.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o test_init_cells.x
	./test_init_cells.x > $@
	emacs $@
	rm test_init_cells.x $@

init_entropy.txt: Objects/init_entropy_test.o ../Functions/Objects/init_entropy.o ../Functions/Objects/init_cells.o ../Functions/Objects/init_particles.o ../Functions/Objects/particle.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o test_init_entropy.x
	./test_init_entropy.x > $@
	emacs $@
	rm test_init_entropy.x $@

entropy_step.x: Objects/entropy_step_test.o ../Functions/Objects/entropy_step.o ../Functions/Objects/init_entropy.o ../Functions/Objects/init_cells.o ../Functions/Objects/particle.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@
	./$@
	rm $@

clean:
	rm rm -f *.x *.o a.out
