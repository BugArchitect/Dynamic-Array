#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>

struct DynamicArray
{
	int* pArrayFirstAddress;												   //��¼��̬������׵�ַ
	unsigned int Capacity;													   //�ɴ洢����������
	unsigned int Quantity;													   //�Ѵ洢����������
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
	if (p_DynamicArray->Capacity == p_DynamicArray->Quantity)                  //�жϿռ��Ƿ�����
	{

		p_DynamicArray->Capacity += 10;										   //���ӿɴ洢���ݵĿռ�  		  
		int* pTemp = (int*)malloc(sizeof(int) * p_DynamicArray->Capacity);	   //����һ�οռ�
		memset(pTemp,0,sizeof(int)*p_DynamicArray->Capacity);
		for (unsigned int i = 0; i < p_DynamicArray->Quantity; i++)
		{
			pTemp[i] = p_DynamicArray->pArrayFirstAddress[i];				   //��ԭ���ݸ����¿ռ���
		}
		free(p_DynamicArray->pArrayFirstAddress);                              //�ͷ�ԭ�ռ�
		p_DynamicArray->pArrayFirstAddress = pTemp;					           //�������׵�ַָ��ָ��һ���¿ռ�	
	}
}
void AddElement(struct DynamicArray* p_DynamicArray, int Element)
{
	if (NULL == p_DynamicArray)
	{
		printf("��������\n");
		return;
	}
	IncreaseCapacity(p_DynamicArray);
	p_DynamicArray->pArrayFirstAddress[p_DynamicArray->Quantity] = Element;    //�����ݴ����ȥ
	p_DynamicArray->Quantity++;
}
void AddArrayMiddleElement(struct DynamicArray* p_DynamicArray, int Element, unsigned int Subscript)
{
	if (NULL == p_DynamicArray)                                                 //�ж�����Ĳ����Ƿ�Ϸ�
	{
		printf("��������\n");
		return;
	}
	IncreaseCapacity(p_DynamicArray);
	if (Subscript > p_DynamicArray->Quantity)									//�ж��±��Ƿ񳬳�ʵ�����鴢����
	{
		Subscript = p_DynamicArray->Quantity;
	}
	for (unsigned int i = p_DynamicArray->Quantity; i >= Subscript; i--)		//�������е�Ԫ�غ���
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
		printf("��������");
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
		printf("�����������");
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
	printf("��Ԫ�ض�Ӧ���±�Ϊ��%d",flag);
}
void OutputElement(struct DynamicArray* p_DynamicArray)
{
	if (NULL == p_DynamicArray)
	{
		printf("��������");
		return;
	}
	printf("�ɴ洢����%u  �Ѵ洢����%u\n", p_DynamicArray->Capacity, p_DynamicArray->Quantity);
	printf("�����ڵ�Ԫ�أ�\n");
	for (unsigned int i = 0; i < p_DynamicArray->Quantity; i++)
	{
		//printf("��%d������", i + 1);
		printf("%d ", p_DynamicArray->pArrayFirstAddress[i]);
	}
	printf("\n\n");
}
