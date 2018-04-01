PROJ = advent

CXX = g++
CFLAGS = -g -Wall

advent: main.cpp src/inputline.cpp src/day1.cpp
	$(CXX) $(CFLAGS) $? -o $@

clean:
	$(RM) advent