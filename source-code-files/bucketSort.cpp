/*
 * Sheikh Khaled
 * COP4531- proj1 Algorithm Analysis
 *
 * Implementation of bucketSort along with the driver program to test it
 */

#include <vector>
#include <algorithm> // for std::sort
#include <iostream>
#include <chrono> // for hi-res clock, measured in ns

void bucketSort(std::vector<double> &a, int size)
{
  // create b empty buckets of size a
  size = a.size();
  std::vector<std::vector<double> > b;
  b.resize(size);
  for (int i = 0; i < size; ++i)
  {
    int bucketIndex = size * a[i]; // index in bucket
    b[bucketIndex].push_back(a[i]);
  }

  // sort each bucket
  for (int i = 0; i < size; ++i)
    std::sort(b[i].begin(), b[i].end());

  // concatenate all buckets to the array
  int index = 0;
  for (int i = 0; i < size; ++i)
  {
    for (unsigned int j = 0; j < b[i].size(); ++j)
      a[index++] = b[i][j];
  }
} // end bucketSort

// to refill vectors to the next testing size
void refill(std::vector<double> &v, int size)
{
  for (int i = 0; i < size; ++i)
  {
    double val = ((double) std::rand() / (RAND_MAX));
    val = (int) (val * 100 + 0.4);
    val = (val / 100);
    v.push_back(val);

    // occasionally a 1 is generated which causes the sorting program to seg
    // fault
    // the workaround is as follows: if a 1 is detected in the vector, it is
    // replaced with 0.99
    if (v.at(i) == 1)
      v.at(i) = 0.99;
  }
} // end refill

int main()
{
  // create array & size of array to be sorted
  std::vector<double> V;
  int size = 10;

  srand((unsigned int)time(nullptr));

  // fill vector here
  for (int i = 0; i < size; ++i)
  {
    double val = ((double) std::rand() / (RAND_MAX));
    val = (int) (val * 100 + 0.4);
    val = (val / 100);
    V.push_back(val);

    if (V.at(i) == 1)
      V.at(i) = 0.99;
  }

  std::vector<double>::iterator itr;

  // format output here
  std::cout << "*** SORTING TIMES FOR BUCKET SORT ***\n";
  std::cout << "\nunsorted array: ";
  for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
  std::cout << '\n';
  std::cout << "sorted array: ";

  auto started = std::chrono::high_resolution_clock::now();
  bucketSort(V, size);
  auto finished = std::chrono::high_resolution_clock::now();
  for (itr = V.begin(); itr != V.end(); ++itr)
    std::cout << *itr << ' ';
  std::cout << '\n';

  std::cout << "\nArray size: " << size << '\n';
  //printf("Time taken to sort: %.5f sec\n", difftime(end, start));
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";

  // refill and resize vector for next test
  size = 50;
  refill(V, size);
  V.resize(50);

  std::cout << "Array size: " << size << '\n';
  started = std::chrono::high_resolution_clock::now();
  bucketSort(V, size);
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
  bucketSort(V, size);
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
  bucketSort(V, size);
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
  bucketSort(V, size);
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
  bucketSort(V, size);
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
  bucketSort(V, size);
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
  bucketSort(V, size);
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
  bucketSort(V, size);
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
  bucketSort(V, size);
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
  bucketSort(V, size);
  finished = std::chrono::high_resolution_clock::now();
  std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finished - started).count() << " nanosec\n";
  /*
  for (itr = V.begin(); itr != V.end(); ++itr)
  std::cout << *itr << ' ';
  std::cout << '\n';
  */

  std::cout << "\n*** END TESTING FOR BUCKET SORT ***\n";
}
