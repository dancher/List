#include "iostream"
#include "locale"
#include "conio.h"
using namespace std;
/**
@class List
@brief ����� ������
@detailed �������� ����: ����� ��������� � ������-N, ����� �������� ������-nomer,
�������� ��������-element,��������� �� ��������� �������-next,
��������� �� ������-Begin � ���������-End ��������
*/
class List
{
int N;
int nomer;
int element;
List* next;
List* Begin;
List* End;
public:
List();
void add(int nomer);
int getElement(int nomer);
void del(int nomer);
void print();
};
/**
@brief ���������� ������������ ��� ����������
*/
List::List()
{   
	End=0;
	Begin=0;
	nomer=0;
	N=0;
}
/**
@brief ��������� ������ ���������� �������� � ������
@params nomer ����� ������������ ��������
*/
void List::add(int nomer)
{
	List* tmp;
	int i=1;
	tmp=(List*)malloc(1*sizeof(List));
	cout<<"������� ������� "<<"\n";
	cin>>tmp->element;
	if (!Begin)// ������ ����
	{   
		Begin=tmp;
		End=tmp;
		tmp->next=0;
		tmp->nomer=1;
		N++;
		return;	
	}
	if (nomer>N)//���� ����� ������ ����� ��������� � ������, ������� ���������� � �����
	{
	   End->next=tmp;
	   End=tmp;
	   tmp->next=0;
	   tmp->nomer=N+1;
	   N++;
	   return;
	}
	if (nomer==1)//����� ������
	{
		tmp->next=Begin;
		Begin=tmp;
	
	}
	else 	//����� ������ ����� ��������� � ������ � �� ������
	{ for (List* t=Begin; t!=0;t=t->next)
	{   
		if(t->nomer==nomer-1)
		{
		tmp->next=t->next->next;
		t->next=tmp;
		break;
		}
	}
	}
	N++;
	for (List* t=Begin; t!=0;t=t->next)//����������� ��������� ��������� ���������� ������
	{   	
		t->nomer=i;
	    i++;
	}

}
/**
@brief ��������� ������ ��������� �������� �������� ������ �� ������
@params nomer ����� �������� ��� ���������
*/
int List::getElement(int nomer)
{
	List* tmp;
	for(tmp=Begin; tmp!=0;tmp=tmp->next)
	{
		if(tmp->nomer==nomer)
		return tmp->element;
	}
}
/**
@brief ��������� ������ �������� �������� �� ������
@params nomer ����� ���������� ��������
*/
void List::del(int nomer)
{
	List* tmp;
	List* t;
	int i=1;
	
	 if(nomer==1)
	 {  
		 tmp=Begin; 
		 Begin=tmp->next;
         free(tmp);		
	 }
	for(tmp=Begin; tmp!=0;tmp=tmp->next)
	{
	    if (tmp->nomer==nomer-1)
		{ 
		  t=tmp->next;
		  tmp->next=tmp->next->next;
		  free(t);
		  break;
		}
	}
	N--;
	for (List* t=Begin; t!=0;t=t->next)//����������� ��������� ��������� ���������� ������
	{   
		t->nomer=i;
	    i++;
	}
}
/**
@brief ��������� ������ ������ ������
*/
void List::print()
{
	List* tmp;
	if (!Begin) 
	{
		cout<<"������ ����";
		return;
	}
	for (tmp=Begin; tmp!=0;tmp=tmp->next)
	{
		cout<<"������� ����� "<<tmp->nomer<<"  "<<tmp->element<<"\n";
	}
}

/**
@brief �y����� main
@detailed ����������� ������ L �� n ���������, ������������ ������ ������.
�������� ������� � ������� nomer, ������������ ������ ���������� ������
(n � nomer �������� � ����������)
*/
void main()
{   setlocale(LC_ALL,"rus");
	int n;
	int nomer;
	
	List L;
	cout<<"������� ���������� ��������� � ������"<<"\n";
	cin>>n;
    for(int i=0;i<n;i++)
	{   
		cout<<"������� ����� ������������ ��������  ";
		cin>>nomer;
		cout<<"\n";
		L.add(nomer);
	}
	L.print();
	cout<<"������� ����� �������� ��� ��������"<<"\n";
	cin>>nomer;
	L.del(nomer);
	L.print();
	getch();
}