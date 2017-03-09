#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
int arr[51];

void SelectionSort(int* A, int num)
{
	for (int i = 0; i < num-1; i++) // we only need num-2 passes as the last element at num is assumed sorted
	{
		int min = i; // check all elemnts from i to num-1
		cout << "min index in outer loop is: " << min << endl;
		for (int j = i + 1; j < num; j++)
		{
			if (A[j] < A[min])
			{
				min = j; // update the index of the minimum element
				cout << "min index in inner loop is: " << min << endl;
			}
		}
		int temp = A[i];
		cout << "value of temp is: " << temp << endl;
		A[i] = A[min];
		cout << "value of A[min] is: " << A[min] << endl;
		A[min] = temp;
	}
	
}
void BubbleSort(int* A, int num)
{
	/*for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (A[i] > A[j])
				swap(A[i], A[j]);
		}
	}*/

	for (int k = 0; k < num - 2; k++)
	{
		int flag = 0;
		for (int i = 0; i < num - k -1 ; i++)
		{
			if (A[i] > A[i + 1])
			{
				swap(A[i], A[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
 }

void InsertionSort(int* A, int num)
{
}


int PartitionQS(int* A, int start, int end)
{
	int pivot = A[end];
	int pIndex = start; // set partition index as start initially
	for (int i = start; i < end; i++)
	{
		if (A[i] <= pivot)
		{
			swap(A[i], A[pIndex]);
			pIndex++;
		}
	}
	swap(A[pIndex], A[end]); // swap pivot with element at partition Index
	return pIndex;
}

void QuickSort(int* A, int start, int end)
{
	if (start < end)
	{
		int pIndex = PartitionQS(A, start, end); // calling partition function
		QuickSort(A, start, pIndex - 1);
		QuickSort(A, pIndex + 1, end);
	}

}

void MergeMS(int* L, int* R, int* A, int numL, int numR)
{
	int i = 0;
	int j = 0;
	int k = 0;
	
	while (i < numL && j < numR)
	{
		if (L[i] < R[j]) // compare elements in each subarray
		{
			A[k] = L[i];
			i++;
			
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < numL)
	{
		A[k] = L[i];
		i++;
		k++;
	}
	while (j < numR)
	{
		A[k] = R[j];
		j++;
		k++;
	}

}

void MergeSort(int* A, int length)
{
	
	if (length < 2)
		return;
	else
	{
		int mid = length / 2;
		int left = mid;
		int right = length - mid;
		cout << "Value of length of array is : " << length << endl;
		cout << "value of mid is: "<< mid << endl;
		cout << "Value of left(mid) is : " << left << endl;
		cout << "Value of right(length - mid) is : " << right << endl;
		int* L = 0;
		int* R = 0;
		L = new int[left];
		R = new int[right];
		cout << "Left sub-array in Mergesort is : " ;
		for (int i = 0; i <= mid - 1; i++)
		{
			L[i] = A[i];
			cout  << L[i] << " ";
		}
		cout << endl;
		cout << "Right sub-array in Mergesort is : " ;
		for (int j = mid; j <= length - 1; j++)
		{
			R[j - mid] = A[j];
			cout << R[j - mid] << " ";
		}
		cout << endl;
		MergeSort(L, left);
		MergeSort(R, right);
		MergeMS(L, R, A, left, right);
		delete[] L;
		delete[] R;
	}
	
}

void DecimalToBinary(int n)
{
	int arr[100];
	int i = 0;
	while (n > 0)
	{
		int remainder = n % 2;
		arr[i] = remainder;
		i++;
		n = n / 2;
	}
	for (int j = i - 1; j >= 0; j--)
	{
		cout << arr[j] << " ";
	}
	cout << endl;
}

void BinaryToDecimal(long bin)
{
	long dec = 0, rem, base = 1;
	while (bin > 0)
	{
		rem = bin % 10;
		dec = dec + rem*base;
		base = base * 2;
		bin = bin / 10;
	}
	cout << dec << endl;
}

void ReverseStringI(char *str) // iterative
{
	char *begin, *end, temp;
	int length, count;
	length = strlen(str) - 1;
	//cout << "The length of the string is " << length << endl;
	begin = str;
	end = str;
	//cout << "The begin pointer points to " << begin << endl;
	//cout << "The end pointer points to " << end << endl;
	for (count = 0; count < length; count++)
		end++; // take the second pointer to the end of the string length. 
	//cout << "The begin pointer points to " << begin << endl;
	//cout << "The end pointer points to " << end << endl;
	for (count = 0; count < (length / 2); count++)
	{
		temp = *end;
		//cout << "The count is  " << count << " and the value in temp is  " << temp << endl;
		*end = *begin;
		//cout << "The value at *end is " << *end << endl;
		*begin = temp;
		//cout << "The value at *begin is " << *begin << endl;
		begin++;
		end--;
	}
}

void ReverseStringR(char* str, int begin, int end)
{
	char c;
	if (begin >= end)
		return;
	c = *(str + begin);
	*(str + begin) = *(str + end);
	*(str + end) = c;
	ReverseStringR(str, ++begin, --end);
}

void OddOrEven()
{
	int x;
	cout << " Enter the number to determine if it is odd or even" << endl;
	cin >> x;

	/*if (x % 2 == 0)*/ if((x & 1) == 0)
		cout << x << " is even!" << endl;
	else
		cout << x << " is odd! " << endl;
	getchar();
}

int FindFactorial(int num)
{
	int factorial = 0;;
	if (num == 0)
	{
		factorial = 1;
	}
	else
	{
		 factorial = num * FindFactorial(num - 1);
	}
	return factorial;
}

void FindIfPrime(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num %i == 0)
		{
			cout << num << " is not a prime number!! ";
			return;
		}
	}
	cout << num << " is a prime number!! ";
	
}


int Fibonacci(int num)
{
	if (num <= 1)
		return num;
	if (arr[num] != -1)
		return arr[num];
	else
	{
		arr[num] = Fibonacci(num - 1) + Fibonacci(num - 2);
		return arr[num];
	}
	
}

int Exponentiation(int base, int pow)
{
	if (pow == 0)
		return 1;
	else
		return base * Exponentiation(base, pow - 1);
}

void PrintRecursively(char *t)
{
	if (*t == '\0')
		return;
	else
	{
		cout << "Now printing " << *t << " ";
		t++;
		PrintRecursively(t);
	}
}

int MyStrCmp(const char *s1, const char *s2)
{
	int cmp = -1;
	while (*s1 == *s2)
	{
		if ((*s1 == '\0') || (*s2 == '\0'))
			break;
		s1++;
		s2++;
	}
	if ((*s1 == '\0') && (*s2 == '\0'))
		cmp = 0;
	return cmp;
}

void MyStrCat(char *original, char *add)
{
	while (*original)
	{
		original++;
	}
	
	while (*add)
	{
		*original = *add;
		add++;
		original++;
		
	}
	*original = '\0';
	
}



void MyStrCpy(char *target, char *source)
{
	while (*source != '\0')
	{
		*target = *source;
		source++;
		target++;
	}
	*target = '\0';
}

int MyStrLen(char *str)
{
	int length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return length;
}

void FindIfPalindrome(char* str)
{
	int length = MyStrLen(str);
	char *buffer = (char*)malloc(length + 1);
	MyStrCpy(buffer, str);
	ReverseStringI(buffer);
	if (MyStrCmp(buffer, str) == 0)
		cout << "The string " << str << " is a palindrome.";
	else
		cout << "The string " << str << " is not a palindrome.";
	free(buffer);
}

void GetIPAddr()
{
	system("C:\\Windows\\System32\\ipconfig");
}

void CheckFreqOfChar(char *str,  int *frequency)
{
	int index;
	for (index = 0; str[index] != '\0'; index++)
	{
		cout << "The index is " << index << " and the character at  " << index << " in the input string is " << str[index] << endl;
		frequency[str[index]]++;
	}
}

bool CheckAnagram(char *str1, char *str2)
{
	bool IsAnag = false;
	int freq1[256] = { 0 };
	int freq2[256] = { 0 };

	if (MyStrLen(str1) != MyStrLen(str2))
		return IsAnag;
	
	for (int i = 0; str1[i] != '\0'; i++)
		freq1[str1[i]]++;

	for (int i = 0; str2[i] != '\0'; i++)
		freq2[str2[i]]++;

	for (int i = 0; i < 256; i++)
	{
		if ((freq1[i] != freq2[i]))
			return IsAnag;
	}
	return IsAnag = true;	

}

void StrToUpper(string str)
{
	/*while (!str.end())
	{
		*str -= 32;
		str++;
	}*/
	
	if (str.empty())
		return;
	for (int i = 0; i < str.length(); i++)
	{
		str.at(i) -= 32;
	}
	cout << "The uppercase version of the string is " << str << endl;
}

void StrToLower(string str)
{
	/*while (!str.end())
	{
	*str -= 32;
	str++;
	}*/

	if (str.empty())
		return;
	for (int i = 0; i < str.length(); i++)
	{
		str.at(i) += 32;
	}
	cout << "The lowercase version of the string is " << str << endl;
}

int ReverseNumber(int num)
{
	int reverse = 0;
	while (num != 0)
	{
		reverse = reverse * 10;
		reverse += num % 10;
		num = num / 10;
	} 

	return reverse;
}

int MaximumInArray(int *arr, int arr_size)
{
	int maximum = arr[0];
	for (int i = 0; i < arr_size; i++)
	{
		if (arr[i] >= maximum)
			maximum = arr[i];
	}
	return maximum;
}

int MinimumInArray(int *arr, int arr_size)
{
	int minimum = arr[0];
	for (int i = 0; i < arr_size; i++)
	{
		if (arr[i] <= minimum)
			minimum = arr[i];
	}
	return minimum;
}

int BinarySearch(int arr[], int first, int last, int value)
{
	int midval = 0;
	
	if (first >= last)
		   return -1;
	else
	{
		midval = (first + last) / 2;
		if (arr[midval] == value)
			return midval;
			
		else
		{
			if (value < arr[midval])
				return BinarySearch(arr, first, midval - 1, value);
			else if(value > arr[midval])
				return BinarySearch(arr, midval + 1, last,  value);
		}
		
	}
	
}

void InsertInArray(int *arr, int size, int val, int pos)
{
	int i = 0;
	for ( i = size - 1; i >= pos - 1; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[pos - 1] = val;
	
}

void DeleteFromArray(int *arr, int size, int pos)
{
	for (int i = pos - 1; i < size; i++)
		arr[i] = arr[i + 1];
}

int main()
{
	/*for (int i = 0; i < 51; i++)
		arr[i] = -1;*/
	/*int A[10] = { 24, 12, 3, 56, 87, 5, 100, 250, 43, 91 };
	cout << "QuickSort" << endl;
	QuickSort(A, 0, 9);
	cout << "MergeSort" << endl;
	MergeSort(A, 10);
	cout << "SelectionSort" << endl;
	SelectionSort(A, 10);
	cout << "BubbleSort" << endl;
	BubbleSort(A, 10);
	for (int i = 0; i < 10; i++)
		cout << A[i] << " ";*/

	//char A[6] = { 'H', 'E', 'L', 'L', 'O', '\0' };
	//char str[100];
	//char str1[50];
	//char str2[50];
	//cout << "Please input your string to be reversed : ";
	//cin >> str;
	 //ReverseStringI(str);
	//ReverseStringR(str, 0, strlen(str) - 1);
	//cout << str << endl;
//	int num, x, y;
	// cout << "Please input your number to get its factorial " << endl;
	// cin >> num;
	// x = FindFactorial(num);
	//cout << "The factorial of " << num << "is " << x << endl;
	//OddOrEven();
	/* cout << "Please input your number to check if it is a prime number:  " ;
	  cin >> num;
	  FindIfPrime(num);*/
	  
	/* cout << "Please input your number to generate its fibonacci sequence:  " ;
	  cin >> num;
	 x =  Fibonacci(num);
	 cout << "The Fibonacci sequence of  " << num << " is  " << x;*/
	/*cout << "Please input your base:  ";
	cin >> num;
	cout << "Please input your power: ";
	cin >> y;
	x = Exponentiation(num, y);
	cout << "The exponentiation of  " << num << " to the power " << y <<" is  " << x;*/
	/*cout << "Please input your string to be printed recursively : ";
	cin >> str;
	PrintRecursively(str);*/
	/*cout << "Enter string s1: ";
	cin >> str1;
	cout << "Enter string s2: ";
	cin >> str2;
	x = MyStrCmp(str1, str2);
	if (x == 0)
		cout << "The strings are equal! ";
	else
		cout << "The strings are not equal !! ";*/
	/*char original[100];
	char add[100];
	cout << "Enter string s1: ";
	cin >> original;
	cout << "Enter string s2: ";
	cin >> add;
	MyStrCat(original, add);
	cout << " The concatenated string is " << original << " ";*/
	/*char source[100];
	char destination[100];
	cout << "Enter the string that needs to be copied: ";
	cin >> source;
	MyStrCpy(destination, source);
	cout << " The copied string is " << destination << " ";*/
	/*cout << "Enter the string whose length needs to be calculated: ";
	cin >> str;
	int len = 0;
	len = MyStrLen(str);
	cout << "The length of " << str << " is " << len << endl;*/
	/*char pal[100];
	cout << "Enter the string to check if palindrome ";
	cin >> pal;
	FindIfPalindrome(pal);*/
	/*char arr1[100], arr2[100];
	
	cout << " Enter the first string for anagram check: ";
	cin >> arr1;
	cout << " Enter the second string for anagram check: ";
	cin >> arr2;
	bool check = CheckAnagram(arr1, arr2);
	if (check)
		cout << arr1 << " and " << arr2 << " are anagrams";
	else
		cout << arr1 << " and " << arr2 << " are not anagrams";*/
	//GetIPAddr();
	/*char string[100];
	int frequency[256] = { 0 };
	cout << "Enter the string to count frquency of characters: ";
	cin >> string;
	CheckFreqOfChar(string, frequency);
	
	cout << endl;
	for (int i = 0; i < 256; i++)
	{
		if (frequency[i] != 0)
		{
			cout << (char)i << " occurs " << frequency[i] << " times " << "in the string " << string << endl;
		}
		
	}*/
//   char ToUpper[100];
//   string ToUpper, ToLower;
//   cout << "Enter the string to be converted to upper case : ";
//   getline(cin, ToUpper);
//   StrToUpper(ToUpper);
//   cout << "Enter the string to be converted to lower case : ";
//   getline(cin, ToLower);
//   StrToLower(ToLower);
//   long n;
//   DecimalToBinary(10);
//   cout << "enter a binary number: ";
//   cin >> n;
//   BinaryToDecimal(n);
//   cout << endl;
//int NumToReverse;
//cout << "Please enter the number to be reversed: ";
//cin >> NumToReverse;
//int ReversedNumber = ReverseNumber(NumToReverse);
//cout << "The reversed number is " << ReversedNumber << endl;

//int arr[10];
//for (int i = 0; i < 10; i++)
//{
//	arr[i] = 2 * i + 2;
//	cout << arr[i] << " ";
//}
//cout << endl;
//int max = MaximumInArray(arr, 10);
//cout << "The maximum element in the array is " << max << endl;
//int min = MinimumInArray(arr, 10);
//cout << "The minimum element in the array is " << min << endl;
//cout << "Enter the number to be serached in the sorted array: ";
//int key = 0;
//cin >> key;
//int index = BinarySearch(arr, 0, 9, key);
//if (index != -1)
//
//cout << "The value " << key << " was located at index " << index << " in the sorted array " << endl;
//else
//cout << "The value " << key << " was not found in the sorted array " << endl;
//getchar();
int arr[20];
int size=0;
int elem=0;
int pos=0;
int i;

cout << "Please enter the number of elements in the array: ";
cin >> size;
cout << "Enter the elements: ";
for ( i = 0; i < size; i++)
{
	cin >> arr[i];
}
//cout << "Enter the element that you want to insert into this array now: ";
//cin >> elem;
//cout << "Enter the position in the array that you want to insert the element in: ";
cout << "Enter the position at which array element has to be deleted: ";
cin >> pos;
//InsertInArray(arr, size, elem, pos);
DeleteFromArray(arr, size, pos);
//cout << "The array after insertion of element " << elem << " at position" << pos << " is : " << endl;
cout << "The array after deletion of element at position " << pos << " is : " << endl;
for (i = 0; i <=size; i++)
{
	cout << arr[i] << endl;
}
getchar();
  cout << "  Press any key to continue";
  getchar();
return 0;
}

