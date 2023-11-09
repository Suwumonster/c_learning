#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 //自定义存储数据类型
typedef int StDataType;

//栈的结构体
typedef struct STACK
{
	StDataType* a;
	int top;
	int capacity;
}ST;

// 函数名：stackinit
// 函数功能：初始化栈，为栈申请空间
// 函数参数：栈的指针
// 函数返回类型及内容：空
void stackinit(ST* ps);

// 函数名：stackdestroy
// 函数功能：销毁栈，为栈释放空间
// 函数参数：栈的指针
// 函数返回类型及内容：空
void stackdestroy(ST* ps);

// 函数名：stackpush
// 函数功能：压栈，把x压入栈顶
// 函数参数：栈的指针，数据x
// 函数返回类型及内容：空
void stackpush(ST* ps, StDataType x);

// 函数名：stackpop
// 函数功能：弹栈，删除栈顶元素
// 函数参数：栈的指针
// 函数返回类型及内容：空
void stackpop(ST* ps);

// 函数名：stacktop
// 函数功能：出栈，返回栈顶位置的数据
// 函数参数：栈的指针
// 函数返回类型及内容：栈储存数据的类型，栈顶位置的数据
StDataType stacktop(ST* ps);

// 函数名：stackempty
// 函数功能：判断栈是否为空，为空返回真，否则返回假
// 函数参数：栈的指针
// 函数返回类型及内容：bool，真或假
bool stackempty(ST* ps);

// 函数名：stacksize
// 函数功能：返回栈中数据个数
// 函数参数：栈的指针
// 函数返回类型及内容：int，栈中数据个数
int stacksize(ST* ps);


void stackinit(ST* ps)
{
	assert(ps);
	ps->a = (StDataType*)malloc(sizeof(StDataType) * 4);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	ps->top = 0;
	ps->capacity = 4;
}
void stackdestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

void stackpush(ST* ps, StDataType x)
{
	assert(ps);
	assert(ps->a);

	//扩容
	if (ps->top == ps->capacity)
	{
		StDataType* tmp = (StDataType*)realloc(ps->a, 2 * ps->capacity * sizeof(StDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void stackpop(ST* ps)
{
	assert(ps);
	assert(!stackempty(ps));
	ps->top--;
}

StDataType stacktop(ST* ps)
{
	assert(ps);
	assert(!stackempty(ps));
	return ps->a[ps->top - 1];
}

bool stackempty(ST* ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		return true;
	}
	return false;
}
int stacksize(ST* ps)
{
	assert(ps);
	return ps->top;
}


void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//int midNum(int* a, int start, int end)//快排优化，三数取中
//{
//	int mid = (start + end) / 2;
//	if (a[start] > a[mid])
//	{
//		if (a[mid] > a[end]) // a[start] > a[mid] > a[end]
//		{
//			return mid;
//		}
//		else if (a[start] > a[end]) // a[start] > a[end] > a[mid]
//		{
//			return end;
//		}
//		else//a[end] > a[start] > a[mid]
//		{
//			return start;
//		}
//	}
//	else// a[mid] > a[start]
//	{
//		if (a[start] > a[end])//a[mid] > a[start] > a[end]
//		{
//			return start;
//		}
//		else if (a[mid] > a[end])//a[mid] > a[end] > a[start]
//		{
//			return end;
//		}
//		else//a[end] > a[mid] > a[start]
//		{
//			return mid;
//		}
//	}
//}

int Partsort(int* a, int start, int end)
{
	////三数取中优化，避免有序情况，最坏情况
	//int midi = midNum(a, start, end);
	int midi = start + rand() % (end - start + 1);//这样应该就可以AC
	swap(&a[start], &a[midi]);

	int keyi = start;
	int prev = start;
	int cur = start + 1;
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	swap(&a[keyi], &a[prev]);
	keyi = prev;
	return keyi;
}


void QuickSort(int* a, int start, int end)
{
	ST st;
	stackinit(&st);
	stackpush(&st, start);
	stackpush(&st, end);
	while (!stackempty(&st))
	{
		int right = stacktop(&st);
		stackpop(&st);
		int left = stacktop(&st);
		stackpop(&st);

		int keyi = Partsort(a, left, right);

		int tmp1 = keyi - 1;
		int tmp2 = keyi + 1;

		while (tmp1 > left && a[tmp1] == a[tmp1 + 1])
		{
			tmp1--;
		}
		while (tmp2 < right && a[tmp2] == a[tmp2 - 1])
		{
			tmp2++;
		}
		if (left < tmp1)
		{
			stackpush(&st, left);
			stackpush(&st, tmp1);
		}
		if (tmp2 < right)
		{
			stackpush(&st, tmp2);
			stackpush(&st, right);
		}
	}

	stackdestroy(&st);
}
int* sortArray(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;
	int* tmp = (int*)malloc(sizeof(int) * numsSize);
	memcpy(tmp, nums, sizeof(int) * numsSize);
	QuickSort(tmp, 0, numsSize - 1);
	return tmp;
}