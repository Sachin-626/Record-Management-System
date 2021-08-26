#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node *create_node();

struct node
{
	struct accommodation
	{		
		char firstname[50];
		char lastname[50];
		char accommodation_type[20];
		int idtype;
		struct idnum
		{	
			char aadhaar[15];
			char passport[15];
			char empcode[15];
		}p;
		char address[100];
	}A;
	struct node *next;
};

struct node *create_node()
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr->next = NULL;
	return(ptr);
}

void operationDone();
void InsertRecord(struct node **head);
void InsertRecord(struct node **head);
void printAllRecords(struct node *head);
void removeDuplicates(struct node **head);
void printRecords(struct node *head);

void operationDone()
{
	printf("\n\n-----------------------------------------------------------------------------------------------------------------------\n\n");
}

void InsertRecord(struct node **head)
{
	int i=0;
	struct node *temp,*ptr = create_node();

	temp = *head;
	if(*head == NULL)
	{
		*head = ptr;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = ptr;
	}
	
	printf("\nFirst_name = ");
	scanf("%s",ptr->A.firstname);
	
	printf("Last_name = ");
	scanf("%s",ptr->A.lastname);
	
	printf("Accommodation_tpye = ");
	scanf("%s",ptr->A.accommodation_type);
	
	printf("idtpye = ");
	scanf("%d",&ptr->A.idtype);
	
	if(ptr->A.idtype == 0)
	{
		printf("Aadhaar and address = ");
		scanf("%s ",ptr->A.p.aadhaar);
	}
	else if(ptr->A.idtype == 1)
	{
		printf("Passport and address = ");
		scanf("%s ",ptr->A.p.passport);	
	}
	else if(ptr->A.idtype == 2)
	{
		printf("Empcode and address= ");
		scanf("%s ",ptr->A.p.empcode);
	}
	
	scanf("%[^\n]s ",ptr->A.address);
}

void printAllRecords(struct node *head)
{
	struct node *ptr = head;
	
	if(ptr != NULL)
	{
		printf("\n\n\nRecords :");
		while(ptr != NULL)
		{
			printf("\n\nFirst_name = %s",ptr->A.firstname);
			printf("\nLast_name = %s",ptr->A.lastname);
			printf("\nAccommodation_tpye = %s",ptr->A.accommodation_type);
			printf("\nidtpye = %d\n",ptr->A.idtype);
	
			if(ptr->A.idtype == 0)
			{
				printf("Aadhaar and address = %s",ptr->A.p.aadhaar);
			}
			else if(ptr->A.idtype == 1)
			{
				printf("Passport and address = %s",ptr->A.p.passport);
			}
			else if(ptr->A.idtype == 2)
			{
				printf("Empcode and address= %s",ptr->A.p.empcode);
			}
			printf("\nAddress = %s",ptr->A.address);
			ptr = ptr->next;
		}
	}
	else
	{
		printf("Records are empty.");
	}
}	

void removeDuplicates(struct node **head)
{
	struct node *ptr1,*ptr2,*temp,*prev;
	ptr1 = *head;
	bool equal = false;
	
	if(ptr1 != NULL)
	{
		while(ptr1 != NULL)
		{
			prev = ptr1;
			ptr2 = ptr1->next;
			while(ptr2 != NULL)
			{
				equal = false;
				if(strcmp(ptr1->A.firstname,ptr2->A.firstname)==0 && strcmp(ptr1->A.lastname,ptr2->A.lastname)==0 && 
				strcmp(ptr1->A.accommodation_type,ptr2->A.accommodation_type)==0 && strcmp(ptr1->A.address,ptr2->A.address)==0) 
				{
					equal = true;
					if(ptr1->A.idtype == ptr2->A.idtype)
					{
						if(ptr1->A.idtype == 0 && strcmp(ptr1->A.p.aadhaar,ptr2->A.p.aadhaar) != 0)
						{
							equal = false;
						}
						else if(ptr1->A.idtype == 1 && strcmp(ptr1->A.p.empcode,ptr2->A.p.empcode) == 0)
						{
							equal = false;
						}
						else if(ptr1->A.idtype == 2 && strcmp(ptr1->A.p.passport,ptr2->A.p.passport) != 0)
						{
							equal = false;
						}
					}
				}
				if(equal == true)
				{
					temp = ptr2;
					prev->next = ptr2->next;
					ptr2 = ptr2->next;
					free(temp);
				}
				else
				{
					prev = ptr2;
					ptr2 = ptr2->next;
				}
			}
			ptr1 = ptr1->next;
		}
		printf("\nDuplicate records are deleted sucessfully");
	}
	else
	{
		printf("Records are empty.");
	}
}

