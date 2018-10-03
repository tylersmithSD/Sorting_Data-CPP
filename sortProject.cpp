/* Tyler Nathan Smith
   Sort Project (C++) */

// Reference libraries
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctime>

// Sorting Functions
void mergesort(int *arr, int sizeOfArray, int first, int last);
void merge(int *arr, int sizeOfArray, int first, int middle, int last);
void insertionSortArray(int *arr,int sizeOfArray);
int partition(int *arr, const int left, const int right);
void quicksort(int *arr, const int left, const int right, const int sz);

// Other Functions
void randomGenerate(int *arr,int sizeOfArray);
void printArray(int *arr,int sizeOfArray);
void printSteps();
void printExecutionTime();

// Variables
int unsortedHundredArray[99];
int unsortedThousandArray[999];
int unsortedFiveThousandArray[4999];
int unsortedTenThousandArray[9999];
int hundredArray[99];
int thousandArray[999];
int fiveThousandArray[4999];
int tenThousandArray[9999];
int stepsCount;
int stepsCountArray[11];
float elapsedTime[11];
void calculateAverageTime();

int main()
{
    // Initialize random time generate
    srand((int)time(0)); //Seed for random number


    // Random generate all the arrays
    randomGenerate(unsortedHundredArray,      sizeof unsortedHundredArray/sizeof(int));
    randomGenerate(unsortedThousandArray,     sizeof unsortedThousandArray/sizeof(int));
    randomGenerate(unsortedFiveThousandArray, sizeof unsortedFiveThousandArray/sizeof(int));
    randomGenerate(unsortedTenThousandArray,  sizeof unsortedTenThousandArray/sizeof(int));


    //Print the two unsorted arrays
    std::cout << "Hundred Array Unsorted: ";
    printArray(unsortedHundredArray, sizeof unsortedHundredArray/sizeof(int));
    std::cout << std::endl;
	std::cout << std::endl;

    std::cout << "Thousand Array Unsorted: ";
    printArray(unsortedThousandArray, sizeof unsortedThousandArray/sizeof(int));
    std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


    //Insertion Sort the arrays
    memmove( hundredArray, unsortedHundredArray, sizeof(hundredArray));
    insertionSortArray(hundredArray, sizeof hundredArray/sizeof(int));
    stepsCountArray[0] = stepsCount;
    stepsCount = 0;

    memmove( thousandArray, unsortedThousandArray, sizeof(thousandArray));
    insertionSortArray(thousandArray, sizeof thousandArray/sizeof(int));
    stepsCountArray[1] = stepsCount;
    stepsCount = 0;

    memmove( fiveThousandArray, unsortedFiveThousandArray, sizeof(fiveThousandArray));
    insertionSortArray(fiveThousandArray, sizeof fiveThousandArray/sizeof(int));
    stepsCountArray[2] = stepsCount;
    stepsCount = 0;

    memmove( tenThousandArray, unsortedTenThousandArray, sizeof(tenThousandArray));
    insertionSortArray(tenThousandArray, sizeof tenThousandArray/sizeof(int));
    stepsCountArray[3] = stepsCount;
    stepsCount = 0;

    // Print the two insertion sorts
    std::cout << "Hundred Array Insertion Sorted: ";
    printArray(hundredArray, sizeof hundredArray/sizeof(int));
    std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Thousand Array Insertion Sorted: ";
    printArray(thousandArray, sizeof thousandArray/sizeof(int));
    std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	//Merge Sort the arrays
    memmove(hundredArray, unsortedHundredArray, sizeof(hundredArray));
    mergesort(hundredArray, sizeof hundredArray/sizeof(int), 0, sizeof hundredArray/sizeof(int));
    stepsCountArray[4] = stepsCount;
    stepsCount = 0;

    memmove(thousandArray, unsortedThousandArray, sizeof(thousandArray));
    mergesort(thousandArray, sizeof thousandArray/sizeof(int), 0, sizeof thousandArray/sizeof(int));
    stepsCountArray[5] = stepsCount;
    stepsCount = 0;

    memmove(fiveThousandArray, unsortedFiveThousandArray, sizeof(fiveThousandArray));
    mergesort(fiveThousandArray, sizeof fiveThousandArray/sizeof(int), 0, sizeof fiveThousandArray/sizeof(int));
    stepsCountArray[6] = stepsCount;
    stepsCount = 0;

    memmove(tenThousandArray, unsortedTenThousandArray, sizeof(tenThousandArray));
    mergesort(tenThousandArray, sizeof tenThousandArray/sizeof(int), 0, sizeof tenThousandArray/sizeof(int));
    stepsCountArray[7] = stepsCount;
    stepsCount = 0;

    // Print the two merge sorts
    std::cout << "Hundred Array Merge Sorted: ";
    printArray(hundredArray, sizeof hundredArray/sizeof(int));
    std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Thousand Array Merge Sorted: ";
    printArray(thousandArray, sizeof thousandArray/sizeof(int));
    std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	// Quick Sort the arrays
    memmove(hundredArray, unsortedHundredArray, sizeof(hundredArray));
    quicksort(hundredArray, 0, sizeof hundredArray/sizeof(int), sizeof hundredArray/sizeof(int));
    stepsCountArray[8] = stepsCount;
    stepsCount = 0;

    memmove(thousandArray, unsortedThousandArray, sizeof(thousandArray));
    quicksort(thousandArray, 0, sizeof thousandArray/sizeof(int), sizeof thousandArray/sizeof(int));
    stepsCountArray[9] = stepsCount;
    stepsCount = 0;

    memmove(fiveThousandArray, unsortedFiveThousandArray, sizeof(fiveThousandArray));
    quicksort(fiveThousandArray, 0, sizeof fiveThousandArray/sizeof(int), sizeof fiveThousandArray/sizeof(int));
    stepsCountArray[10] = stepsCount;
    stepsCount = 0;

    memmove(tenThousandArray, unsortedTenThousandArray, sizeof(tenThousandArray));
    quicksort(tenThousandArray, 0, sizeof tenThousandArray/sizeof(int), sizeof tenThousandArray/sizeof(int));
    stepsCountArray[11] = stepsCount;
    stepsCount = 0;

    // Print the two quick sorts
    std::cout << "Hundred Array Quick Sorted: ";
    printArray(hundredArray, sizeof hundredArray/sizeof(int));
    std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Thousand Array Quick Sorted: ";
    printArray(thousandArray, sizeof thousandArray/sizeof(int));
    std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


    // Display the steps it took for each array and sort method
    printSteps();

    // Display average running time for each array and sort method
    calculateAverageTime();
    printExecutionTime();
}

