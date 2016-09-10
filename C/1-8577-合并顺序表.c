#include<stdio.h>
#include<malloc.h>
#define OK 1 
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int
/*
ADT SqList{
	//�ṹ
	typedef struct{
		ElemType *elem;//���Ա�Ԫ��
		int length;//���Ա�ĸ���
		int listsize;//���Ա�Ŀռ䳤��
	}SqList
	//��������
	//��ʼ��--Status InitList_Sq(SqList &L)
	//����(��ȡ)--int Load_Sq(SqList &L)
	//����(����)Ԫ��--Status ListInsert_Sq(SqList &L, int position, ElemType ele)
	//ɾ��--ElemType ListDelete_Sq(SqList &L, int position, ElemType &e)
	
}
*/
typedef struct {
	ElemType *elem;//���Ա�Ԫ�ؼ���
	int length;//���Ա�ĸ���
	int listsize;//���Ա�Ŀռ䳤��
} SqList;

int InitList_Sq(SqList &L) {
	// �㷨2.3������һ���յ����Ա�L�������Ա�Ԥ�����СΪLIST_INIT_SIZE
	// �벹ȫ����
	L.elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
	if (!L.elem) return ERROR;//����ʧ�ܣ����ش���
	L.length = 0; //���Ա����Ϊ0
	L.listsize = LIST_INIT_SIZE;//���Ա�ĳ�ʼ�ռ�
	return OK;
}

int Load_Sq(SqList &L) {
	// ���˳����е�����Ԫ��
	int i;
	if (L.length == 0) printf("The List is empty!"); // �����
	else {
		//printf("The List is: ");
		for (i = 0; i < L.length; i++) printf("%d ", L.elem[i]); // �����
	}
	printf("\n");
	return OK;
}

//����������ƣ��ٲ���
int ListInsert_Sq(SqList &L, int i, int e) {
	// �㷨2.4����˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
	// i�ĺϷ�ֵΪ1��i��L.length +1
	// �벹ȫ����
	ElemType *p, *q;
	//�ж��Ƿ�Ϸ�
	if (i < 1 || i > L.length + 1) return ERROR;
	//�ж��Ƿ񳬳���������̬����ռ�
	if (L.length >= L.listsize) {
		ElemType* newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) return ERROR;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	q = &(L.elem[i - 1]); //qΪ�����λ��
	//pΪ����λ��
	for (p = &(L.elem[L.length - 1]); p >= q; --p) *(p + 1) = *p; //����λ�ü��Ժ��Ԫ������
	*q = e; //����e
	++L.length;
	return OK;
}
//ɾ������ɾ����������
int ListDelete_Sq(SqList &L, int i, int &e) {
	// �㷨2.5,��˳�����Ա�L��ɾ����i��λ�õ�Ԫ�أ�����e������ֵ
	// i�ĺϷ�ֵΪ1��i��L.length
	// �벹ȫ����
	if (i < 1 || i > L.length) {
		return ERROR;
	}//����
	ElemType *p = &(L.elem[i - 1]);//PΪɾ��Ԫ�ص�λ��
	e = *p;//��ɾ����ֵ����e
	ElemType *q = &(L.elem [L.length - 1]);
	for (p++; p <= q; ++p) *(p - 1) = *p;
	L.length--;
	return e;
}
void MergeList(SqList sq_First,SqList sq_Second,SqList &sq_Result) {
	ElemType *ptr = NULL;
	ElemType elem;
	int i, j, r, loop, loopLength, num;
	i = 1;//sq_First�ĵ�һ��Ԫ��
	j = 1;//sq_Second�ĵ�һ��Ԫ��
	r = 1;//��ʼ��sq_Result��λ�ã�����λ��
	while (i <= sq_First.length&&j <= sq_Second.length) {
		if (sq_First.elem[i - 1] >= sq_Second.elem[j - 1]) {
			elem = sq_Second.elem[j - 1];//�õ�СԪ��
			j++;
		}
		else {
			elem = sq_First.elem[i - 1];//�õ�СԪ�صĵ�ַ
			i++;
		}
		ListInsert_Sq(sq_Result, r, elem);
		r++;
	}
	//�ж�����һ������
	//��һ������
	if (i > sq_First.length) {
		loop = j;
		loopLength = sq_Second.length;
		ptr = &sq_Second.elem[j - 1];//��ȡ1����ʱ��2��ͷԪ�صĵ�ַ���ǵü�һ
	}
	//�ڶ�������
	else {
		loop = i;
		loopLength = sq_First.length;
		ptr = &sq_First.elem[i - 1];//��ȡ2����ʱ��1��ͷԪ�صĵ�ַ���ǵü�һ
	}
	//��δ�����Ĳ���sq_Result
	for (; loop <= loopLength; loop++) {
		elem = *ptr;
		ListInsert_Sq(sq_Result, r, elem);
		r++;
		ptr++;
	}
}




int main() {
	SqList sq_First,sq_Second,sq_Result;
	ElemType *ptr = NULL;
	ElemType elem;
	InitList_Sq(sq_First);
	InitList_Sq(sq_Second);
	InitList_Sq(sq_Result);
	int i,j,r,loop,loopLength,num;
	scanf("%d",&num);
	for (i = 1; i < (num+1); i++) {
		scanf("%d",&elem);
		ListInsert_Sq(sq_First,i,elem);
	}
	scanf("%d", &num);
	for (i = 1; i < (num + 1); i++) {
		scanf("%d", &elem);
		ListInsert_Sq(sq_Second, i, elem);
	}
	MergeList(sq_First,sq_Second,sq_Result);
	printf("List A:");
	Load_Sq(sq_First);
	printf("List B:");
	Load_Sq(sq_Second);
	printf("List C:");
	Load_Sq(sq_Result);
	return 0;
}