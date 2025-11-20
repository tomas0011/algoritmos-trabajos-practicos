CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = huffman
SRCS = main.cpp ejercicio1.cpp ejercicio2.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) *.o

rebuild: clean $(TARGET)

.PHONY: clean rebuild