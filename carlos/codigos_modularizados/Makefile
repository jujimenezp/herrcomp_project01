


all: 2.x



test: testfactorial.x test_catch2.x



%.0: %.cpp
	g++ -c $<


2.x: 2.o class_particle.o
	g++ $^ -o $@

testfactorial.x: testfactorial.o factorial.o
	g++ $^ -o $@

test_catch2.x: test_catch2.o factorial.o
	g++ $^ -o $@

clean:
	rm -f *.x *.o a.out