void merge(int *arr, int sizeOfArray, int first, int middle, int last)
{
    int temp[sizeOfArray];
    for(int i = first; i<=last; i++)
    {
       stepsCount = stepsCount + 1;
       temp[i] = arr[i];
    }

    int i = first, j = middle + 1, k = first;
    while(i <= middle && j <= last)
    {
        stepsCount = stepsCount + 1;
       if(temp[i] <= temp[j])
       {
          stepsCount = stepsCount + 1;
          arr[k] = temp[i];
          i++;
       }
       else
       {
          stepsCount = stepsCount + 1;
          arr[k] = temp[j];
          j++;
       }
       k++;
    }

    while(i <= middle)
    {
       stepsCount = stepsCount + 1;
       arr[k] = temp[i];
       k++;
       i++;
    }
}

void mergesort(int *arr, int sizeOfArray, int first, int last)
{
    if(first<last)
    {
       int middle = ( first + last ) / 2;
       mergesort(arr, sizeOfArray, first, middle);
       mergesort(arr, sizeOfArray, middle+1, last);
       merge(arr, sizeOfArray, first, middle, last);
    }
}

// Insertion Sort Array Function
void insertionSortArray(int *arr,int sizeOfArray)
{
	//Begin sorting
	int beginLocation;
	int i;
	for(int x = 1; x <= sizeOfArray; x++)
	{
	    beginLocation = arr[x]; //Keep track of what should go in this spot
        for(i = x; i > 0 && arr[i - 1] > beginLocation; i--)
        {
            stepsCount = stepsCount + 1;
            arr[i] = arr[i - 1];
        }
        arr[i] = beginLocation; //Place the proper number in correct spot
	}
}

int partition(int *arr, const int left, const int right) {
    const int mid = left + (right - left) / 2;
    const int pivot = arr[mid];

    // Move the mid point value to the front.
    std::swap(arr[mid],arr[left]);
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while(i <= j && arr[i] <= pivot)
        {
            i++;
        }

        while(i <= j && arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            stepsCount = stepsCount + 1;
            std::swap(arr[i], arr[j]);
        }
    }

    stepsCount = stepsCount + 1;
    std::swap(arr[i - 1],arr[left]);
    return i - 1;
}

void quicksort(int *arr, const int left, const int right, const int sz){

    if (left >= right)
    {
        stepsCount = stepsCount + 1;
        return;
    }

    int part = partition(arr, left, right);
    quicksort(arr, left, part - 1, sz);
    quicksort(arr, part + 1, right, sz);
}