void printRecords(struct node *head)
{
	struct node *ptr;
	int i=0;
	for(i=0;i<3;i++)
	{
		ptr = head;
		while(ptr != NULL)
		{
			if(ptr->A.idtype == i)
			{
				printf("\n\nFirst_name = %s",ptr->A.firstname);
				printf("\nLast_name = %s",ptr->A.lastname);
				printf("\nAccommodation_tpye = %s",ptr->A.accommodation_type);
				printf("\nidtpye = %d\n",ptr->A.idtype);
		
				if(i == 0)
				{
					printf("Aadhaar and address = %s",ptr->A.p.aadhaar);
				}
				else if(i == 1)
				{
					printf("Passport and address = %s",ptr->A.p.passport);
				}
				else if(i == 2)
				{
					printf("Empcode and address= %s",ptr->A.p.empcode);
				}
				printf("\nAddress = %s",ptr->A.address);
			}
			ptr = ptr->next;
		}
	}
}


struct node_with_index *create_inode();
void printSortedRecords(struct node *head);
void search(struct node *head,char fn[],char ln[]);
void deleteRecord(struct node **head,int Id_Type,char id[]);
void updateRecord(struct node *head);


struct node_with_index
{
	struct accommodation A;
	int index;
	struct node_with_index *next;
}*ihead = NULL;

int LL_count=0;

struct node_with_index *create_inode()
{
	struct node_with_index *ptr = (struct node_with_index*)malloc(sizeof(struct node_with_index));
	ptr->next = NULL;
	ptr->index = -1;
	return(ptr);
}


void printSortedRecords(struct node *head);
void search(struct node *head,char fn[],char ln[]);
void deleteRecord(struct node **head,int Id_Type,char id[]);
void updateRecord(struct node *head);


void printSortedRecords(struct node *head)
{
	struct node_with_index *iptr,*lptr,*lPrev,*temp;
	int i=0;
	
	if(ihead == NULL)
	{
		iptr = create_inode();
		ihead = iptr;
		iptr->A = head->A;
		head = head->next;
		while(head != NULL)	
		{
			iptr->next = create_inode();
			iptr = iptr->next;
			iptr->A = head->A;
			head = head->next;
			i++;
		}
		LL_count = i+1;
		iptr = ihead;
		
		for(i=0;i<LL_count;i++)
		{
			temp = ihead;
			while(temp != NULL && temp->index != -1)
			{
				temp = temp->next;
			}
			
			lptr = temp->next;
			while(lptr != NULL)
			{
				if(lptr->index == -1)
				{
					if(strcmp(temp->A.firstname,lptr->A.firstname) > 0)
					{
						temp = lptr;
					}	
					else if(strcmp(temp->A.firstname,lptr->A.firstname) == 0 && strcmp(temp->A.lastname,lptr->A.lastname) > 0)
					{
						temp = lptr;
					}
				}
				lptr = lptr->next;
			}
			temp->index = i;
		}
	}
	
	i=0;
	while(i != LL_count)
	{
		iptr = ihead;
		while(iptr != NULL && iptr->index != i)
		{
			iptr = iptr->next;
		}
		printf("\n\nFirst_name = %s",iptr->A.firstname);
		printf("\nLast_name = %s",iptr->A.lastname);
		printf("\nAccommodation_tpye = %s",iptr->A.accommodation_type);
		printf("\nidtpye = %d\n",iptr->A.idtype);
	
		if(iptr->A.idtype == 0)
		{
			printf("Aadhaar and address = %s",iptr->A.p.aadhaar);
		}
		else if(iptr->A.idtype == 1)
		{
			printf("Passport and address = %s",iptr->A.p.passport);
		}
		else if(iptr->A.idtype == 2)
		{
			printf("Empcode and address= %s",iptr->A.p.empcode);
		}
		printf("\nAddress = %s",iptr->A.address);
		i++;
	}
}

