#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define StackLimit 50

typedef int StackElementType;

typedef struct {
	int Top;
	StackElementType Element[StackLimit];
} StackType;

/*typedef enum {
	FALSE, TRUE
} boolean;
*/


void CreateStack(StackType *Stack)
{
	// �������� ��� � ������ ���� top �� -1
	// ����� ���������� ��� ������ ������ ��������
	// ����.
	Stack->Top = -1;
}

bool EmptyStack(StackType Stack)
{
	return (Stack.Top == -1);
}

bool FullStack(StackType Stack)
{
	return (Stack.Top == StackLimit-1);
}

void Pop(StackType *Stack, StackElementType *Item)
{
	
	if (!EmptyStack(*Stack))	// �� ��� ����� ���� � �����
	{
		*Item = Stack->Element[Stack->Top];
		Stack->Top = Stack->Top - 1;		
	}
	else
	{
		printf("Empty Stack...\n");
	}
}

void Push(StackType *Stack, StackElementType Item)
{
	if (!FullStack(*Stack))
	{
		Stack->Top = Stack->Top + 1;
		Stack->Element[Stack->Top] = Item;		
	}
	else
	{
		printf("Full Stack...\n");
	}
}

void TraverseStack(StackType Stack)
{
	// � ������ ���� 3 ��������:
	// 4
	// 2
	// 0
	printf("Stack has %d elements:\n", Stack.Top + 1);
	int i;
	for (i=Stack.Top; i>=0; i--)
	{
		printf("%d\n", Stack.Element[i]);
	}
}




// � function1 ������� �� ��������� ��� ������, ������� �� ���������� �������� ��� �������
// �� ���������� ���� ��� ��������� ��� �� ������ ���� ��� ���������� 

// --1--. �� ���� ���������� �� ������ �� ���� � function 1?
	// ������ ��������� ��� �������� ��� �������, � ����� ���������� ��� function1 �� ������ 
	// �� ����� � ����� ��� ��������� ��� ������ Element, ������ StackElementType
// --2--. �� ����������� ������ �� ��� ��� ��� �� ��� �����?
	// ������ ������������� (������������ �� ����������) � ������ ������ �� ��� ������ by reference
StackElementType function1(StackType *S)
{
	StackType tempStack;
	StackElementType max, item;
	int i;
	
	CreateStack(&tempStack);
	
	// �� max ������ �� �������� by reference ��� ���� &max
	// �� Pop ������� �� ��������� ������ �� ������,
	// ��� �� ��������� StackElementType function1(StackType *S)
		// �� &S ����� ��������� ������ �� ������
		// �� S ����� ������� �� ������
		// �� *S ����� � ������
	// ��� ����� ������� �� S	
	
	Pop(S, &max);	// O ��������� ������ �� max �� ����� 
					// �������� ��� ������� ������.
					// ���� ����� ��������� �� �� 
					// �� �������� ��� max �� �������
					// ��� �� ������ max = A[0];
	
	// --4--
	Push(&tempStack, max);
	
	// --5--. ���� ���� �� ������ ��� Empty Stack ������ �� ������ 
	// �� ������ ���� ���' ���� ��� ��� ������ �� ����. �� S ����� 
	// ������� �� ������, ��� �� ������� �� ������ EmptyStack(S).
	// �� &tempStack ����� ��������� �� ������, ��� �� ������� �� 
	// ������ EmptyStack(&tempStack)
	// ���� ��� while ������� ��� �� if ��� ��� �� ����� ��� �� ��������
	// ��� �� ������ S. ����� � ����� �� tempStack ����� �����.
	// ��� ������ 99% ����� �� �� !EmptyStack(*S)
	
	while (!EmptyStack(*S))
	{
		
		Pop(S, &item);	// --6--
		
		// --7--. �� ���� ��� ������ ����� ����� �� ���� 
		// push ��� tempStack, ����� ��� ���� �� ��� �����
		// pop ��� �� S. 
		// H push ������� by reference �� ������
		// ��� �� ������ �� tempStack by reference ��� ����
		// &tempStack. ��� � ����� �������� �����:
		Push(&tempStack, item);
		if (max<item)
			max = item;		// --8--
	}
	
	while(!EmptyStack(tempStack))
	{
		Pop(&tempStack, &item);
		if (item != max)
			Push(S, item);
	}
	return max;
}

// Thesi	Timi
// 2    	4
// 1		2
// 0		0

int main(void)
{
	StackType s;
	CreateStack(&s);
	Push(&s, 6);
	Push(&s, 3);
	Push(&s, 8);
	Push(&s, 3);
	Push(&s, 2);
	Push(&s, 6);
	Push(&s, 2);
	Push(&s, 8);
	Push(&s, 1);
	int max = function1(&s);
	printf("Max = %d\n", max);
	
	TraverseStack(s);
	printf("\n");
	return 0;
}
