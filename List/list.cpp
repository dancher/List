#include "iostream"
#include "locale"
#include "conio.h"
using namespace std;
/**
@class List
@brief Класс список
@detailed Содержит поля: число элементов в списке-N, номер элемента списка-nomer,
значение элемента-element,указатель на следующий элемент-next,
указатель на первый-Begin и последний-End элементы
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
@brief Реализация конструктора без параметров
*/
List::List()
{   
	End=0;
	Begin=0;
	nomer=0;
	N=0;
}
/**
@brief Релизация метода добавления элемента в список
@params nomer номер добавляемого элемента
*/
void List::add(int nomer)
{
	List* tmp;
	int i=1;
	tmp=(List*)malloc(1*sizeof(List));
	cout<<"введите элемент "<<"\n";
	cin>>tmp->element;
	if (!Begin)// Список пуст
	{   
		Begin=tmp;
		End=tmp;
		tmp->next=0;
		tmp->nomer=1;
		N++;
		return;	
	}
	if (nomer>N)//Если номер больше числа элементов в списке, элемент помещяется в конец
	{
	   End->next=tmp;
	   End=tmp;
	   tmp->next=0;
	   tmp->nomer=N+1;
	   N++;
	   return;
	}
	if (nomer==1)//номер первый
	{
		tmp->next=Begin;
		Begin=tmp;
	
	}
	else 	//Номер меньше числа элементов в списке и не первый
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
	for (List* t=Begin; t!=0;t=t->next)//Исправление нумерации элементов изменённого списка
	{   	
		t->nomer=i;
	    i++;
	}

}
/**
@brief Релизация метода получения значения элемента списка по номеру
@params nomer номер элемента для получения
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
@brief Релизация метода удаления элемента из списка
@params nomer номер удаляемого элемента
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
	for (List* t=Begin; t!=0;t=t->next)//Исправление нумерации элементов изменённого списка
	{   
		t->nomer=i;
	    i++;
	}
}
/**
@brief Релизация метода печати списка
*/
void List::print()
{
	List* tmp;
	if (!Begin) 
	{
		cout<<"Список пуст";
		return;
	}
	for (tmp=Begin; tmp!=0;tmp=tmp->next)
	{
		cout<<"Элемент номер "<<tmp->nomer<<"  "<<tmp->element<<"\n";
	}
}

/**
@brief Фyнкция main
@detailed Формируется список L из n элементов, производится печать списка.
Удаяется элемент с номером nomer, производится печать изменённого списка
(n и nomer вводятся с клавиатуры)
*/
void main()
{   setlocale(LC_ALL,"rus");
	int n;
	int nomer;
	
	List L;
	cout<<"Введите количество элементов в списке"<<"\n";
	cin>>n;
    for(int i=0;i<n;i++)
	{   
		cout<<"Введите номер добавляемого элемента  ";
		cin>>nomer;
		cout<<"\n";
		L.add(nomer);
	}
	L.print();
	cout<<"введите номер элемента для удаления"<<"\n";
	cin>>nomer;
	L.del(nomer);
	L.print();
	getch();
}