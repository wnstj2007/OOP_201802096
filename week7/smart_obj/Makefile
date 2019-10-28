.SUFFIXES: .cpp .o

OBJECTS = smart_ptr/object.o smart_ptr/smart_obj.o smart_ptr/shared_mut.o smart_ptr/unique_immut.o
MAIN = main.o $(OBJECTS)
TEST_FILE = test.o $(OBJECTS)

CXX = g++
SMT_PTR = smart_ptr

TARGET = test
TEST = test_all

$(TARGET) : $(MAIN)
	$(MAKE) -C $(SMT_PTR)
	$(CXX) -o $(TARGET) $(MAIN)

$(TEST) : $(TEST_FILE)
	$(MAKE) -C $(SMT_PTR)
	$(CXX) -o $(TEST) $(TEST_FILE)

clean :
	rm -rf $(MAIN) $(TARGET) $(TEST) $(TEST_FILE)

main.o : main.cpp
test.o : test.cpp
