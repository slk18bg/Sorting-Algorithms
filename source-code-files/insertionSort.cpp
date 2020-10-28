/*
 * Sheikh Khaled
 * COP4531- proj1
 *      implementation of insertionSort and its driver program
 */

#include <vector>
#include <iostream>
#include <chrono> // for hi-res clock

void insertionSort(std::vector<int> &a, int length)
{
  int key;
  int j;

  for(int i = 1; i < length; ++i)
  {
    key = a[i];
    j = i - 1;

    // if element j > key, move j to position j + 1
    while (j >= 0 && a[j] > key)
    {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = key;
  }
} // end insertionSort

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
  // create vector and size of vector to be sorted
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

  std::cout << "*** SORTING TIMES FOR INSERTION SORT ***\n";
  std::cout << "\nunsorted array: ";
  for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
  std::cout << "\nsorted array: ";

  auto started = std::chrono::high_resolution_clock::now();
  insertionSort(V, size);
  auto finished = std::chrono::high_resolution_clock::now();
  for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
  std::cout << '\n';
  std::cout << "\nArray size: " << size << '\n';
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
    for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
    std::cout << '\n';
  */

  // refill and resize vector for next test
  size = 50;
  refill(V, size);
  V.resize(50);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  insertionSort(V, size);
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
  insertionSort(V, size);
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
  insertionSort(V, size);
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
  insertionSort(V, size);
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
  insertionSort(V, size);
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
  insertionSort(V, size);
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
  insertionSort(V, size);
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
  insertionSort(V, size);
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
  insertionSort(V, size);
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
  insertionSort(V, size);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
    for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
    std::cout << '\n';
  */

  std::cout << "\n*** END TESTING FOR INSERTION SORT ***\n";
}
