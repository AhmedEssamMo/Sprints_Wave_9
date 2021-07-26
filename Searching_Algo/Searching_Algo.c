/*INCLUDES
 --------------------------------*/
#include "Searching_Algo.h"
#include "TypeDef.h"
#include <stdio.h>
#include <stdlib.h>
/*- APIs IMPLEMENTATION
 -----------------------------------*/
/******************************************
*THIS FUNCTION CHECK IF THE ARR IS SORRTED*
*******************************************/
enum EN_IsSorted Check_if_sorted(uint32_t* arr,uint8_t size){
    uint8_t SortedFlag=Sorted;//If the flag = 1 that is mean the arr is not sorted
    uint8_t i=0;
    while(i!=(size-1)){
    /*This if checks if the arr[i]>arr[i+1] if yes that is mean it is not sorted*/
        if(*(arr+i)>*(arr+i+1)){
            SortedFlag=NotSorted;
        }
        else{
            //do nothing
        }
        i++;
    }
    if(SortedFlag==Sorted){
        return Sorted;
    }
    else if(SortedFlag==NotSorted){
        return NotSorted;
    }
    else{
            //do notheing

    }
}
/**************************************
*THIS FUNCTION SORT THE ARR IS SORRTED*
***************************************/
enum EN_IsSorted sort(uint32_t* arr,uint8_t size ){
    /*check if the arr is Sorted*/
    if (Check_if_sorted(arr,size)==Sorted){
            return Sorted;
        }
    else{
        //DO NOTHING
    }
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
    return NotSorted;
}
/*******************************************************
*THIS FUNCTION SEARCH FOR A NUMBER(USING BINARY SEARCH)*
********************************************************/
uint8_t binarySearch(uint32_t* arr,uint8_t size,uint32_t number){
    uint8_t start=0;
    uint8_t end=size-1;
    uint8_t mid=end/2;
    uint8_t i=0;
    uint8_t index_no=0;
    /*THIS FUNCTION WILL NOT SORT IF THE ARRAY IS ALREADY SORTED*/
    sort(arr,size);

    while(1){
    if(start==end){
        return 255;
    }
    if(number==arr[mid]){
        return mid;
    }

    else if(number<arr[mid]){
        end=mid-1;
        if(start>end){
            return 255;
        }
        mid=(end+start)/2;
    }
    else if(number>arr[mid]){
        start=mid+1;
        mid=((end+start)/2);
    }
    else{}
    }
}
