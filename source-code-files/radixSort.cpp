/*
 * Sheikh Khaled
 * COP4531- proj1 Algorithm Analysis
 *      Implementation of radixSort along with helper functions findMax and
 * stable algorithm countSort
 *      driver program implemented as well for testing the algorithm
 */

#include <vector>
#include <iostream>
#include <chrono> // for hi-res clock

int findMax(std::vector<int> &a, int size)
{
  //int max = a[0];
  int max;
  for (int i = 1; i < size; ++i)
    if (a[i] > max) // if current element is > max, current element = max
      max = a[i];

  return max;
}

// helper countSort function
void countSort(std::vector<int> &a, int size, int d)
{
  std::vector<int> temp;
  temp.resize(size);
  std::vector<int> count(10, 0);

  // store amount of occurrences to count[]
  for(int i = 0; i < size; ++i)
    ++count[(a[i] / d) % 10];

  // adjust count[] to reflect the actual positions of digit d
  for(int i = 1; i < 10; ++i)
    count[i] += count[i - 1];

  // move to temporary vector
  for(int i = (size - 1); i >= 0; --i)
  {
    temp[count[(a[i] / d) % 10] - 1] = a[i];
    --count[(a[i] / d) % 10];
  }

  // copy to vector in sorted order
  for(int i = 0; i < size; i++)
    a[i] = temp[i];
} // end countSort

void radixSort(std::vector<int> &a, int size)
{
  int max = findMax(a, size);
  for (int i = 1; (max / i) > 0; i *= 10)
    countSort(a, size, i);
}

// to refill vectors for the next testing size
void refill(std::vector<int> &v, int size)
{
  for (int i = 0; i < size; ++i)
  {
    int val = (std::rand() % 20000);
    v.push_back(val);
  }
} // end refill

int main()
{
  // create array & size of array to be sorted
  std::vector<int> V;
  int size = 10;

  srand((unsigned int)time(nullptr));

  // fill vector here
  for (int i = 0; i < size; ++i)
  {
    int val = (std::rand() % 20000);
    V.push_back(val);
  }

  std::vector<int>::iterator itr;

  std::cout << "*** SORTING TIMES FOR RADIX SORT ***\n";
  std::cout << "\nunsorted array: ";
  for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
  std::cout << '\n';
  std::cout << "sorted array: ";

  auto started = std::chrono::high_resolution_clock::now();
  radixSort(V, size);
  auto finished = std::chrono::high_resolution_clock::now();
  for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
  std::cout << '\n';
  std::cout << "\nArray size: " << size << '\n';
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";

  // refill and resize vector for next test
  size = 50;
  refill(V, size);
  V.resize(50);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  radixSort(V, size);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
    for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
    std::cout << '\n';
    */

  size = 100;
  refill(V, size);
  V.resize(100);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  radixSort(V, size);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
    for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
    std::cout << '\n';
  */

  size = 500;
  refill(V, size);
  V.resize(500);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  radixSort(V, size);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
    for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
    std::cout << '\n';
  */

  size = 1000;
  refill(V, size);
  V.resize(1000);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  radixSort(V, size);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
    for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
    std::cout << '\n';
  */

  size = 5000;
  refill(V, size);
  V.resize(5000);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  radixSort(V, size);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
    for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
    std::cout << '\n';
  */

  size = 10000;
  refill(V, size);
  V.resize(10000);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  radixSort(V, size);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
    for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
    std::cout << '\n';
  */

  size = 50000;
  refill(V, size);
  V.resize(50000);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  radixSort(V, size);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
    for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
    std::cout << '\n';
  */

  size = 100000;
  refill(V, size);
  V.resize(100000);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  radixSort(V, size);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
    for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
    std::cout << '\n';
  */

  size = 500000;
  refill(V, size);
  V.resize(500000);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  radixSort(V, size);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
    for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
    std::cout << '\n';
  */

  size = 1000000;
  refill(V, size);
  V.resize(1000000);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  radixSort(V, size);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
    for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
    std::cout << '\n';
  */

  std::cout << "\n*** END TESTING FOR RADIX SORT ***\n";
}
