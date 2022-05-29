#include <stdio.h>
#include <stdlib.h>
#include<ctime>
#include <iostream>
#include <cstdlib>
using namespace std;
// Функция быстрой сортировки
void quickSort(int *numbers, int left, int right)
{
  int pivot; 
  int l_hold = left; 
  int r_hold = right; 
  pivot = numbers[left];
  while (left < right) 
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--; 
    if (left != right) 
    {
      numbers[left] = numbers[right]; 
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++; 
    if (left != right) 
    {
      numbers[right] = numbers[left]; 
      right--; 
    }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) 
    quickSort(numbers, left, pivot - 1);
  if (right > pivot)
    quickSort(numbers, pivot + 1, right);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    unsigned int start_time = clock();
    for (int j = 0; j < 100; j++) {
        int arr[1000];
        for (int i = 0; i < int((sizeof(arr) / sizeof(arr[0]))); i++)
            arr[i] = rand() % 100 + 1;

        quickSort(arr, 0, 99);
    }
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << search_time / 1000.0 << endl;
}