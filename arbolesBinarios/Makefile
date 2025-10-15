CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = arbolesBinarios
SRCS = main.cpp ejercicio1.cpp ejercicio2.cpp ejercicio3.cpp ejercicio4.cpp ejercicio5.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) *.o

rebuild: clean $(TARGET)

.PHONY: clean rebuild