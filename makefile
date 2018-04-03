
 exec : main.o
	gcc -o exec main.o

 main.o : main.c MemoryManager.h Block.h Node.h DLinkedList.h
	gcc -c main.c

 
 clean : 
	rm main.o exec
