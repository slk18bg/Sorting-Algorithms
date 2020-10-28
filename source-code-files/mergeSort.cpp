/*
 * Sheikh Khaled
 * COP4531- proj1 Algorithm Analysis
 *   implementation of  helper function merge and mergeSort along with its
 * driver program for testing
 */

#include <vector>
#include <iostream>
#include <chrono> // for hi-res clock

void merge(std::vector<int> &left, std::vector<int> &right, std::vector<int> &v)
{
  // vector v is partitioned into
  // two sub vectors left and right
  // then sorted and merged back into v

  // for each subarray size
  int lsize = left.size();
  int rsize = right.size();

  // indices of each vector
  int i = 0;
  int j = 0;
  int k = 0;

  // split and copy v to each subvector
  while (j < lsize && k < rsize)
  {
    if (left[j] < right[k])
    {
      v[i] = left[j];
      ++j;
    }
    else
    {
      v[i] = right[k];
      ++k;
    }
    ++i;
  } // end while

  while (j < lsize)
  {
    v[i] = left[j];
    ++j; 
    ++i;
  }

  while (k < rsize)
  {
    v[i] = right[k];
    ++k; 
    ++i;
  }

} // end merge

void mergeSort(std::vector<int> &v)
{
  if (v.size() <= 1) return;

  int mid = v.size() / 2;
  std::vector<int> left;
  std::vector<int> right;

  for (int j = 0; j < mid; ++j)
    left.push_back(v[j]);
  for (int j = 0; j < (v.size()) - mid; ++j)
    right.push_back(v[mid + j]);

  // sort each half
  mergeSort(left);
  mergeSort(right);
  merge(left, right, v);

} // end mergeSort

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
  // create array & size of array to be sorted
  std::vector<int> V;
  int size = 10;

  srand((unsigned) time(nullptr));

  // fill arrays here
  for (int i = 0; i < size; ++i)
  {
    int val = (std::rand() % 20000 );
    V.push_back(val);
  }

  std::vector<int>::iterator itr;

  std::cout << "*** SORTING TIMES FOR MERGE SORT ***\n";
  std::cout << "\nunsorted array: ";
  for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
  std::cout << "\nsorted array: ";

  auto started = std::chrono::high_resolution_clock::now();
  mergeSort(V);
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
  mergeSort(V);
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
  mergeSort(V);
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
  mergeSort(V);
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
  mergeSort(V);
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
  mergeSort(V);
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
  mergeSort(V);
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
  mergeSort(V);
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
  mergeSort(V);
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
  mergeSort(V);
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
  mergeSort(V);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
    for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
    std::cout << '\n';
  */

  std::cout << "\n*** END TESTING FOR MERGE SORT ***\n";
}
