.SUFFIXES: .cpp .o

CXX = g++
CPPFLAGS = -Wall -O
TARGET = puyopuyo
OBJECTS = main.o board.o block.o tree.o fold.o cross.o

$(TARGET): $(OBJECTS)
	$(CXX) $(CPPFLAGS) -o $(TARGET) $(OBJECTS)

main.o : main.cpp
board.o : board.cpp
block.o : block.cpp
tree.o : tree.cpp
cross.o : cross.cpp
fold.o : fold.cpp

clean:
	rm -rf $(OBJECTS)