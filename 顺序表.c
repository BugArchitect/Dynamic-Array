#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>

struct DynamicArray
{
	int* pArrayFirstAddress;												   //记录动态数组的首地址
	unsigned int Capacity;													   //可存储的数据总量
	unsigned int Quantity;													   //已存储的数据总量
};

void InitializeArray(struct DynamicArray* p_DynamicArray);
void IncreaseCapacity(struct DynamicArray* p_DynamicArray);
void AddElement(struct DynamicArray* p_DynamicArray,int Element);
void AddArrayMiddleElement(struct DynamicArray* DynamicArray, int Element, unsigned int Subscript);
void DeleteArrayFinalElement(struct DynamicArray* p_DynamicArray);
void DeleteArrayMiddleElement(struct DynamicArray* p_DynamicArray,unsigned int Subscript);
void DeleteArrayAllElement(struct DynamicArray* p_DynamicArray);
void FindArrayElement(struct DynamicArray* p_DynamicArray,int Element);
void OutputElement(struct DynamicArray* p_DynamicArray);
void Release(struct DynamicArray* p_DynamicArray);

int main(void)
{
	struct DynamicArray _DynamicArray;
	InitializeArray(&_DynamicArray);
	AddElement(&_DynamicArray,1);
	AddElement(&_DynamicArray,2);
	AddElement(&_DynamicArray,3);
	AddElement(&_DynamicArray,4);
	AddElement(&_DynamicArray,5);
	/*AddElement(&_DynamicArray,6);
	AddElement(&_DynamicArray,6);
	AddElement(&_DynamicArray,6);
	AddElement(&_DynamicArray,6);
	AddElement(&_DynamicArray,6);
	AddElement(&_DynamicArray,6);
	AddElement(&_DynamicArray,6);
	AddElement(&_DynamicArray,6);
	AddElement(&_DynamicArray,6);
	AddElement(&_DynamicArray,6);*/
	AddArrayMiddleElement(&_DynamicArray,6,3);
	/*AddArrayMiddleElement(&_DynamicArray, 7, 6);
	AddArrayMiddleElement(&_DynamicArray, 8, 7);
	AddArrayMiddleElement(&_DynamicArray, 9, 8);
	AddArrayMiddleElement(&_DynamicArray, 10, 9);
	AddArrayMiddleElement(&_DynamicArray, 11, 10);
	AddArrayMiddleElement(&_DynamicArray, 12, 11);
	AddArrayMiddleElement(&_DynamicArray, 13, 12);
	AddArrayMiddleElement(&_DynamicArray, 14, 13);
	AddArrayMiddleElement(&_DynamicArray, 15, 14);*/
	OutputElement(&_DynamicArray);
	//DeleteArrayFinalElement(&_DynamicArray); 
	/*DeleteArrayFinalElement(&_DynamicArray);
	DeleteArrayFinalElement(&_DynamicArray);
	DeleteArrayFinalElement(&_DynamicArray);
	DeleteArrayFinalElement(&_DynamicArray);
	DeleteArrayFinalElement(&_DynamicArray);*/
	//OutputElement(&_DynamicArray);
	//DeleteArrayAllElement(&_DynamicArray);
	//Release(&_DynamicArray);
	DeleteArrayMiddleElement(&_DynamicArray,3);
	OutputElement(&_DynamicArray);
	FindArrayElement(&_DynamicArray, 3);
	free(_DynamicArray.pArrayFirstAddress);
	return 0;
}
void InitializeArray(struct DynamicArray* p_DynamicArray)
{
	p_DynamicArray->Capacity = 5;
	p_DynamicArray->pArrayFirstAddress = (int*)malloc(sizeof(int) * p_DynamicArray->Capacity);
	p_DynamicArray->Quantity = 0;
}
void IncreaseCapacity(struct DynamicArray* p_DynamicArray)
{
	if (NULL == p_DynamicArray)
	{
		return;
	}
	if (p_DynamicArray->Capacity == p_DynamicArray->Quantity)                  //判断空间是否已满
	{

		p_DynamicArray->Capacity += 10;										   //增加可存储数据的空间  		  
		int* pTemp = (int*)malloc(sizeof(int) * p_DynamicArray->Capacity);	   //申请一段空间
		memset(pTemp,0,sizeof(int)*p_DynamicArray->Capacity);
		for (unsigned int i = 0; i < p_DynamicArray->Quantity; i++)
		{
			pTemp[i] = p_DynamicArray->pArrayFirstAddress[i];				   //将原数据赋到新空间中
		}
		free(p_DynamicArray->pArrayFirstAddress);                              //释放原空间
		p_DynamicArray->pArrayFirstAddress = pTemp;					           //将数组首地址指针指向一块新空间	
	}
}
void AddElement(struct DynamicArray* p_DynamicArray, int Element)
{
	if (NULL == p_DynamicArray)
	{
		printf("参数错误！\n");
		return;
	}
	IncreaseCapacity(p_DynamicArray);
	p_DynamicArray->pArrayFirstAddress[p_DynamicArray->Quantity] = Element;    //将数据储存进去
	p_DynamicArray->Quantity++;
}
void AddArrayMiddleElement(struct DynamicArray* p_DynamicArray, int Element, unsigned int Subscript)
{
	if (NULL == p_DynamicArray)                                                 //判断输入的参数是否合法
	{
		printf("参数错误！\n");
		return;
	}
	IncreaseCapacity(p_DynamicArray);
	if (Subscript > p_DynamicArray->Quantity)									//判断下标是否超出实际数组储存数
	{
		Subscript = p_DynamicArray->Quantity;
	}
	for (unsigned int i = p_DynamicArray->Quantity; i >= Subscript; i--)		//让数组中的元素后移
	{
		p_DynamicArray->pArrayFirstAddress[i] = p_DynamicArray->pArrayFirstAddress[i - 1];
	}
	p_DynamicArray->pArrayFirstAddress[Subscript] = Element;
	p_DynamicArray->Quantity++;
}
void DeleteArrayFinalElement(struct DynamicArray* p_DynamicArray)
{
	if(NULL == p_DynamicArray)
	{
		return;
	}
	p_DynamicArray->Quantity--;
}
void DeleteArrayMiddleElement(struct DynamicArray* p_DynamicArray,unsigned int Subscript)
{
	if(NULL == p_DynamicArray)
	{
		return;
	}
	if(Subscript >= p_DynamicArray->Quantity)
	{
		printf("参数错误！");
		return;
	}
	for(unsigned int i = Subscript;i < p_DynamicArray->Quantity - 1;i++)
	{
		p_DynamicArray->pArrayFirstAddress[i] = p_DynamicArray->pArrayFirstAddress[i + 1];
	}
	p_DynamicArray->Quantity--;
}
void DeleteArrayAllElement(struct DynamicArray* p_DynamicArray)
{
	if (NULL == p_DynamicArray)
	{
		return;
	}
	p_DynamicArray->Quantity = 0;	
}
void Release(struct DynamicArray* p_DynamicArray)
{
	if (NULL == p_DynamicArray)
	{
		return;
	}
	p_DynamicArray->Quantity = 0;
	p_DynamicArray->Capacity = 0;
	free(p_DynamicArray->pArrayFirstAddress);
	p_DynamicArray->pArrayFirstAddress = NULL;
}
void FindArrayElement(struct DynamicArray* p_DynamicArray,int Element)
{
	if(NULL == p_DynamicArray)
	{
		printf("参数输入错误！");
		return;
	}
	int flag = -1;
	for(unsigned int i = 0;i < p_DynamicArray->Quantity;i++)
	{
		if(p_DynamicArray->pArrayFirstAddress[i] == Element)
		{
			flag = i;
		}
	}
	printf("该元素对应的下标为：%d",flag);
}
void OutputElement(struct DynamicArray* p_DynamicArray)
{
	if (NULL == p_DynamicArray)
	{
		printf("参数错误！");
		return;
	}
	printf("可存储数：%u  已存储数：%u\n", p_DynamicArray->Capacity, p_DynamicArray->Quantity);
	printf("数组内的元素：\n");
	for (unsigned int i = 0; i < p_DynamicArray->Quantity; i++)
	{
		//printf("第%d个数：", i + 1);
		printf("%d ", p_DynamicArray->pArrayFirstAddress[i]);
	}
	printf("\n\n");
}
