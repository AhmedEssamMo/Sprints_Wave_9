#ifndef _Searching_Algo_h_
#define _Searching_Algo_h_
/*INCLUDES
 --------------------------------*/
#include "TypeDef.h"

/*ENUMS
 ----------------------------*/
enum EN_IsSorted{Sorted, NotSorted};

/*FUNCTIONS DECLARATIONS
--------------------------------*/
enum EN_IsSorted sort(uint32_t* arr,uint8_t size);
enum EN_IsSorted Check_if_sorted(uint32_t* arr,uint8_t size);
uint8_t binarySearch(uint32_t* arr,uint8_t size,uint32_t number);



#endif // _Searching_Algo_h_
