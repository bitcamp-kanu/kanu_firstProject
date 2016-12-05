#include <stdio.h>										//28 ���� 6 ��ȭ��ȣ�� ��ũ����Ʈ ���� ����� �߰�
#include <stdlib.h>
#include <string.h>

typedef struct element	// �Ʒ� node����ü ���� ������ �ϳ�
{
	char name[20];
	char phone[20];
}element;
typedef struct node	//node ����ü ����
{
	struct element data;	//�̸�,��ȭ��ȣ ������
	struct node * next;	//���� ��带 ����Ű�� ������
}node;

//���Ǵ� �Լ���
node *createnode(void);	//node�ϳ��� ����� �Լ�. insert�Լ��� �ι�° ���ڷ� �����ϱ�����
void insert(node **phead, node *newnode);	//���Ḯ��Ʈ�� ������ node�� newnode�� �����Ű�� �Լ�
node *search(node *phead);		//�Է��� �̸��� ���� node�� ã�� �Լ�
void delete(node **phead, node *remove);	//remove��带 search�Լ��� ã�Ƽ� ���ڷ� �����Ѵ�
void display(node *head);		//���Ḯ��Ʈ�� ��� ������ ����ϴ� �Լ�
void writefile(node *phead);	//����� ���Ͽ� ���Ḯ��Ʈ�� ������ �����ϴ� �Լ�

int main()
{
	node *head = NULL;	//��� ������ ����
	int num = 0;
	int in = 0;
	node *se;	   //switch ���� case 3: ���� ã�� ����� �ּҰ��� �ӽ÷� �����ϱ� ���ؼ�
	int i = 0;

	FILE *des = fopen("C:\\linked listfile.txt", "rt");	//������ ������ ���ʷ� ���Ḯ��Ʈ ������ ���� �Է½�Ʈ�� ����

	if (des == NULL)	//�Է½�Ʈ���� ������ Ȯ��
	{
		printf("���� �б� ����!\n");
		return -1;	//���������� ���Ḧ �ǹ�
	}
	while (feof(des) == 0)
	{
		char ch;
		ch = fgetc(des);
		if (ch == ':')
		{
			char name[20];
			char phone[20];
			if (i % 2 == 0)
				fgets(name, sizeof(name), des);
			else if (i % 2 == 1)
			{
				int j = 0;
				node *newnode = (node *)malloc(sizeof(node));
				newnode->next = NULL;
				fgets(phone, sizeof(phone), des);
				for (j = 0; j<20; j++)
				{
					if (name[j] == '\n')	//name�� ����� \n�� 0���� �ٲ��ش�.
						name[j] = 0;

					if (phone[j] == '\n')	//phon�� ����� \n�� 0���� �ٲ��ش�.
						phone[j] = 0;
				}
				strncpy(newnode->data.name, name, sizeof(newnode->data.name));
				strncpy(newnode->data.phone, phone, sizeof(newnode->data.phone));
				insert(&head, newnode);
			}
			i++;
		}
	}
	fclose(des);
	/*������ ���뿡�� ':' �̿��ؼ� ':' ������ ������ ���ڿ��� name,phon�� ���ʴ�� �ִ´�. �׸���
	�������� ���ο� ��忡 name,phon�� �Է½�Ű�� �� ���ο� ���� ���Ḯ��Ʈ�� �����Ѵ�.*/
	while (1)
	{
		printf("*****MENU*****\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Search\n");
		printf("4.Print All\n");
		printf("5.Exit\n");
		printf("Choose the item:");
		scanf("%d", &num);

		switch (num)		//switch ���� �̿��ؼ� �޴��� ����.
		{
		case 1:
			insert(&head, createnode());
			break;
		case 2:
			delete(&head, search(head));
			break;
		case 3:
			se = search(head);
			if (se != NULL)
			{
				printf("�̸� : %s ", se->data.name);
				printf("��ȣ : %s\n", se->data.phone);
			}
			else
			{
				printf("�����ϴ�!"); printf("\n");
			}
			break;
		case 4:
			display(head);
			break;
		default:
			writefile(head);
			break;
		}
		if (num == 5)
			break;
	}
	return 0;
}
node *createnode(void)
{
	node *newnode = (node*)malloc(sizeof(node));		//���ο� ��� ����
	printf("�̸� �Է�:");	scanf("%s", (newnode->data).name);	//name �Է�
	printf("��ȣ �Է�:");	scanf("%s", (newnode->data).phone);	//phone �Է�
	newnode->next = NULL;
	return newnode;	//newnode �� �ּҰ��� ��ȯ
}
void insert(node **phead, node *newnode)
{
	node *ptr = *phead;
	node *p;
	if (*phead == NULL)	//���Ḯ��Ʈ�� �ƹ� ������ ������
	{
		(*phead) = newnode;
		newnode->next = NULL;
	}
	else
	{
		while (ptr != NULL)	//������ ����� �ּҰ��� ã�� �ݺ���
		{
			p = ptr;
			ptr = ptr->next;
		}
		ptr = newnode;
		p->next = ptr;	//���Ḯ��Ʈ�� ���� newnode�� ����
	}
}
node *search(node *phead)
{
	node *ptr = phead;
	element el;
	printf("�̸� �Է�:");	scanf("%s", el.name);
	while (ptr != NULL)
	{
		if (!strcmp(ptr->data.name, el.name))	//�� ����� ������ ���� �̸��� ã�� �̸��� ��
			return ptr;	//ã�� �̸��� ���� ����� �ּҰ��� ��ȯ
		ptr = ptr->next;
	}
	return NULL;
}
void delete(node **phead, node *remove)
{
	node *ptr = *phead;
	node *p;
	if (ptr == NULL)
		return;
	else
	{
		if (*phead == remove)		//ù��° ��带 �����Ҷ�
		{
			*phead = (*phead)->next;
			free(remove);
		}
		else
		{
			while (ptr != NULL)
			{
				if (ptr == remove)
				{
					p->next = remove->next;	//remove��带 ���Ḯ��Ʈ���� ����
					free(remove);
					return;
				}
				p = ptr;
				ptr = ptr->next;
			}
		}
	}
}
void display(node *head)
{
	int i = 1;
	node *p = head;
	while (p != NULL)
	{
		printf("%d��°\n", i);
		printf("�̸�:%s\n", (p->data).name);
		printf("��ȣ:%s\n\n", (p->data).phone);
		p = p->next;
		i++;
	}
}
void writefile(node *phead)
{
	node *ptr = phead;
	int i = '1';
	FILE *des = fopen("c:\\linked listfile.txt", "wt");	//��� ��Ʈ�� ����

	if (ptr == NULL)
		return;
	else
	{
		while (ptr != NULL)
		{
			fputc(i, des); fputs("��°\n", des);
			fputs("�̸�:", des); fputs(ptr->data.name, des); fputs("\n", des);
			fputs("��ȣ:", des); fputs(ptr->data.phone, des); fputs("\n", des);
			ptr = ptr->next;
			i++;
		}
	}
	fclose(des);
	return;
}