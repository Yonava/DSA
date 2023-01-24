#include <iostream>
#include <ctime>
#include <string>
#include <random>

template <typename T>
void bubbleSort(T arr[], int n);

template <typename T>
void insertionSort(T arr[], int n);

template <typename T>
void selectionSort(T arr[], int n);

template <typename T>
void mergeSort(T arr[], int left, int right);

template <typename T>
void merge(T arr[], int left, int mid, int right);

template <typename T>
void swap(T &a, T &b);

template <typename T>
void quickSort(T arr[], int left, int right);

template <typename T>
int partition(T arr[], int left, int right);

void generateData(int *data, int n, int range = 100)
{
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> dist(0, range);
  for (int i = 0; i < n; i++)
  {
    data[i] = dist(generator);
  }
}

int main()
{
  std::cout << "Enter the size of the data: ";
  int n;
  std::cin >> n;
  int data[n];

  generateData(data, n);

  std::cout << "name an algorithm (bubble, insertion, selection, merge, or quick): ";
  std::string algorithm;
  std::cin >> algorithm;

  clock_t begin = clock();

  if (algorithm == "bubble")
  {
    bubbleSort(data, n);
  }
  else if (algorithm == "insertion")
  {
    insertionSort(data, n);
  }
  else if (algorithm == "selection")
  {
    selectionSort(data, n);
  }
  else if (algorithm == "merge")
  {
    mergeSort(data, 0, n - 1);
  }
  else if (algorithm == "quick")
  {
    quickSort(data, 0, n - 1);
  }
  else
  {
    std::cout << "Invalid algorithm selected." << std::endl;
  }

  clock_t end = clock();
  double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << "Elapsed time: " << elapsed_time << " seconds" << std::endl;
}

template <typename T>
void swap(T &a, T &b)
{
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
void bubbleSort(T arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

template <typename T>
void insertionSort(T arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    T key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

template <typename T>
void selectionSort(T arr[], int n)
{
  int i, j, minIndex;
  for (i = 0; i < n - 1; i++)
  {
    minIndex = i;
    for (j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }
    swap(arr[minIndex], arr[i]);
  }
}

template <typename T>
void merge(T arr[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;
  T L[n1], R[n2];
  for (int i = 0; i < n1; i++)
  {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++)
  {
    R[j] = arr[mid + 1 + j];
  }
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

template <typename T>
void mergeSort(T arr[], int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

template <typename T>
void quickSort(T arr[], int left, int right)
{
  if (left < right)
  {
    int pivot = partition(arr, left, right);
    quickSort(arr, left, pivot - 1);
    quickSort(arr, pivot + 1, right);
  }
}

template <typename T>
int partition(T arr[], int left, int right)
{
  T pivot = arr[right];
  int i = left - 1;
  for (int j = left; j < right; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[right]);
  return i + 1;
}