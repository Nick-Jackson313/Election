CXX = g++
CXXFLAGS	= -std=c++17 -Wall

all: election

clean:
	rm run Election.o ElectoralMap.o TextUI.o District.o

election: main.cpp Election.o ElectoralMap.o TextUI.o District.o
	$(CXX) $(CXXFLAGS) main.cpp Election.o TextUI.o District.o ElectoralMap.o -o run

TextUI.o: TextUI.cpp
	$(CXX) $(CXXFLAGS) -c TextUI.cpp

Election.o: Election.cpp
	$(CXX) $(CXXFLAGS) -c Election.cpp

ElectoralMap.o: ElectoralMap.cpp
	$(CXX) $(CXXFLAGS) -c ElectoralMap.cpp

District.o: District.cpp
		$(CXX) $(CXXFLAGS) -c District.cpp
