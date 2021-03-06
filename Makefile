CXX = g++
CXXFLAGS = -Wall -MMD -g
EXEC = graph
OBJECTS = main.o graph.o node.o undirected-graph.o directed-graph.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}