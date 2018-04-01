PROJ = advent

CXX = g++
CFLAGS = -g -Wall

advent: main.cpp src/inputline.cpp src/inversecaptcha.cpp
	$(CXX) $(CFLAGS) $? -o $@

clean:
	$(RM) advent