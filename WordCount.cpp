#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 1024

void fun1()
{
	char buf[MAX_NUM];
	FILE* fp;
	int len, total = 0;
	if ((fp = fopen("test.txt", "r")) == NULL) {
		perror("the file fail to read");
		getchar();
		exit(1);
	}
	while (!feof(fp) && !ferror(fp))
	{
		fgets(buf, MAX_NUM, fp);
		len = strlen(buf);
		for (int i = 0; i < len; i++)
		{
			if (buf[i] == ' ' || buf[i] == '	' || buf[i] == '\n')
			{
				total++;
			}
		}
	}
	printf("字符数：%d", total);
	fclose(fp);
}
void fun2()
{
	char buf[MAX_NUM];
	FILE* fp;
	int len, total = 0;
	if ((fp = fopen("test.txt", "r")) == NULL) {
		perror("the file fail to read");
		getchar();
		exit(1);
	}
	while (!feof(fp) && !ferror(fp))
	{
		fgets(buf, MAX_NUM, fp);
		len = strlen(buf);
		for (int i = 0; i < len; i++)
		{
			if (buf[i] != ' ' && buf[i]!='	'&& buf[i]!='\n')
			{
				total++;
			}
		}
	}
	printf("单词数：%d", total);
	fclose(fp);
}
void fun(char a, char c)
{
	if (a == '-' && c == 'c')
	{
		fun1();
	}
	else if (a == '-' && c == 'w')
	{
		fun2();
	}

}
int main() {
	char a, c;
	scanf("%c %c", &a, &c);
	fun(a, c);
	return 0;
}

