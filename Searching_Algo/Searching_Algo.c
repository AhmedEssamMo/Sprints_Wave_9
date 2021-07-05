#include "Searching_Algo.h"
#include "TypeDef.h"
#include <stdio.h>
#include <stdlib.h>


void sort(uint32_t* arr,uint8_t size ){

    uint8_t i=0;
    uint8_t j=1;
    uint8_t index_no=0;
    uint8_t flag=0;

    while(i!=size){
        while(j!=size){
            if(arr[i]>arr[j]){
               if(flag==0)
                {
                index_no=j;
                }
                else if ((flag==1)&&(arr[j]<arr[index_no]))
                    {
                        index_no=j;
                    }
                else{}
                flag=1;
            }
            else{}
            j++;

        }
        if(flag==1){
            arr[i]=arr[i]+arr[index_no];
            arr[index_no]=arr[i]-arr[index_no];
            arr[i]=arr[i]-arr[index_no];
            flag=0;
        }
        else{}
        i++;
        j=i+1;
    }
}
uint8_t binarySearch(uint32_t* arr,uint8_t size,uint32_t number){
    uint8_t sorted=1;
    uint8_t start=0;
    uint8_t end=size-1;
    uint8_t mid=end/2;
    uint8_t i=0;
    uint8_t index_no=0;


    while(i!=(size-1)){
        if(*(arr+i)>*(arr+i+1)){
            sorted=0;
        }
        else{}
        i++;
    }
    if (sorted==0){

        sort(arr,size);
        }

    else{}
    printf("Printing the array after sorting \n");
    for(i=0;i<size;i++){
        printf("%d \t",arr[i]);
    }
    printf("\n");
    while(1){
    if(number==arr[mid]){
        return mid;
    }
    if(start==end){
        return -1;
    }
    else if(number<arr[mid]){
        end=mid-1;
        mid=(end+start)/2;
    }
    else if(number>arr[mid]){
        start=mid+1;
        mid=((end+start)/2);
    }
    else{}

    }

}
