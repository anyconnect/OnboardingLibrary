CPP=g++
CPPFLAGS=-I. -std=c++11 -ldl -pthread
DEPS = Test.h OnboardService.h
OBJ = Test.o

%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CPPFLAGS)

TARGET = onboardtest

all: $(TARGET)

clean: 
	rm -f $(OBJ) $(TARGET)


$(TARGET): $(OBJ)
	$(CPP) -o $@ $^ $(CPPFLAGS)
