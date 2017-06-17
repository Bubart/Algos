#include <stdio.h>
#include <stdlib.h>
#define SIZE 25

typedef struct{
	char FName[24];
	char LName[16];
	char MI;
}nametype;

typedef struct{
	nametype elem[SIZE];
	int last;
}LIST;

void init(LIST *);
void populate(LIST *L, nametype []);
void bubbleSort(LIST *L);

int main()
{
	LIST L;
	init(&L);
	nametype data[] = {{"Robert Michael","Lim", 'M'},
						{"John Paul", "Jayme", 'R'},
						{"Bojo", "Alcisto", 'R'},
						};
						
	
	populate(&L, data);
	bubbleSort(&L);
	printf("%s", L.elem[0].FName);
	return 0;
}

void init (LIST *L)
{
	L->last = -1;
}

void populate(LIST *L, nametype data[])
{
	int ctr;
	for(ctr = 0; ctr < 3; ctr ++){
		if(L->last < SIZE){
			L->last++;
			L->elem[L->last] = data[ctr];
		}
	}
	
}

void bubbleSort(LIST *L)
{
	int i, j;
	nametype swapdata;
	for(i=0;i<L->last;i++){
		for(j = 0; j< L->last; j++){
			if(strcmp(L->elem[j].LName, L->elem[j+1].LName)>0){
				swapdata = L->elem[j];
				L->elem[j] = L->elem[j+1];
				L->elem[j+1] = swapdata;
			}else if(strcmp(L->elem[j].LName, L->elem[j+1].LName)==0){
				if(strcmp(L->elem[j].FName, L->elem[j+1].FName)>0){
					swapdata = L->elem[j];
					L->elem[j] = L->elem[j+1];
					L->elem[j+1] = swapdata;
				}
			}
		}
	}
}
