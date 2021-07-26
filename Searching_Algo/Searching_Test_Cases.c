/*INCLUDES
 ---------------------------------*/
#include <stdlib.h>
#include "Searching_Algo.h"

/*LOCAL FUNCTION IMPLEMENTATION
 ----------------------------*/
void TEST1_IF_ARR_IS_SORTED(void)
{
    uint32_t arr[5] = {0,1,2,3,4};
    if(Check_if_sorted(arr, 5) == Sorted){
        printf("TEST CASE 1 PASSED\n");
        }
    else if(Check_if_sorted(arr, 5) == NotSorted){
        printf("TEST CASE 2 FAILED\n");
    }
}

void TEST2_IF_ARR_IS_NOT_SORTED(void)
{
    uint32_t arr[5] = {5,1,2,3,4};
    if(Check_if_sorted(arr, 5) == NotSorted){
        printf("TEST CASE 2 PASSED\n");
    }
    else if(Check_if_sorted(arr, 5) == Sorted){
        printf("TEST CASE 2 FAILED\n");
    }
}


void TEST3_SORT_FUNC_FOR_SORRTED_ARR(void)
{
    uint32_t arr[5] = {0,1,2,3,4};
    if(sort(arr,5) == Sorted){
        printf("TEST CASE 3 PASSED\n");
    }
    else {
        printf("TEST CASE 3 FAILED\n");
    }
}

void TEST4_SORT_FUNC_FOR_NOT_SORRTED_ARR(void)
{
    uint32_t arr[5] = {0,7,8,3,4};
    if(sort(arr,5) == NotSorted){
        printf("TEST CASE 4 PASSED\n");
    }
    else {
        printf("TEST CASE 4 FAILED\n");
    }
}

void TEST5_BINARY_SEARCH_FOUND_THE_NUMBER(void)
{
    uint32_t arr[5] = {6,2,0,40,18};
    if(binarySearch(arr, 5, 0) < 5)   {
        printf("TEST CASE 5 PASSED\n");
    }
    else if(binarySearch(arr, 5, 50) == 255){
        printf("TEST CASE 5 FAILED\n");
    }
}

void TEST6_BINARY_SEARCH_COULDNT_FIND_THE_NUMBER_(void)
{
    uint32_t arr[5] = {1,25,39,11,45};
    if(binarySearch(arr, 5, 20) == 255){
        printf("TEST CASE 6 PASSED\n");
    }
    else if(binarySearch(arr, 5, 20) < 5){
       printf("TEST CASE 6 FAILED\n");
    }
}
/*MIAN
 ----------------------------*/
int main(void)
{
    TEST1_IF_ARR_IS_SORTED();
    TEST2_IF_ARR_IS_NOT_SORTED();
    TEST3_SORT_FUNC_FOR_SORRTED_ARR();
    TEST4_SORT_FUNC_FOR_NOT_SORRTED_ARR();
    TEST5_BINARY_SEARCH_FOUND_THE_NUMBER();
    TEST6_BINARY_SEARCH_COULDNT_FIND_THE_NUMBER_();
    return 0;
}
