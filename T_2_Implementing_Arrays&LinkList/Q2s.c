#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int coeff;
	int pow;
	struct Node* next;
};

void readPolynomial(struct Node** poly)
{
	int coeff, exp, cont;
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	*poly = temp;
	do{
		printf("Coeffecient: ");
		scanf("%d", &coeff);
		printf(" Exponent: ");
		scanf("%d", &exp);
		temp->coeff = coeff;
		temp->pow = exp;
		temp-> next = NULL;
		printf("PRESSS 1 for more to add and 0 for no: ");
		scanf("%d", &cont);
		if(cont)
		{
			temp->next = (struct Node*)malloc(sizeof(struct Node));
			temp = temp->next;
			temp->next = NULL;
		}
	}while(cont);
}

void displayPolynomial(struct Node* poly)
{
	printf("Polynomial is ");
	while(poly != NULL)
	{
		printf("%dX^%d", poly->coeff, poly->pow);
		poly = poly->next;
		if(poly != NULL)
			printf("+");
	}
	printf("\n");
}

void addPolynomials(struct Node** result, struct Node* first, struct Node* second)
{
 	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 	temp->next = NULL;
 	*result = temp;
 	while(first && second)
 	{
 		if(first->pow > second->pow)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}
 		else if(first->pow < second->pow)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 		else
 		{
 			temp->coeff = first->coeff + second->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 			second = second->next;
 		}

 		if(first && second)
 		{
 			temp->next = (struct Node*)malloc(sizeof(struct Node));
 			temp = temp->next;
 			temp->next = NULL;
 		}
 	}
 	while(first || second)
 	{
 		temp->next = (struct Node*)malloc(sizeof(struct Node));
 		temp = temp->next;
 		temp->next = NULL;

 		if(first)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}

 		else if(second)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 	}
}


void subPolynomial2(struct Node** result, struct Node* first, struct Node* second)
{
 	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 	temp->next = NULL;
 	*result = temp;
 	while(first && second)
 	{
 		if(first->pow > second->pow)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}
 		else if(first->pow < second->pow)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 		else
 		{
 			temp->coeff = first->coeff - second->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 			second = second->next;
 		}

 		if(first && second)
 		{
 			temp->next = (struct Node*)malloc(sizeof(struct Node));
 			temp = temp->next;
 			temp->next = NULL;
 		}
 	}
 	while(first || second)
 	{
 		temp->next = (struct Node*)malloc(sizeof(struct Node));
 		temp = temp->next;
 		temp->next = NULL;

 		if(first)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}

 		else if(second)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 	}
}



void subPolynomial1(struct Node** result, struct Node* first, struct Node* second)
{
 	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 	temp->next = NULL;
 	*result = temp;
 	while(first && second)
 	{
 		if(first->pow > second->pow)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}
 		else if(first->pow < second->pow)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 		else
 		{
 			temp->coeff =second->coeff-first->coeff ;
 			temp->pow = first->pow;
 			first = first->next;
 			second = second->next;
 		}

 		if(first && second)
 		{
 			temp->next = (struct Node*)malloc(sizeof(struct Node));
 			temp = temp->next;
 			temp->next = NULL;
 		}
 	}
 	while(first || second)
 	{
 		temp->next = (struct Node*)malloc(sizeof(struct Node));
 		temp = temp->next;
 		temp->next = NULL;

 		if(first)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}

 		else if(second)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 	}
}

void max_c(int *max1 , struct Node* poly){
    *max1=0;
    while(poly!=NULL){
    if(poly->coeff > *max1){
        *max1=poly->coeff;
        }
        poly=poly->next;
    }
}

void max_p(int *max2 , struct Node* poly){
    *max2=0;
    while(poly!=NULL){
    if(poly->pow > *max2){
        *max2=poly->pow;
        }
        poly=poly->next;
    }
}



int main()
{

	struct Node* first = NULL;
	struct Node* second = NULL;
	struct Node* result = NULL;

	printf("\nGive input for First polynomial:\n");
	readPolynomial(&first);
	displayPolynomial(first);
	printf("\nGive input for Second polynomial:\n");
	readPolynomial(&second);
	displayPolynomial(second);
	//addPolynomials(&result, first, second);
	subPolynomial2(&result, first, second);
    //subPolynomial1(&result, first, second);
    displayPolynomial(result);

	int max1;
	int max2;
    max_c(&max1, first);
    max_p(&max2, first);

    printf("Maximum coefficient and power of poly 1 is -> ");

    printf("\n %d ", max1);
    printf("\n %d", max2);

    max_c(&max1, second);
    max_p(&max2, second);

    printf("Maximum coeff and power of poly 2 is -> ");

    printf("\n %d ", max1);
    printf("\n %d", max2);
	return 0;
}
