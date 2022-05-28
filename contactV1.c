#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"


void Initcontact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

void Addcontact(struct Contact* ps)
{
	//判断通讯录是否已满
	//if (ps->size == MAX)
	//{
	//	printf("通讯录已满\n");
	//}
	if(ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity==0?4:ps->capacity*2;
		Peoinfo* tmp = (Peoinfo*)realloc(ps->data,sizeof(Peoinfo)*newcapacity);
		if(tmp==NULL)
		{
			exit(-1);
		}
		else
		{
			ps->capacity = newcapacity;
			ps->data = tmp;
		}
		printf("增容成功");
	}
	else
	{
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
}

void Showcontact(struct Contact* ps)
{
	//判断通讯录是否为空
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\t\n","名字","年龄","性别","电话","地址");
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

int Findbyname(struct Contact* ps,char name[MAX_NAME])
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

void Delcontact(struct Contact* ps)
{
	int pos = 0;
	char name[MAX_NAME] = { 0 };
	printf("请输入要删除人的名字\n");
	scanf("%s", &name);
	//查找要删除的人在什么位置
	pos = Findbyname(ps, name);
	//遍历完也找不到
	if (-1 == pos )
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//删除
		int j = 0;
		for (j = pos; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void Searchcontact(struct Contact* ps)
{
	int pos = 0;
	char name[MAX_NAME];
	printf("请输入要查找人的名字\n");
	scanf("%s", &name);
	pos = Findbyname(ps, name);
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
int sort_by_name(const void* e1,const void*e2)
{
	//strcmp比较字符串
	return(strcmp(((Contact*)e1)->data->name,((Contact*)e2)->data->name));
}
void Sortcontact(struct Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), sort_by_name);
	printf("排序成功\n");
}