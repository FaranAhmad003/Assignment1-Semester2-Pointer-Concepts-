#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void display(int& size1, int& size2, int* arr2)
{

	for (int i = 0; i < (size1 + size2); i++)
	{
		cout << arr2[i] << " ";
	}
}
void swap(int* a, int* b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void bubblesort(int* arr, int size) {
	/*int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (*(arr + j) > (*(arr + (j + 1)))) {
				swap(*(arr + j), arr[j + 1]);
			}
		}
	}*/
	for (int* iptr = arr; iptr < arr + size - 1; iptr++) {
		for (int* jptr = iptr + 1; jptr < arr + size; jptr++) {
			if (*jptr < *iptr) {
				swap(jptr, iptr);
			}
		}
	}

	
}
	

void print(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "ARRAY["<<i<<"] " << " : " << *(arr + i) << " " << endl;
	}
}
int* inputArray(ifstream& file, int& size_of_array)
{

	int values;
	file >> size_of_array;
	cout << "SIZE OF DYNAMIC ARRAY : " << size_of_array << endl;


	//check for negative value
	if (size_of_array <= 0)                 //not handled exception here


		return 0;

	//size : now making dynamic array using size from file
	int* dynamic_array;
	dynamic_array = new int[size_of_array];

	//fetching values from file
	for (int i = 0; i < size_of_array; i++) {
		
		file >> values;
		*(dynamic_array + i) = values;

	}
	cout << "ARRAY BEFORE SORTING : "<<endl;
	for (int i = 0; i < size_of_array; i++) {
		cout << "array["<<i<<"] : " << *(dynamic_array + i) << endl;
	}

	return dynamic_array;

}
int* MergeArrays(int* arr1, int* arr2, int Size1, int Size2 )
{
	// Allocating memory dynamically for new merged arrays
	int* mergedarray = new int[Size1 + Size2];  


	int* temporary_array1 = arr1, * temporary_array2 = arr2, * temporary_mergedarray = mergedarray;      //temporary2 for storing array2 temporarily
	int* end_array1 = (arr1 + Size1) - 1, *end_array2 = (arr2 + Size2) - 1;      // end_array1 = 000001DC23BAFB68(firstarray)
																				//	*end_arrayptr = 00000191F2A702CC (secondarray)   		

	while (temporary_array1 <= end_array1 && temporary_array2 <= end_array2)
	{
		                                            
 
		if (*temporary_array1 < *temporary_array2)            //stores array1 in mergedarray if arr1 smaller than2
		{
			*temporary_mergedarray = *temporary_array1;
			temporary_mergedarray++, temporary_array1++;
		}

		                               
		else
		{
			*temporary_mergedarray = *temporary_array2;
			temporary_mergedarray++;
			temporary_array2++;   //else stores array2 in merged array
		}


	}


	if (temporary_array1 > end_array1)
	{
		while (temporary_array2 <= end_array2)
		{
			*temporary_mergedarray = *temporary_array2;     //check for arr1 and 2 if smaller greater than writing in front of it
			temporary_mergedarray++;
				temporary_array2++;
		}
	}


	else
	{
		while (temporary_array1 <= end_array1)
		{
			*temporary_mergedarray = *temporary_array1; 
			temporary_mergedarray++;
			temporary_array1++;
		}
	}

	return mergedarray;
}

int main()
{
		//storing values in 2 arrays
		int size1 = 0, size2 = 0;

		ifstream file("DATA2.txt");
		//error message for not being opened
		if (!file.is_open())
		{
			cout << "Error: CANT OPEN THIS FILE.";
			return 0;
		}
		//hardcore loop 
		for (int i = 1; i <= 3; i++)

		{


			cout << "TEST CASE : \t " << i << ":" << endl;
			file >> size1;
			if (size1 < 0)
			{

				cout << "---ERROR: SIZE CAN NOT BE SMALLER THAN ZERO---";    //error message
				return 0;
			}



			cout << "THE SIZE OF ARRAY IS :\t" << size1 << endl;
			int  value = 0, file_value = 0;
			int* array3 = new int[size1];
			while (value < size1)
			{
				file >> file_value;             
				array3[value] = file_value;
				value++;
			}
			
			cout << "ARRAY1 NUMBERS: ";
			for (value = 0; value < size1; value++) {         
				cout << array3[value] << " ";
			}
			cout << endl;




			file >> size2;
			cout << "SIZE OF ARRAY 2 :" << size2 << endl;    //picking size for array2
			int  variable_temp = 0, y = 0;
			int* array1 = new int[size2];
			while (variable_temp < size2)
			{
				file >> y;
				array1[variable_temp] = y;
				variable_temp++;
			}
			cout << "ARRAY NUMBERS: ";
			for (variable_temp = 0; variable_temp < size2; variable_temp++) {    //displays array
				cout << array1[variable_temp] << " ";
			}
			cout << endl;



			//merging arrays
			int* array2 = new int[size1 + size2];
			array2 = MergeArrays(array3, array1, size1, size2);
			cout << "The merged array is:" << endl;
			display(size1, size2, array2);
		 cout<<endl;
			cout << "--------------------------------" << endl;
			cout << endl << endl;



			//clearing 
			delete[]array1;
			delete[]array2;
			delete[]array3;
		}
		file.close();
		return 0;






		//-----------------------------------------------------------------------------------------------------------------------------------


	//int size_of_array = 0;
	//int* dynamicarray = new int[size_of_array];

	//ifstream file("DATA1.txt");
	//if (!file.is_open()) {
	//	cout << "NO FILE EXIST!" << endl;
	//	return 0;
	//}

	//for (int i = 1; i <= 3; i++)
	//{ 
	//	cout << "TEST CASE " << i << " : " << endl;
	//	dynamicarray = inputArray(file, size_of_array);

	//	//inserting values from file to program

	//	cout << endl;;
	//	
	//	if (size_of_array <= 0)
	//	{
	//		cout << "Error: Array Size should be greater than zero.";     //error message
	//		return 0;
	//	}
	//	//bubblesorting the array
	//	bubblesort(dynamicarray, size_of_array);
	//	cout << "----BUBBLE - SORTING -------" << endl;
	//	print(dynamicarray, size_of_array);
	//	cout << "----------------------------"<<endl;
	//	
	//	cout << endl << endl;
	//	delete[]dynamicarray;
	//}
	//file.close();



}