// Generate random number for arrays
void randomGenerate(int *arr,int sizeOfArray)
{
	for(int x = 0; x <= sizeOfArray; x++)
	{
	    //Generate random number from 1 - 10
        int randNum = rand()%sizeOfArray + 1;
        arr[x] = randNum;
	}
}

//Print the array
void printArray(int *arr,int sizeOfArray)
{
    for(int x = 0; x <= sizeOfArray; x++)
    {
        // We don't want to print comma at the end
        if(x == sizeOfArray)
        {
          std::cout << arr[x];
        }
        else if(x < sizeOfArray)
        {
          std::cout << arr[x] << ", ";
        }
    }
}

void printSteps()
{
	std::cout << "Insertion Sort Steps: " << std::endl;
	std::cout << "Hundred Array: " << stepsCountArray[0]<< std::endl;
	std::cout << "Thousand Array: " << stepsCountArray[1]<< std::endl;
	std::cout << "Five-Thousand Array: " << stepsCountArray[2]<< std::endl;
	std::cout << "Ten-Thousand Array: " << stepsCountArray[3]<< std::endl;
	std::cout << std::endl;

	std::cout << "Merge Sort Steps: " << std::endl;
	std::cout << "Hundred Array: " << stepsCountArray[4]<< std::endl;
	std::cout << "Thousand Array: " << stepsCountArray[5]<< std::endl;
	std::cout << "Five-Thousand Array: " << stepsCountArray[6]<< std::endl;
	std::cout << "Ten-Thousand Array: " << stepsCountArray[7]<< std::endl;
	std::cout << std::endl;

	std::cout << "Quick Sort Steps: " << std::endl;
	std::cout << "Hundred Array: " << stepsCountArray[8]<< std::endl;
	std::cout << "Thousand Array: " << stepsCountArray[9]<< std::endl;
	std::cout << "Five-Thousand Array: " << stepsCountArray[10]<< std::endl;
	std::cout << "Ten-Thousand Array: " << stepsCountArray[11]<< std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

void printExecutionTime()
{
	std::cout << "Insertion Sort Average Execution: " << std::endl;
	std::cout << "Hundred Array: " << elapsedTime[0]<< " seconds " << std::endl;
	std::cout << "Thousand Array: " << elapsedTime[1]<< " seconds " << std::endl;
	std::cout << "Five-Thousand Array: " << elapsedTime[2]<< " seconds " << std::endl;
	std::cout << "Ten-Thousand Array: " << elapsedTime[3]<< " seconds " << std::endl;
	std::cout << std::endl;

	std::cout << "Merge Sort Average: " << std::endl;
	std::cout << "Hundred Array: " << elapsedTime[4]<< " seconds " << std::endl;
	std::cout << "Thousand Array: " << elapsedTime[5]<< " seconds " << std::endl;
	std::cout << "Five-Thousand Array: " << elapsedTime[6]<< " seconds " << std::endl;
	std::cout << "Ten-Thousand Array: " << elapsedTime[7]<< " seconds " << std::endl;
	std::cout << std::endl;

	std::cout << "Quick Sort Average Execution: " << std::endl;
	std::cout << "Hundred Array: " << elapsedTime[8]<< " seconds " << std::endl;
	std::cout << "Thousand Array: " << elapsedTime[9]<< " seconds " << std::endl;
	std::cout << "Five-Thousand Array: " << elapsedTime[10]<< " seconds " << std::endl;
	std::cout << "Ten-Thousand Array: " << elapsedTime[11]<< " seconds " << std::endl;
	std::cout << std::endl;
}

//I had to do this because the clock time was too small to calculate the seconds
void calculateAverageTime()
{
    // Insertion Sort average calculation
    clock_t begin = clock();
    for(int x = 0; x <= 1000; x++)
    {
        memmove( hundredArray, unsortedHundredArray, sizeof(hundredArray));
        insertionSortArray(hundredArray, sizeof hundredArray/sizeof(int));
    }
    clock_t end   = clock();
    elapsedTime[0] = float(end - begin) / CLOCKS_PER_SEC;
    elapsedTime[0] = elapsedTime[0] / 1000;

    begin = clock();
    for(int x = 0; x <= 1000; x++)
    {
        memmove( thousandArray, unsortedThousandArray, sizeof(thousandArray));
        insertionSortArray(thousandArray, sizeof thousandArray/sizeof(int));
    }
    end   = clock();
    elapsedTime[1] = float(end - begin) / CLOCKS_PER_SEC;
    elapsedTime[1] = elapsedTime[1] / 1000;

    begin = clock();
    for(int x = 0; x <= 10; x++)
    {
        memmove( fiveThousandArray, unsortedFiveThousandArray, sizeof(fiveThousandArray));
        insertionSortArray(fiveThousandArray, sizeof fiveThousandArray/sizeof(int));
    }
    end   = clock();
    elapsedTime[2] = float(end - begin) / CLOCKS_PER_SEC;
    elapsedTime[2] = elapsedTime[2] / 10;

    begin = clock();
    for(int x = 0; x <= 5; x++)
    {
        memmove( tenThousandArray, unsortedTenThousandArray, sizeof(tenThousandArray));
        insertionSortArray(tenThousandArray, sizeof tenThousandArray/sizeof(int));
    }
    end   = clock();
    elapsedTime[3] = float(end - begin) / CLOCKS_PER_SEC;
    elapsedTime[3] = elapsedTime[3] / 5;


    // Merge Sort average calculation
    begin = clock();
    for(int x = 0; x <= 1000; x++)
    {
        memmove( hundredArray, unsortedHundredArray, sizeof(hundredArray));
        mergesort(hundredArray, sizeof hundredArray/sizeof(int), 0, sizeof hundredArray/sizeof(int));
    }
    end   = clock();
    elapsedTime[4] = float(end - begin) / CLOCKS_PER_SEC;
    elapsedTime[4] = elapsedTime[4] / 1000;

    begin = clock();
    for(int x = 0; x <= 1000; x++)
    {
        memmove( thousandArray, unsortedThousandArray, sizeof(thousandArray));
        mergesort(thousandArray, sizeof thousandArray/sizeof(int), 0, sizeof thousandArray/sizeof(int));
    }
    end   = clock();
    elapsedTime[5] = float(end - begin) / CLOCKS_PER_SEC;
    elapsedTime[5] = elapsedTime[5] / 1000;

    begin = clock();
    for(int x = 0; x <= 5; x++)
    {
        memmove( fiveThousandArray, unsortedFiveThousandArray, sizeof(fiveThousandArray));
        mergesort(fiveThousandArray, sizeof fiveThousandArray/sizeof(int), 0, sizeof fiveThousandArray/sizeof(int));
    }
    end   = clock();
    elapsedTime[6] = float(end - begin) / CLOCKS_PER_SEC;
    elapsedTime[6] = elapsedTime[6] / 5;

    begin = clock();
    for(int x = 0; x <= 5; x++)
    {
        memmove( tenThousandArray, unsortedTenThousandArray, sizeof(tenThousandArray));
        mergesort(tenThousandArray, sizeof tenThousandArray/sizeof(int), 0, sizeof tenThousandArray/sizeof(int));
    }
    end   = clock();
    elapsedTime[7] = float(end - begin) / CLOCKS_PER_SEC;
    elapsedTime[7] = elapsedTime[7] / 5;


    // Quick Sort average calculation
    begin = clock();
    for(int x = 0; x <= 1000; x++)
    {
        memmove( hundredArray, unsortedHundredArray, sizeof(hundredArray));
        quicksort(hundredArray, 0, sizeof hundredArray/sizeof(int), sizeof hundredArray/sizeof(int));
    }
    end   = clock();
    elapsedTime[8] = float(end - begin) / CLOCKS_PER_SEC;
    elapsedTime[8] = elapsedTime[8] / 1000;

    begin = clock();
    for(int x = 0; x <= 1000; x++)
    {
        memmove( thousandArray, unsortedThousandArray, sizeof(thousandArray));
        quicksort(thousandArray, 0, sizeof thousandArray/sizeof(int), sizeof thousandArray/sizeof(int));
    }
    end   = clock();
    elapsedTime[9] = float(end - begin) / CLOCKS_PER_SEC;
    elapsedTime[9] = elapsedTime[9] / 1000;

    begin = clock();
    for(int x = 0; x <= 10; x++)
    {
        memmove( fiveThousandArray, unsortedFiveThousandArray, sizeof(fiveThousandArray));
        quicksort(fiveThousandArray, 0, sizeof fiveThousandArray/sizeof(int), sizeof fiveThousandArray/sizeof(int));
    }
    end   = clock();
    elapsedTime[10] = float(end - begin) / CLOCKS_PER_SEC;
    elapsedTime[10] = elapsedTime[10] / 10;

    begin = clock();
    for(int x = 0; x <= 5; x++)
    {
        memmove( tenThousandArray, unsortedTenThousandArray, sizeof(tenThousandArray));
        quicksort(tenThousandArray, 0, sizeof tenThousandArray/sizeof(int), sizeof tenThousandArray/sizeof(int));
    }
    end   = clock();
    elapsedTime[11] = float(end - begin) / CLOCKS_PER_SEC;
    elapsedTime[11] = elapsedTime[11] / 5;
}


