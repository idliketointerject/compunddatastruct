PA1.out : main.o quash.o hash.o minHeap.o linkedList.o
	g++ -o prog1 main.o quash.o hash.o minHeap.o linkedList.o

linkedList.o: structs.h linkedList.h linkedList.cpp
	g++ -c linkedList.cpp

hash.o: structs.h hash.h linkedList.h linkedList.cpp hash.cpp
	g++ -c hash.cpp 
# above we are saying mylib.o depends on mylib.cpp and mylib.h 
# so if either mylib.cpp or mylib.h CHANGED since creating mylib.o 
# comple mylib.cpp again 
minHeap.o: structs.h minHeap.h 
	g++ -c minHeap.cpp 
main.o: main.cpp quash.h
	g++ -c main.cpp
quash.o: quash.cpp quash.h
	g++ -c quash.cpp


clean: 
	&nbps   	rm *.o prog1 
# above we are stating how to run the rule for clean, no dependencies, 
# what we want is when we ask to do a "make -f lab1.make clean" 
# that will not do anything except remove executable and object files 
# so we can "clean out" our directory of unneeded large files. 
# we only do a make clean when we want to clean up the files.

# END OF MAKE FILE
