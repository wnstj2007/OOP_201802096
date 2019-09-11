.SUFFIXES: .cpp .o

OBJECTS = main.o print.o student_id.o

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

clean :
	rm -rf $(OBJECTS) $(TARGET)

main.o : main.cpp
print.o : print.cpp
student_id.o : student_id.cpp
