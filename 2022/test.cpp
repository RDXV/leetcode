#include "iostream"
#include "chrono"
#include <ctime>
using namespace std;

int main()
{
  clock_t begin = clock();
  for (int i = 0; i < 50000; i++)
  {
    cout << "hello world\n";
  }
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << "Run time = " << elapsed_secs << " seconds\n";
}