#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a -Werror

HEADERS=snowman.hpp
OBJECTS=snowman.o

run: test
	./$^

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o StudentTest1.o StudentTest2.o StudentTest3.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy snowman.cpp -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,hicpp-*,performance-*,portability-*,readability-* --warnings-as-errors=-* --

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

Test2.cpp:
	curl https://raw.githubusercontent.com/cpp-exercises/snowman-a/master/TestExample.cpp > Test2.cpp

StudentTest1.cpp: 
	curl https://raw.githubusercontent.com/YD5463/System-Programing-2/master/Test.cpp > $@

StudentTest2.cpp: # Shlomo Glick
	curl https://raw.githubusercontent.com/shlomog12/ex1_partA/main/Test.cpp > $@

StudentTest3.cpp: # Eviatar Nachshoni
	curl https://raw.githubusercontent.com/EN555/EX1-c-/master/Test.cpp > $@

clean:
	rm -f *.o demo test
	rm -f Test2.cpp
