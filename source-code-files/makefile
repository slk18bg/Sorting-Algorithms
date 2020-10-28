# Sheikh Khaled
# Makefile for project 1
#

CC = g++ -std=c++11 -Wall -Wextra -I .

all: insertionSort.exe mergeSort.exe heapSort.exe quickSort.exe countingSort.exe radixSort.exe bucketSort.exe

insertionSort.exe: insertionSort.o
	$(CC) -o insertionSort.exe insertionSort.o
insertionSort.o: insertionSort.cpp
	$(CC) -c insertionSort.cpp

mergeSort.exe: mergeSort.o
	$(CC) -o mergeSort.exe mergeSort.o
mergeSort.o: mergeSort.cpp
	$(CC) -c mergeSort.cpp

heapSort.exe: heapSort.o
	$(CC) -o heapSort.exe heapSort.o
heapSort.o: heapSort.cpp
	$(CC) -c heapSort.cpp

quickSort.exe: quickSort.o
	$(CC) -o quickSort.exe quickSort.o
quickSort.o: quickSort.cpp
	$(CC) -c quickSort.cpp

countingSort.exe: countingSort.o
	$(CC) -o countingSort.exe countingSort.o
countingSort.o: countingSort.cpp
	$(CC) -c countingSort.cpp

radixSort.exe: radixSort.o
	$(CC) -o radixSort.exe radixSort.o
radixSort.o: radixSort.cpp
	$(CC) -c radixSort.cpp

bucketSort.exe: bucketSort.o
	$(CC) -o bucketSort.exe bucketSort.o
bucketSort.o: bucketSort.cpp
	$(CC) -c bucketSort.cpp
