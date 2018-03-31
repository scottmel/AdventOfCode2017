PROJ = advent

CXX = g++
CFLAGS = -g -Wall

advent: main.cpp
	$(CXX) $(CFLAGS) $? -o $@

clean:
	$(RM) advent