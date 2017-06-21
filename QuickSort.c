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
void quickSort(LIST *L, int low, int high);

int main()
{
	LIST L;
	init(&L);
	nametype data[] = {{"Robert Michael","Lim", 'M'},
						{"John Paul", "Jayme", 'R'},
						{"Bojo", "Alcisto", 'R'},
						{"Joi", "Villablanca", 'F'},
						{"Lynnard", "Mondigo", 'R'}
						};
						
	int i;
	
	populate(&L, data);
	for(i=0;i<5;i++){
		printf("%s ", L.elem[i].LName);
		if(i<4){
			printf("- ");
		}
	}
	quickSort(&data, 0, L.last);
	return 0;
}

void init (LIST *L)
{
	L->last = -1;
}

void populate(LIST *L, nametype data[])
{
	int ctr;
	for(ctr = 0; ctr < 5; ctr ++){
		if(L->last < SIZE){
			L->last++;
			L->elem[L->last] = data[ctr];
		}
	}
	
}

void quickSort(LIST *L, int low, int high)
{
	if(low < high){
		partitionArray(a, low, high)
	}
}