void search(struct node *head,char fn[],char ln[])
{
	bool found = false;
	while(head != NULL)
	{
		if(strcmp(head->A.firstname,fn) ==0 && strcmp(head->A.lastname,ln) == 0)
		{
			found = true;
			printf("\n\nFirst_name = %s",head->A.firstname);
			printf("\nLast_name = %s",head->A.lastname);
			printf("\nAccommodation_tpye = %s",head->A.accommodation_type);
			printf("\nidtpye = %d\n",head->A.idtype);
			if(head->A.idtype == 0)
			{
				printf("Aadhaar and address = %s",head->A.p.aadhaar);
			}
			else if(head->A.idtype == 1)
			{
				printf("Passport and address = %s",head->A.p.passport);
			}
			else if(head->A.idtype == 2)
			{
				printf("Empcode and address= %s",head->A.p.empcode);
			}
			printf("\nAddress = %s",head->A.address);
			return;
		}
		head = head->next;
	}
	if(found == false)
	{
		printf("\nNo person with the name %s %s was found in the record.",fn,ln);
	}
}

void deleteRecord(struct node **head,int Id_Type,char id[])
{
	struct node *temp,*ptr,*prev;
	bool del = false;
	int n;
	ptr = *head;
	prev = NULL;
	while(ptr != NULL)
	{
		if(Id_Type == ptr->A.idtype)
		{
			if(ptr->A.idtype == 0)
			{
				if(strcmp(ptr->A.p.aadhaar,id) == 0)
				{
					del = true;
				}
			}
			else if(ptr->A.idtype == 1)
			{
				if(strcmp(ptr->A.p.passport,id) == 0)
				{
					del = true;
				}
			}
			else if(ptr->A.idtype == 2)
			{
				if(strcmp(ptr->A.p.empcode,id) == 0)
				{
					del = true;
				}
			}
			
			if(del == true)
			{
				if(ptr == *head)
				{
					*head = ptr->next;
				}
				else
				{
					prev->next = ptr->next;
				}
				struct node_with_index *iptr,*iprev;
				iptr = ihead;
				iprev = NULL;
				if(iptr != NULL)
				{
					while(strcmp(iptr->A.firstname,ptr->A.firstname) != 0 || strcmp(iptr->A.lastname,ptr->A.lastname) != 0)
					{
						iprev = iptr;
						iptr = iptr->next;	
					}
					n = iptr->index;
					if(iprev != NULL)
					{
						iprev->next = iptr->next;
					}
					else
					{
						ihead = iptr->next;
					}
					struct node_with_index *f = iptr;
					free(f);
					LL_count--;
						
					iptr = ihead;
					
					while(iptr != NULL)
					{
						if(iptr->index > n)
						{
							iptr->index = iptr->index - 1;
						}
						iptr = iptr->next;
					}
					
				}
				free(ptr);
				return;
			}
		}
		prev = ptr;
		ptr = ptr->next;
	}
	printf("No person found with Id Type = %d and Id No. = %s",Id_Type,id);
	
}

