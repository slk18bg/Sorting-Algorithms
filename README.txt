Sheikh Khaled
COP4531- proj1 Algorithm Analysis

********************************
* CONTENTS OF THE PROJECT FOLDER *
********************************
Inside Khaled_proj1 are three folders:
- data files
- plots
- source code files
The 'data files' folder contains the data used to create the plots (read below
how data was generated).
The 'plots' folder contains the images of the data generated to create
the plots for the runtimes of each algorithm. Also included is the PDF with
each plot.
The 'source code files' contains the implementations of each algorithm
along with the makefile needed to create the executables (read below
how to run the executables).
Also included in the project folder are:
- python code used to plot data via matplotlib
- this README.txt file

***************************
* HOW EACH FILE IS SET UP *
***************************
Each file is named after the algorithm that is implemented in
it. 
Ex. insertionSort.cpp has insertion sort implemented in it along with the
driver program needed to test that algorithm. 
No input is necessary, all data used for testing is generated within the
program. The random values are generated using std::rand() and then added to the
vector.
The algorithms are sorting vectors since attempting to sort arrays results in
seg faults for the larger test sizes.
Each algorithm is sorting vectors of ints, with the exception of bucketSort,
which sorts vectors of floats as stated in the assignment instructions.


*******************************
* HOW TO EXECUTE EACH PROGRAM *
*******************************
There is a provided makefile that will make each individual algorithm executable
program. Just enter the command "make" or "make all" to make all of the
executables simultaneously or "make xSort.exe" to make a specific
executable, where x is the name of the sorting algorithm. 
FOr example, to create heapSort.exe, just enter "make heapSort.exe"
to make the executable heapSort.exe. 
To run the program, just type in "heapSort.exe" and press enter to begin the program. 


************************************
* OUTPUT FORMAT FOR EACH ALGORITHM *
************************************
Each algorithm executable output will have identical behavior. What will be
first displayed is an unsorted array followed by the array sorted so that the
user can see that the algorithm works correctly. 
The time had to be measured in nanoseconds since the smaller vector sizes sort
too quickly, and the time taken to sort displays as 0 sec as a result.
Insertion sort takes the longest to sort, so be patient with this one. Don't
worry, the program did not time out. It takes 26 minutes to sort the vector of
size 1 million.
The rest of the output will be as follows:


*** SORTING TIMES FOR (algorithm name) SORT ***

unsorted array: (unsorted array values here)
sorted array: (sorted array values here)

Array size: (size of vector being sorted)
Time taken to sort: (time in nanoseconds)
sorted array: (sorted array values here) (optional)

*** END TESTING FOR (algorithm name) SORT ***


For each vector size, the time taken to sort that size will follow it. The
following vector sizes will be tested:
size = 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000
There is a stub of code commented out after each vector is sorted. If the user
wishes to see the sorted array, they may uncomment the stub of code.

A separate PDF file will be submitted along with the code that displays the
graphs for the sorting times of each algorithm, per the assignment instructions.


*************************************
* HOW DATA WAS GENERATED FOR GRAPHS *
*************************************
To gather data to plot, I ran each of the algorithm executables and copy pasted
the generated data into individual text files named "algorithmData.txt", where
'algorithm' can be replaced with any of the algorithm names tested.
For example, to open the data used to plot the radixSort runtimes, the user
should locate the "radixData.txt" file.
The data was then read in as a csv file on matplotlib, and then plotted and
labelled appropriately.
