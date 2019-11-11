
// .cpp와 .o파일을 다룰 것임을 표기
.SUFFIXES: .o .cpp
// compile할 object파일들 설정
OBJECTS = shared_ref.o test.o human.o student.o smart_obj.o weak_pointer.o
// compile할 테스트코드의 object파일을 포함한 object 파일들 설정

// CXX 설정
CXX = g++
CPPFLAGS = -c
// 실행파일 이름 설정
TARGET = test


// 실행파일 : 컴파일에 사용될 object파일들
//  (탭으로 띄운 후) 컴파일 명령어 사용
$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

// clean은 make 결과 생성된 파일들 모두 삭제
clean :
	rm -rf $(OBJECTS) $(TARGET)

// 컴파일하기 위해 필요한 파일들 설정
test.o : test.cpp
shared_ref.o : shared_ref.cpp
human.o : human.cpp
smart_obj.o : smart_obj.cpp
weak_pointer.o : weak_pointer.cpp
student.o : student.cpp
