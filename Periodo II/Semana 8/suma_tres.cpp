#include <iostream>

using namespace std;

int contarSumaTres(int arr[], int tamano)
{
	int contar = 0;
	
	for(int i = 0; i < tamano; i++)
	{
		for(int j = i + 1; j < tamano; j++)
		{
			for(int k = j + 1; k < tamano; k++)
			{
				cout << arr[i] << arr[j] << arr[k] << endl;
				
				if(arr[i] + arr[j] + arr[k] == 0)
				{
					contar++;
				}
			}
		}
	}
	return contar;
}

int main()
{
	int arr[] = {1, 2, 4};
	int arr2[] = {-1, 3, -2};
	int size = sizeof(arr) / sizeof(arr[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	
	cout << contarSumaTres(arr, size) << endl;
	cout << contarSumaTres(arr2, size2) << endl;
}
