#include <stdio.h>
#include <stdlib.h>
#include "TypeDef.h"
#include "Searching_Algo.h"

int main()
{
    uint32_t arr[10]={3,5,18,20,6,1,2,10,30,40};
    uint8_t i=0;
    uint8_t index=0;
    uint32_t temp=0;

    uint8_t size_of_arr=sizeof(arr);
    size_of_arr=size_of_arr/sizeof(uint32_t);

    for(i=0;i<size_of_arr;i++){
        printf("%d \t",arr[i]);
    }
    printf("\n");
    printf("Printing the arr element only to testing purposes!!!\n");
    while(1){
    printf("Please enter the number you are searching for\n");
    scanf("%d",&temp);
    index= binarySearch(arr,size_of_arr,temp);
    printf("the index of the number is %d\n",index);
    }
    return 0;
}
