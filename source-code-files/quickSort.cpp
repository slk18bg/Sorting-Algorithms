// implementation of quicksort and helper functions partition and swap

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <chrono>

int partition(std::vector<int> &a, int left, int right)
{
  int x = a[left];
  int i = left; // index of smaller element

  for (int j = left + 1; j < right; ++j)
  {
    if (a[j] <= x)
    {
      i += 1;
      std::swap(a[i], a[j]);
    }
  }

  std::swap(a[i], a[left]);
  return i;

} // end partition
// start = starting index
// end = ending index

void quickSort(std::vector<int> &v, int start, int end)
{
  if (start < end)
  {
    int pivotIdx = partition(v, start, end);
    quickSort(v, start, pivotIdx);
    quickSort(v, (pivotIdx + 1), end);
  }
} // end quickSort

// to refill vectors to the next testing size
void refill(std::vector<int> &v, int size)
{
  for (int i = 0; i < size; ++i)
  {
    int val = (std::rand() % 20000);
    v.push_back(val);
  }
}

int main()
{
  // create vector & size of vector to be sorted
  std::vector<int> V;
  int size = 10;

  srand((unsigned int)time(nullptr));

  // fill vector here
  for (int i = 0; i < size; ++i)
  {
    int val = (std::rand() % 20000);
    V.push_back(val);
  }

  int first = 0;
  int last = size;

  std::vector<int>::iterator itr;

  std::cout << "*** SORTING TIMES FOR QUICKSORT ***\n";
  std::cout << "\nunsorted array: ";
  for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
  std::cout << '\n';
  std::cout << "sorted array: ";

  auto started = std::chrono::high_resolution_clock::now();
  quickSort(V, first, last);
  auto finished = std::chrono::high_resolution_clock::now();
  for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
  std::cout << '\n';
  std::cout << "\nArray size: " << size << '\n';
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";

  // refill and resize vector for next test
  size = 50;
  last = 50;
  refill(V, size);
  V.resize(50);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  quickSort(V, first, last);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /* 
  for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
  std::cout << '\n';
  */

  size = 100;
  last = 100;
  refill(V, size);
  V.resize(100);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  quickSort(V, first, last);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
  for (itr = V.begin(); itr != V.end(); ++itr)
  std::cout << *itr << ' ';
  std::cout << '\n';
  */

  size = 500;
  last = 500;
  refill(V, size);
  V.resize(500);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  quickSort(V, first, last);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
  for (itr = V.begin(); itr != V.end(); ++itr)
  std::cout << *itr << ' ';
  std::cout << '\n';
  */
  

  size = 1000;
  last = 1000;
  refill(V, size);
  V.resize(1000);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  quickSort(V, first, last);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
  for (itr = V.begin(); itr != V.end(); ++itr)
  std::cout << *itr << ' ';
  std::cout << '\n';
  */

  size = 5000;
  last = 5000;
  refill(V, size);
  V.resize(5000);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  quickSort(V, first, last);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
  for (itr = V.begin(); itr != V.end(); ++itr)
  std::cout << *itr << ' ';
  std::cout << '\n';
  */

  size = 10000;
  last = 10000;
  refill(V, size);
  V.resize(10000);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  quickSort(V, first, last);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
  for (itr = V.begin(); itr != V.end(); ++itr)
  std::cout << *itr << ' ';
  std::cout << '\n';
  */

  size = 50000;
  last = 50000;
  refill(V, size);
  V.resize(50000);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  quickSort(V, first, last);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
  for (itr = V.begin(); itr != V.end(); ++itr)
  std::cout << *itr << ' ';
  std::cout << '\n';
  */

  size = 100000;
  last = 100000;
  refill(V, size);
  V.resize(100000);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  quickSort(V, first, last);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
  for (itr = V.begin(); itr != V.end(); ++itr)
  std::cout << *itr << ' ';
  std::cout << '\n';
  */

  size = 500000;
  last = 500000;
  refill(V, size);
  V.resize(500000);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  quickSort(V, first, last);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
  for (itr = V.begin(); itr != V.end(); ++itr)
  std::cout << *itr << ' ';
  std::cout << '\n';
  */

  size = 1000000;
  last = 1000000;
  refill(V, size);
  V.resize(1000000);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  quickSort(V, first, last);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
  for (itr = V.begin(); itr != V.end(); ++itr)
  std::cout << *itr << ' ';
  std::cout << '\n';
  */

  std::cout << "\n*** END TESTING FOR QUICKSORT ***\n";
}
