EXENAME = graph
OBJS = main.o graph.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp graph.h NodeReader.h 
	$(CXX) $(CXXFLAGS) main.cpp

graph.o : graph.cpp graph.h NodeReader.h 
	$(CXX) $(CXXFLAGS) graph.cpp NodeReader.cpp 

test: catchmain.o tests.o graph.o NodeReader.o 
	$(LD) catchmain.o tests.o  graph.o $(LDFLAGS) -o test

catchmain.o : catchmain.cpp catch.hpp
	$(CXX) $(CXXFLAGS) catchmain.cpp

tests.o : tests.cpp catch.hpp graph.cpp graph.h NodeReader.h 
	$(CXX) $(CXXFLAGS) tests.cpp

clean :
	-rm -f *.o $(EXENAME) test

