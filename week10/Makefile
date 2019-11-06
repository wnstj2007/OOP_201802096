.SUFFIXES: .o .cpp

OBJECTS = main.o vehicle.o car.o bike.o

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

clean :
	rm -rf $(OBJECTS) $(TARGET)

main.o : main.cpp
vehicle.o : vehicle.cpp
car.o : car.cpp
bike.o : bike.cpp
