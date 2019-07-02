#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义数据结构
typedef struct node *nodeptr;
typedef struct node {
	char *word;
	int count;
	nodeptr next;
} node;

// 最多有29131个不同的单词
#define NHASH 29989
#define MULT 31
#define WORDMX 1024
nodeptr bin[NHASH];

// 散列函数把每个字符串映射为一个小于NHASH的正整数
unsigned int hash(char *p)
{
	unsigned int h = 0;
	for ( ; *p; p++)
	{
		h = MULT * h + *p;
	}
	return h % NHASH;
}

// 增加与输入单词相关联的计数器的值（如果以前没有这个单词，就对计数器进行初始化）
void incword(char *s)
{
	unsigned int h = hash(s);
	for (nodeptr p = bin[h]; p != NULL; p = p->next)
	{
		if (strcmp(s, p->word) == 0)
		{
			(p->count)++;
			return;
		}
	}

	nodeptr p = malloc(sizeof(node));
	p->count = 1;
	p->word = malloc(strlen(s) + 1);
	strcpy(p->word, s);
	p->next = bin[h];
	bin[h] = p;
}

// 首先把每个箱都初始化为NULL，接着读取单词并增加计数值，然后迭代散列表（未排序的）单词和计数器
int main(void)
{
	for (int i = 0; i < NHASH; i++)
		bin[i] = NULL;
	char buf[WORDMX];
	while (scanf("%s", buf) != EOF)
	{
		incword(buf);
	}

	for (int i = 0; i < NHASH; i++)
	{
		for (nodeptr p = bin[i]; p != NULL; p = p->next)
		{
			printf("%s, %d\n", p->word, p->count);
		}
	}

	return 0;
}
