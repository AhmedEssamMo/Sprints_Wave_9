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
	for(i=0;i<(size-1);i++)
	{
    /*This if checks if the arr[i]>arr[i+1] if yes that is mean it is not sorted*/
        if(*(arr+i)>*(arr+i+1)){
            SortedFlag=NotSorted;
        }
        else{
            //do nothing
        }
    }
	return SortedFlag;
}
/**************************************
*THIS FUNCTION SORT THE ARR IS SORRTED*
***************************************/
enum EN_IsSorted sort(uint32_t* arr,uint8_t size ){
	uint8_t i=0;
	uint8_t j=1;
	uint8_t index_no=0;
	uint8_t flag=0;
	uint8_t SortedFlag=Sorted;//If the flag = 1 that is mean the arr is not sorted
    /*check if the arr is Sorted*/
    if (Sorted==Check_if_sorted(arr,size))
	{
		SortedFlag=Sorted;
	}
    else{    
		SortedFlag=NotSorted;
		for(i=0;i<(size);i++)
		{
			for(j=(i+1);j<(size);j++)
			{
				if(arr[i]>arr[j])
				{
				   if(0==flag)
					{
						index_no=j;
					}
					else if ((1==flag)&&(arr[j]<arr[index_no]))
					{
						index_no=j;
					}
					else
					{
						//DO NOTHING
					}
					flag=1;
				}
				else
				{
					//DO NOTHING
				}
			}
			/*IF FLAG = 1 SWAP*/
			if(1==flag){
				arr[i]=arr[i]+arr[index_no];
				arr[index_no]=arr[i]-arr[index_no];
				arr[i]=arr[i]-arr[index_no];
				flag=0;
			}
			else
			{
				//DO NOTHING
			}
		}
	}
    return SortedFlag;
}
/*******************************************************
*THIS FUNCTION SEARCH FOR A NUMBER(USING BINARY SEARCH)*
********************************************************/
uint8_t binarySearch(uint32_t* arr,uint8_t size,uint32_t number){
	uint8_t u8_Index=0;
    uint8_t start=0;
    uint8_t end=size-1;
    uint8_t mid=end/2;
    uint8_t i=0;
    /*THIS FUNCTION WILL NOT SORT IF THE ARRAY IS ALREADY SORTED*/
    sort(arr,size);
    for(i=0;i<255;i++)
	{
		if(start==end){
			u8_Index=255;//Not exist
			break;
		}
		if(number==arr[mid]){
			u8_Index=mid;//At index (mid)
			break;
		}

		else if(number<arr[mid]){
			end=mid-1;
			if(start>end){
				u8_Index=255;//Not exist
				break;
			}
			mid=(end+start)/2;
		}
		else if(number>arr[mid]){
			start=mid+1;
			mid=((end+start)/2);
		}
		else{
			//DO NOTHING
		}
    }
	return flag;
}
