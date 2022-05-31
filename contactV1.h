#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SIZE 0
//#define MAX 1000


typedef struct People
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

typedef struct Contact
{
	PeoInfo* data;
	int capacity;
	int size;
}Contact;

void InitContact(Contact* ps);
void AddContact(Contact* ps);
void ShowContact(Contact* ps);
void DelContact(Contact* ps);
void SearchContact(Contact* ps);
void SortContact(Contact* ps);
void DestoryContact(Contact* ps);
void SaveContact(Contact* ps);
void LoadContact(Contact* ps);