PROJ = advent

CXX = g++
CXXFLAGS = -g -Wall

DAY1 = inversecaptcha
DAY2 = corruptionchecksum
DAY3 = spiralmemory
DAY4 = passphrasevalidator

DAY1SRC = src/$(DAY1).cpp
DAY2SRC = src/$(DAY2).cpp
DAY3SRC = src/$(DAY3).cpp
DAY4SRC = src/$(DAY4).cpp

DAY1HEAD = src/$(DAY1).h $(DAY1SRC)
DAY2HEAD = src/$(DAY2).h $(DAY2SRC)
DAY3HEAD = src/$(DAY3).h $(DAY3SRC)
DAY4HEAD = src/$(DAY4).h $(DAY4SRC)

HELPERHEAD = inputline.o adventhelper.o

main: main.o $(HELPERHEAD) $(DAY1).o $(DAY2).o $(DAY3).o $(DAY4).o
	$(CXX) $(CXXFLAGS) -o $(PROJ) $?

main.o: main.cpp $(MAINHEAD)
	$(CXX) $(CXXFLAGS) -c main.cpp

inputline.o: src/inputline.h src/inputline.cpp
	$(CXX) $(CXXFLAGS) -c src/inputline.cpp

adventhelper.o: src/adventhelper.h src/adventhelper.cpp
	$(CXX) $(CXXFLAGS) -c src/adventhelper.cpp

$(DAY1).o: $(HELPERHEAD) $(DAY1HEAD)
	$(CXX) $(CXXFLAGS) -c $(DAY1SRC)

$(DAY2).o: $(HELPERHEAD) $(DAY2HEAD)
	$(CXX) $(CXXFLAGS) -c $(DAY2SRC)

$(DAY3).o: $(HELPERHEAD) $(DAY3HEAD)
	$(CXX) $(CXXFLAGS) -c $(DAY3SRC)

$(DAY4).o: $(HELPERHEAD) $(DAY4HEAD)
	$(CXX) $(CXXFLAGS) -c $(DAY4SRC)

clean:
	$(RM) $(PROJ)

nuke:
	$(RM) $(PROJ) *.o