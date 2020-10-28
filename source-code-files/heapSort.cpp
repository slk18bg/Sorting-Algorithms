/*
 * Sheikh Khaled
 * COP4531- proj1
 *    implementation of heap sort and helper function heapify along with driver
 *    program for testing
 */

#include <vector>
#include <algorithm> // for std::swap
#include <iostream>
#include <chrono> // for hi-res clock

void heapify(std::vector<int> &a, int size, int root) // helper for heapSort
{

  int largest = root;
  int left = 2 * root + 1;
  int right = 2 * root + 2;

  // if left <= heap-size[a], a[left] > a[i]
  if (left < size && a[left] > a[largest]) largest = left;

  // if right >= largest
  if (right < size && a[right] > a[largest]) largest = right;

  // largest != root
  if (largest != root)
  {
    std::swap(a[root], a[largest]);
    heapify(a, size, largest);
  }

} // end heapify

void heapSort(std::vector<int> &a, int size)
{
  // build heap
  for (int i = size / 2 - 1; i >= 0; --i)
    heapify(a, size, i);

  // do for each element 1 by 1
  for (int i = size - 1; i >= 0; --i)
  {
    std::swap(a[0], a[i]);
    heapify(a, i, 0);
  }
} // end heapSort

// to refill vectors to the next testing size
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
  // create vector & size of vector to be sorted
  std::vector<int> V;
  int size = 10;

  // generate random values each time
  srand((unsigned int)time(nullptr));

  // fill vector here
  for (int i = 0; i < size; ++i)
  {
    int val = (std::rand() % 20000);
    V.push_back(val);
  }

  std::vector<int>::iterator itr;

  std::cout << "*** SORTING TIMES FOR HEAP SORT ***\n";
  std::cout << "\nunsorted array: ";

  for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
  std::cout << '\n';

  std::cout << "sorted array: ";
  auto started = std::chrono::high_resolution_clock::now();
  heapSort(V, size);
  auto finished = std::chrono::high_resolution_clock::now();
  for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
  std::cout << '\n';

  std::cout << "\nArray size: " << size << '\n';
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";

  size = 50;
  refill(V, size);
  V.resize(50);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  heapSort(V, size);
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
  heapSort(V, size);
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
  heapSort(V, size);
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
  heapSort(V, size);
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
  heapSort(V, size);
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
  heapSort(V, size);
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
  heapSort(V, size);
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
  heapSort(V, size);
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
  heapSort(V, size);
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
  heapSort(V, size);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
  for (itr = V.begin(); itr != V.end(); ++itr)
  std::cout << *itr << ' ';
  std::cout << '\n';
  */

  std::cout << "\n*** END TESTING FOR HEAP SORT ***\n";
}
