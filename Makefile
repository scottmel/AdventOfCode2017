PROJ = advent

CXX = g++
CXXFLAGS = -g -Wall

DAY1 = inversecaptcha
DAY2 = corruptionchecksum
DAY3 = spiralmemory

DAY1SRC = src/$(DAY1).cpp
DAY2SRC = src/$(DAY2).cpp
DAY3SRC = src/$(DAY3).cpp

DAY1HEAD = src/$(DAY1).h $(DAY1SRC)
DAY2HEAD = src/$(DAY2).h $(DAY2SRC)
DAY3HEAD = src/$(DAY3).h $(DAY3SRC)


main: main.o inputline.o $(DAY1).o $(DAY2).o $(DAY3).o
	$(CXX) $(CXXFLAGS) -o $(PROJ) $?

main.o: main.cpp $(MAINHEAD)
	$(CXX) $(CXXFLAGS) -c main.cpp

inputline.o: src/inputline.h
	$(CXX) $(CXXFLAGS) -c src/inputline.cpp

$(DAY1).o: src/inputline.h $(DAY1HEAD)
	$(CXX) $(CXXFLAGS) -c $(DAY1SRC)

$(DAY2).o: src/inputline.h $(DAY2HEAD)
	$(CXX) $(CXXFLAGS) -c $(DAY2SRC)

$(DAY3).o: src/inputline.h $(DAY3HEAD)
	$(CXX) $(CXXFLAGS) -c $(DAY3SRC)

clean:
	$(RM) $(PROJ)

nuke:
	$(RM) $(PROJ) *.o