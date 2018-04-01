PROJ = advent

CXX = g++
CXXFLAGS = -g -Wall

DAY1HEAD = src/inversecaptcha.h
DAY2HEAD = src/corruptionchecksum.h
DAY3HEAD = src/spiralmemory.h

DAY1SRC = src/inversecaptcha.cpp
DAY2SRC = src/corruptionchecksum.cpp
DAY3SRC = src/spiralmemory.cpp


main: main.o inputline.o inversecaptcha.o corruptionchecksum.o spiralmemory.o
	$(CXX) $(CXXFLAGS) -o $(PROJ) $?

main.o: main.cpp $(MAINHEAD)
	$(CXX) $(CXXFLAGS) -c main.cpp

inputline.o: src/inputline.h
	$(CXX) $(CXXFLAGS) -c src/inputline.cpp

inversecaptcha.o: src/inputline.h $(DAY1HEAD)
	$(CXX) $(CXXFLAGS) -c $(DAY1SRC)

corruptionchecksum.o: src/inputline.h $(DAY2HEAD)
	$(CXX) $(CXXFLAGS) -c $(DAY2SRC)

spiralmemory.o: src/inputline.h $(DAY3HEAD)
	$(CXX) $(CXXFLAGS) -c $(DAY3SRC)

clean:
	$(RM) $(PROJ)

nuke:
	$(RM) $(PROJ) *.o