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

  std::cout << "Enter the sorting algorithm to use (bubble, insertion, or selection): ";
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