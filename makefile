
#Variables
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
HEADERS = Ant.hpp menu.hpp
SRCS = antMain.cpp Ant.cpp menu.cpp
OBJS = antMain.o Ant.o menu.o

#Targets
ant: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS}  -o ant

antMain.o: antMain.cpp menu.hpp
	${CXX} ${CXXFLAGS} -c antMain.cpp

Ant.o: Ant.cpp Ant.hpp
	${CXX} ${CXXFLAGS} -c Ant.cpp

menu.o: menu.cpp Ant.hpp menu.hpp
	${CXX} ${CXXFLAGS} -c menu.cpp

clean:
	rm *.o ant
