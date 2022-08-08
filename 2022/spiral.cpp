#include <iostream>
#include "vector"
using namespace std;

void spiral(int n)
{
  vector<vector<int>> ans(n, vector<int>(n, 0));
  int i = 0, j = 0, i_start = 0, j_start = 0, i_end = n - 1, j_end = n - 1;
  int count = 0;
  int total = n * n;

  while (count < total)
  {

    // left to right for row
    for (j = j_start, i = i_start; j <= j_end && count <= total; j++)
    {
      ans[i][j] = ++count;
    }
    i_start++;

    // go top to bottom
    for (i = i_start, j = j_end; i <= i_end && count <= total; i++)
    {
      ans[i][j] = ++count;
    }
    j_end--;

    // go right to left
    for (j = j_end, i = i_end; j >= j_start && count <= total; j--)
    {
      ans[i][j] = ++count;
    }
    i_end--;

    for (i = i_end, j = j_start; i >= i_start && count <= total; i--)
    {
      ans[i][j] = ++count;
    }
    j_start++;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << ans[i][j] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
    cout << "i and j are " << i << " " << j << "\n"
         << "i_start and i_end are " << i_start << " " << i_end << "\n"
         << "j_start and j_end are " << j_start << " " << j_end << "\n\n";
  }
}

int main()
{
  int n;
  cin >> n;
  spiral(n);
  return 0;
}