void updateRecord(struct node *head)
{
	int iIndex,flag=1,i=0;
	char fn[50],ln[50];
	struct node *ptr;
	struct node_with_index *iptr,*p;
	ptr = head;
	iptr = ihead;
	printf("\nEnter the firstname and lastname of the person whose record you want to update.\nName = ");
	scanf("%s %s",fn,ln);
	
	while(ptr != NULL && (strcmp(fn,ptr->A.firstname) != 0 || strcmp(ln,ptr->A.lastname) != 0))
	{
		ptr = ptr->next;
		iptr = iptr->next;
	}
	if(ptr != NULL)
	{
		int choice;
		printf("\n\nEnter the no. of field you want to update.");
		printf("\n1. Firstname \n2. Lastname \n3. Accomodation Type \n4. Id Type \n5. Address\n");
		printf("choice = ");
		scanf("%d",&choice);
		
		switch(choice)	
		{
			case 1:		
				printf("\nEnter new Firstname : ");
				scanf("%s",fn);
				strcpy(ptr->A.firstname,fn);
				strcpy(iptr->A.firstname,fn);
				
				iIndex = iptr->index;
				p = ihead;
				while(p != NULL)
				{
					if(strcmp(p->A.firstname,iptr->A.firstname) < 0)
					{
						i++;
					}
					else if(strcmp(p->A.firstname,iptr->A.firstname) == 0 && strcmp(p->A.lastname,iptr->A.lastname) < 0 )
					{
						i++;
					}
					p = p->next;	
				}
				p = ihead;
				if(iIndex > i)
				{
					while(p != NULL)
					{
						if(p->index >= i && p->index < iIndex)
						{
							p->index = p->index + 1;
						}
						p = p->next;
					}
					iptr->index = i;
				}
				else if(iIndex < i)
				{
					while(p != NULL)
					{
						if(p->index <= i && p->index > iIndex)	
						{
							p->index = p->index - 1;
						}
						p = p->next;
						iptr->index = i;
					}
				}
				p = ihead;
				while(p != NULL)
				{
					p=p->next;
				}
				break;
			
			case 2:
				printf("\nEnter new Lastname : ");
				scanf("%s",ln);
				strcpy(ptr->A.lastname,ln);
				strcpy(iptr->A.lastname,ln);
				
				iIndex = iptr->index;
				p = ihead;
				while(p != NULL)
				{
					if(strcmp(p->A.firstname,iptr->A.firstname) < 0)
					{
						i++;
					}
					else if(strcmp(p->A.firstname,iptr->A.firstname) == 0 && strcmp(p->A.lastname,iptr->A.lastname) < 0 )
					{
						i++;
					}
					p = p->next;	
				}
				p = ihead;
				if(iIndex > i)
				{
					while(p != NULL)
					{
						if(p->index <= i && p->index > iIndex)
						{
							p->index = p->index + 1;
						}
						p = p->next;
					}
					iptr->index = i;
				}
				else if(iIndex < i)
				{
					while(p != NULL)
					{
						if(p->index <=i && p->index > iIndex)	
						{
							p->index = p->index - 1;
						}
						iptr->index = i;
					}
				}
				break;
			
			case 3:
				printf("\nEnter the new Accomodation type = ");
				scanf("%s",fn);
				strcpy(ptr->A.accommodation_type,fn);
				strcpy(iptr->A.accommodation_type,fn);
				break;
			
			case 4:
				printf("\nEnter the Idtype = ");
				scanf("%d",&ptr->A.idtype);
				iptr->A.idtype = ptr->A.idtype;
				if(ptr->A.idtype == 0)
				{
					printf("Enter Aadhaar no. = ");
					scanf("%s",ptr->A.p.aadhaar);
					strcpy(iptr->A.p.aadhaar,ptr->A.p.aadhaar);
				}
				else if(ptr->A.idtype == 1)
				{
					printf("Enter Passport no. = ");
					scanf("%s",ptr->A.p.aadhaar);
					strcpy(iptr->A.p.aadhaar,ptr->A.p.aadhaar);
				}
				else if(ptr->A.idtype == 2)
				{
					printf("Enter Empcode no. = ");
					scanf("%s",ptr->A.p.empcode);
					strcpy(iptr->A.p.empcode,ptr->A.p.empcode);
				}
				else
				{
					printf("\nInvalid ID Type");
				}
				break;
			case 5:
				printf("\nEnter new Address : ");
				scanf("%[^\n]s ",ptr->A.address);
				strcmp(iptr->A.address,iptr->A.address);
		}
	}
	else
	{
		printf("No record found with name %s %s",fn,ln);
	}
}

struct accomodation_status
{
	int status;
	struct accomodation_status *next;
}*acc[4] = {NULL};

struct accomodation_status *create_acc()
{
	struct accomodation_status *aptr = (struct accomodation_status*)malloc(sizeof(struct accomodation_status));
	aptr->status = 0;
	aptr->next = NULL;
	return(aptr);
} 


