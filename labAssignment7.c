#include <stdio.h>
#include <stdlib.h>

int * bubbleSort (int arr[], int size) {

  int * tempArr = (int*)malloc(size * sizeof(int));

  for(int k = 0; k < size; k++) {
    tempArr[k] = arr[k];
  }  
 
  int temp, secTemp, i = 0;

  // Here I initialize a temporary variable, a second temporary variable, and an "i" value --> this "i" value will end up being used in a while loop for the bubble sort!

  for (int len_counter = 0; len_counter < size; len_counter++) {

    while (i + 1 < size) { // Makes sure that the while loop will stop at the second to last variable (as it will get a value from index i + 1 and that will end up messing up that program! ).

      if (tempArr[i] > tempArr[i + 1]) { //Swaps the two if the current value is greater than the value after it!
        
        temp = tempArr[i];
        secTemp = tempArr[i + 1];
        tempArr[i + 1] = temp;
        tempArr[i] = secTemp;
        
      }

      i++;
    
    }

    i = 0; // Reset the value of i to make sure that the while loop will run again!
    
  }

  return tempArr; // Return the arr;

}

int * num_swaps_bubble(int arr[], int sortedArr[], int size) {

  int * tempArr = (int*)malloc(size * sizeof(int));

  for (int k = 0; k < size; k++) {
    tempArr[k] = arr[k];
  }

  int * swap_counts = (int*)malloc(size * sizeof(int));

  if (!swap_counts) {
    printf("%s", "Memory allocation failed! :(\n");
    exit(1);
  }

  int temp, secTemp, i = 0;

  for (int len_counter = 0; len_counter < size; len_counter++) {
    
    while (i + 1 < size) {
      
      if (tempArr[i] > tempArr[i + 1]) { // The logic for a swap

        for (int j = 0; j < size; j++) {
          
          if (tempArr[i] == sortedArr[j]) {
            swap_counts[j] += 1;
          }
          if (tempArr[i + 1] == sortedArr[j]) {
            swap_counts[j] += 1;
          }
          
        }

        temp = tempArr[i];
        secTemp = tempArr[i + 1];
        tempArr[i + 1] = temp;
        tempArr[i] = secTemp;
        
      }

      i++;
      
    }

    i = 0;
    
  }

  free(tempArr);
  return swap_counts;
}

int * num_swaps_selection(int arr[], int sorted_list[], int size) {

  //================================================

  int * tempArr = (int*)malloc(size * sizeof(int));

  for (int k = 0; k < size; k++) {
    
    tempArr[k] = arr[k];
    
  }

  int * swap_list_selection = (int*)malloc(size * sizeof(int));

  //================================================
  
  int i , j, min_index, temp;

  for (i = 0; i < size - 1; i++) {

    min_index = i;

    for (j = i + 1; j < size; j++) {

      if (tempArr[j] < tempArr[min_index]) {
        min_index = j;
      }
      
    }

    if (tempArr[i] != tempArr[min_index]) {

      for (int k = 0; k < size; k++) {

        if (tempArr[min_index] == sorted_list[k]) {
          swap_list_selection[k] += 1;
        }

        if (tempArr[i] == sorted_list[k]) {
          swap_list_selection[k] += 1;
        }

      }
      
    }

    

    temp = tempArr[i];
    tempArr[i] = tempArr[min_index];
    tempArr[min_index] = temp;

    
    
  }

  free(tempArr);
  return swap_list_selection;
}



int main() {

  int array1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  
  int array2[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

  int * sorted_array = bubbleSort(array1, sizeof(array1) / sizeof(int));

  // for (int i = 0; i < 9; i++) {
  //   printf("%d %d\n", array1[i], sorted_array[i]);
  // }  

  int * swap_counts = num_swaps_bubble(array1, sorted_array, sizeof(array1) / sizeof(int));

  printf("%s", "Array 1 | Bubble Sort | Number of swaps for each number: \n");

  for (int i = 0; i < sizeof(array1) / sizeof(int); i++) {
    printf("%d: swapped %d times.\n", sorted_array[i], swap_counts[i]);
  }

  int total = 0;

  for (int i = 0; i < sizeof(array1) / sizeof(int); i++) {
    total += swap_counts[i];
  }

  printf("The total # of swaps is %d\n", total / 2);

  puts("");

  int * sorted_array2 = bubbleSort(array2, sizeof(array1) / sizeof(int));

  // for (int i = 0; i < 9; i++) {
  //   printf("%d %d\n", array1[i], sorted_array[i]);
  // }  

  int * swap_counts2 = num_swaps_bubble(array2, sorted_array2, sizeof(array1) / sizeof(int));

  printf("%s", "Array 2 | Bubble Sort | Number of swaps for each number: \n");

  for (int i = 0; i < sizeof(array1) / sizeof(int); i++) {
    printf("%d: swapped %d times.\n", sorted_array2[i], swap_counts2[i]);
  }

  int total2 = 0;

  for (int i = 0; i < sizeof(array1) / sizeof(int); i++) {
    total2 += swap_counts2[i];
  }

  printf("The total # of swaps is %d", total2 / 2);

  free(swap_counts2);
  free(swap_counts);

  //=================================================================
  puts("");
  puts("");
  //=================================================================

  int array3[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};

  int array4[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

  int * sorted_array3 = bubbleSort(array3, sizeof(array1) / sizeof(int));

  // for (int i = 0; i < 9; i++) {
  //   printf("%d %d\n", array3[i], sorted_array3[i]);
  // }  

  int * swap_counts3 = num_swaps_selection(array3, sorted_array3, sizeof(array1) / sizeof(int));

  printf("%s", "Array 1 | Selection Sort | Number of swaps for each number: \n");

  for (int i = 0; i < sizeof(array1) / sizeof(int); i++) {
    printf("%d: swapped %d times.\n", sorted_array3[i], swap_counts3[i]);
  }

  int total3 = 0;

  for (int i = 0; i < sizeof(array1) / sizeof(int); i++) {
    total3 += swap_counts3[i];
  }

  printf("The total # of swaps is %d\n", total3 / 2);

  puts("");

  int * sorted_array4 = bubbleSort(array4, sizeof(array1) / sizeof(int));

  // for (int i = 0; i < 9; i++) {
  //   printf("%d %d\n", array4[i], sorted_array4[i]);
  // }  

  int * swap_counts4 = num_swaps_selection(array4, sorted_array4, sizeof(array1) / sizeof(int));

  printf("%s", "Array 2 | Selection Sort | Number of swaps for each number: \n");

  for (int i = 0; i < sizeof(array1) / sizeof(int); i++) {
    printf("%d: swapped %d times.\n", sorted_array4[i], swap_counts4[i]);
  }

  int total4 = 0;

  for (int i = 0; i < sizeof(array1) / sizeof(int); i++) {
    total4 += swap_counts4[i];
  }

  printf("The total # of swaps is %d", total4 / 2);

  
  
}