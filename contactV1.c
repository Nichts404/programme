#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void CheckCapacity(Contact* ps);

void InitContact(Contact* ps)
{
	ps->data = (PeoInfo*)malloc(DEFAULT_SIZE*sizeof(PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SIZE;
	//把文件中已经存放的通讯录中的信息加载到通讯录中
	LoadContact(ps);
}

void LoadContact(Contact* ps)
{
	PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	//读取文件，存放到通讯录
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}

	fclose(pfRead);
	pfRead = NULL;
}

void CheckCapacity(Contact* ps)
{
	//判断通讯录是否已满
	//if (ps->size == MAX)
	//{
	//	printf("通讯录已满\n");
	//}
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		PeoInfo* tmp = (PeoInfo*)realloc(ps->data, sizeof(PeoInfo)*newcapacity);
		if (tmp == NULL)
		{
			exit(-1);
		}
		else
		{
			ps->capacity = newcapacity;
			ps->data = tmp;
		}
		printf("增容成功\n");
	}
}
void AddContact(Contact* ps)
{
	CheckCapacity(ps);
	printf("请输入姓名>:");
	scanf("%s", &ps->data[ps->size].name);
	printf("请输入年龄>:");
	scanf("%d", &ps->data[ps->size].age);
	printf("请输入性别>:");
	scanf("%s", &ps->data[ps->size].sex);
	printf("请输入电话>:");
	scanf("%s", &ps->data[ps->size].tele);
	printf("请输入地址>:");
	scanf("%s", &ps->data[ps->size].addr);
	ps->size++;
	printf("添加成功\n");
}

void ShowContact(struct Contact* ps)
{
	//判断通讯录是否为空
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\t\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\t\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

int FindByName(Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(name, ps->data[i].name))
		{
			return i;
		}
	}
	return -1;//找不到的情况
}

void DelContact(Contact* ps)
{
	int pos = 0;
	char name[MAX_NAME] = { 0 };
	printf("请输入要删除人的名字\n");
	scanf("%s", &name);
	//查找要删除的人在什么位置
	pos = FindByName(ps, name);
	//遍历完也找不到
	if (-1 == pos)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//删除
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void SearchContact(Contact* ps)
{
	int pos = 0;
	char name[MAX_NAME];
	printf("请输入要查找人的名字\n");
	scanf("%s", &name);
	pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("找不到指定人的信息\n");
	}
	else
	{
		//打印要查找人的信息
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\t\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\t\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}
//根据名字排序
<<<<<<< HEAD
//int SortByName(const void* e1, const void*e2)
//{
//	//strcmp比较字符串
//	return(strcmp(((Contact*)e1)->data->name, ((Contact*)e2)->data->name));
//}
void SortContact(Contact* ps)
{
	for (int i = 0; i < ps->size - 1; i++)
	{
		for (int j = 0; j < ps->size - i - 1; j++)
		{
			if (strcmp(ps->Data[j].name, ps->Data[j + 1].name) > 0)
			{
				PeoInfo tmp = ps->Data[j];
				ps->Data[j] = ps->Data[j + 1];
				ps->Data[j + 1] = tmp;
			}
		}
	}
	printf("排序成功\n");
}
void DestoryContact(Contact* ps)
=======
int SortByName(const void* e1, const void*e2)
{
	//strcmp比较字符串
	return(strcmp(((Contact*)e1)->data->name, ((Contact*)e2)->data->name));
}
void SortContact(struct Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), SortByName);
	printf("排序成功\n");
}
void DestoryContact(struct Contact* ps)
>>>>>>> 08ea1d696e50aa9ab5edef00a3f602103382d646
{
	free(ps->data);
	ps->data = NULL;
}

void SaveContact(Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("%s\n"), strerror(errno);
		return ;
	}
	//写通讯录中的数据到文件中
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(PeoInfo),1,pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}