#include <vector>
#include <iostream>

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

int main() {
  int const arr_size = 6;
  int arr[arr_size] = {1, 2, 3, 6, 4, 5};
  int max = array_max(arr, arr_size);
  cout << max << endl;
}