.SUFFIXES: .o .cpp
OBJECTS = shared_ref.o test.o human.o student.o smart_obj.o weak_pointer.o

CXX = g++

TARGET = test

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

clean :
	rm -rf $(OBJECTS)

test.o : test.cpp
shared_ref.o : shared_ref.cpp
human.o : human.cpp
smart_obj.o : smart_obj.cpp
weak_pointer.o : weak_pointer.cpp
student.o : student.cpp