void insert_accomodation();
void print_accomodation_status();
void specialRequestAllocation();


void insert_accomodation()
{
	int i,j;
	struct accomodation_status *aptr;
	
	printf("\n\nEnter data in accomodation list");
	printf("\n\nEnter 1 if the block is accomodated and 0 if it is not accommodated.");
	for(i=0;i<4;i++)
	{
		printf("\n\nType%d Blocks :",i+1);
		acc[i] = create_acc();
		aptr = acc[i];
		printf("\nBLock 0 = ");
		scanf("%d",&aptr->status);
		
		for(j=1;j<10;j++)
		{
			aptr->next = create_acc();
			aptr = aptr->next;
			printf("BLock %d = ",j);
			scanf("%d",&aptr->status);
		}
	}
}

void print_accomodation_status()
{
	struct accomodation_status *aptr;
	int i,j=0;
	printf("\nAccomodation List :");
	for(i=0;i<4;i++)
	{
		aptr = acc[i];
		j=0;
		printf("\n\nType%d Blocks :",i+1);
		while(aptr != NULL)
		{
			printf("\nBlock %d = %d",j,aptr->status);
			j++;
			aptr = aptr->next;
		}
	}
}

void specialRequestAllocation()
{
	struct accomodation_status *aptr,*prev,*nptr;
	int t_old,t_new,index,i=0;
	printf("Enter the Type of the block whose type you want to change. \nt_old = ");
	scanf("%d",&t_old);
	printf("Enter the index of the block = ");
	scanf("%d",&index);
	printf("Enter the new type of the block = ");
	scanf("%d",&t_new);
	
	aptr = acc[t_old-1];
	nptr = acc[t_new-1];
	prev = NULL;
	while(i != index)
	{
		prev = aptr;
		aptr = aptr->next;
		i++;
	}
	
	if(aptr->status != 0)
	{
		if(prev == NULL)
		{
			acc[t_old-1] = aptr->next;
		}
		else
		{
			prev->next = aptr->next;
		}
		
		while(nptr->next != NULL)
		{
			nptr = nptr->next;
		}
		nptr->next = create_acc();
		nptr = nptr->next;
		nptr->status = aptr->status;
		free(aptr);
	}
	else
	{
		printf("\nCan't update the block type because it is not allocated.");
	}
}

int main()
{
	int n,i,choice;
	char fn[50],ln[50],ID[15];
	struct node *head;
	head = NULL;
	
	printf("Enter the no. of records = ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		InsertRecord(&head);
	}
	operationDone();
	removeDuplicates(&head);
	operationDone();
	insert_accomodation();
	operationDone();
	
	while(choice != 9)
	{
		printf("\n\nEnter the operation no. that you want to be performed.");
		printf("\n1. Print all records \n2. Print Records sorted according to id \n3. Printing Records sorted ");
		printf("according to alphabetical order of their name \n4. Printing the data of a particular person.");
		printf("\n5. Deleting a particular data \n6. Updating a particular record \n7. Printing Accomodation List");
		printf("\n8. Changing the type of a accomodation block \n9. Exit");
		
		printf("\nChoice = ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printAllRecords(head);
				operationDone();
				break;
				
			case 2:
				printRecords(head);
				operationDone();
				break;
				
			case 3:
				printSortedRecords(head);
				operationDone();
				break;
				
			case 4:
				printf("\nEnter the firstname and lastname of the person whose data you want to print");
				scanf("%s %s",fn,ln);
				search(head,fn,ln);
				operationDone();
				break;
			
			case 5:
				printf("\nEnter the id type and IdNo. of the person whose data you want to delete.");
				printf("\nId Type = ");
				scanf("%d",&i);
				printf("Id no. = ");
				scanf("%s",ID);
				deleteRecord(&head,i,ID);
				operationDone();
				break;
				
			case 6:
				updateRecord(head);
				operationDone();
				break;
				
			case 7:
				print_accomodation_status();
				operationDone();
				break;
			
			case 8:
				specialRequestAllocation();
				operationDone();
				break;
				
			case 9:
				exit(0);
				
			default: 
				printf("Invalid Choice");
		}
	}
	return(0);
}
