CXX=g++
CXXFLAGS=-std=c++17
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined

all: intento1.x

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

intento1.x: intento1.o getdatos.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.x *.o a.out
