CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = caminosMinimos
SRCS = main.cpp dijkstra.cpp floydWarshall.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) *.o

rebuild: clean $(TARGET)

.PHONY: clean rebuild