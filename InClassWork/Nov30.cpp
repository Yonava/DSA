#include <vector>

using namespace std;

template <typename T>
T array_max(T a[], size_t n)
{
  T max = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  return max;
}