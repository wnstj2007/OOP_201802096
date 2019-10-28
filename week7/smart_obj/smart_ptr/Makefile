.SUFFIXES: .cpp .h .o

OBJECTS = object.o smart_obj.o shared_mut.o unique_immut.o
CPP = object.cpp smart_obj.cpp shared_mut.cpp unique_immut.cpp

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(CPP)
	$(CXX) -c $(CPP)

clean :
	rm -rf $(OBJECTS)

smart_ptr.o : smart_ptr.cpp

shared_mut.o : shared_mut.cpp

unique_immut.o : unique_immut.cpp

object.o : object.cpp
