PROJ = advent

CXX = g++
CFLAGS = -g -Wall

advent: main.cpp src/inputline.cpp
	$(CXX) $(CFLAGS) $? -o $@

clean:
	$(RM) advent