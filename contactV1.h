
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
//#define MAX 1000


typedef struct People
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}Peoinfo;

typedef struct Contact
{
	Peoinfo* data;
	int capacity;
	int size;
}Contact;

void Initcontact(struct Contact* ps);
void Addcontact(struct Contact* ps);
void Showcontact(struct Contact* ps);
void Delcontact(struct Contact* ps);
void Searchcontact(struct Contact* ps);
void Sortcontact(struct Contact* ps);