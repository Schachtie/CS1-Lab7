#include <stdio.h>
#include <stdlib.h>

//Structures
typedef struct {
    int m_iData;
    int m_iSwapFreq;
} PairDataFreq;

//Function Prototypes
int bubbleSort(PairDataFreq* array, size_t length);
void printArray(PairDataFreq* array, size_t length);
int selectionSort(PairDataFreq* array, size_t length);
void swap(PairDataFreq* pX, PairDataFreq* pY);


int main(void) {
    PairDataFreq array1[9] = {{97, 0}, {16, 0}, {45, 0}, {63, 0}, {13, 0}, {22, 0}, {7, 0}, {58, 0}, {72, 0}};
    PairDataFreq array2[9] = {{90, 0}, {80, 0}, {70, 0}, {60, 0}, {50, 0}, {40, 0}, {30, 0}, {20, 0}, {10, 0}};

    puts("\narray1 bubble sort:");
    int iArray1BubbleSwaps = bubbleSort(array1, 9);
    printArray(array1, 9);
    printf("%s: %d\n", "Total number of swaps: ", iArray1BubbleSwaps);

    puts("\narray2 bubble sort:");
    int iArray2BubbleSwaps = bubbleSort(array2, 9);
    printArray(array2, 9);
    printf("%s: %d\n", "Total number of swaps: ", iArray2BubbleSwaps);

    //"Reset" arrays to original data values and locations
    PairDataFreq array3[9] = {{97, 0}, {16, 0}, {45, 0}, {63, 0}, {13, 0}, {22, 0}, {7, 0}, {58, 0}, {72, 0}};
    PairDataFreq array4[9] = {{90, 0}, {80, 0}, {70, 0}, {60, 0}, {50, 0}, {40, 0}, {30, 0}, {20, 0}, {10, 0}};

    puts("\narray1 selection sort:");
    int iArray3SelectSortSwaps = selectionSort(array3, 9);
    printArray(array3, 9);
    printf("%s: %d\n", "Total number of swaps", iArray3SelectSortSwaps);

    puts("\narray2 selection sort:");
    int iArray4SelectSortSwaps = selectionSort(array4, 9);
    printArray(array4, 9);
    printf("%s: %d\n", "Total number of swaps", iArray4SelectSortSwaps);
}


//Function Definitions
int bubbleSort(PairDataFreq* array, size_t length) {
    int iTotalSwaps = 0;
    for (size_t pass = 0; pass < length - 1; ++pass) {
        for (size_t comparison = 0; comparison < length - pass - 1; ++comparison) {
            if (array[comparison].m_iData > array[comparison + 1].m_iData) {
                swap(&array[comparison], &array[comparison + 1]);
                ++iTotalSwaps;
            }
        }
    }
    return iTotalSwaps;
}

void printArray(PairDataFreq* array, size_t length) {
    for (size_t index = 0; index < length; ++index) {
        printf("%d: %d\n", array[index].m_iData, array[index].m_iSwapFreq);
    }
}

int selectionSort(PairDataFreq* array, size_t length) {
    int iTotalSwaps = 0;
    //push boundary
    for (size_t fixedElms = 0; fixedElms < length - 1; ++fixedElms) {
        //find smallest element in unsorted portion
        size_t minIndex = fixedElms;
        for (size_t currIndex = fixedElms + 1; currIndex < length; ++currIndex) {
            if (array[currIndex].m_iData < array[minIndex].m_iData) {
                minIndex = currIndex;
            }
        }
        //swap smallest element into next position of sorted array
        swap(&array[minIndex], &array[fixedElms]);
        ++iTotalSwaps;
    }
    return iTotalSwaps;
}

void swap(PairDataFreq* pX, PairDataFreq* pY) {
    //swap elements
    PairDataFreq temp = *pX;
    *pX = *pY;
    *pY = temp;

    //update frequency counters
    ++(pX->m_iSwapFreq);
    ++(pY->m_iSwapFreq);
}