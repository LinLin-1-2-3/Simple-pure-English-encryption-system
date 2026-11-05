#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void Enc(char arr[], int len)//[加密函数]
{
	char temp;
	printf("加密结果：\n");
	for (int i = 0; i < (len / 2); i++)//1...将字符串倒序
	{
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
	for (int j = 0; j < len - 1; j += 2)//2...将字符串两两依次交换
	{
		temp = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = temp;
	}
	for (int k = 0; k < len; k++)printf("%c", arr[k]);
}

void Dec(char arr[], int len)//[解密函数]
{
	char temp;
	printf("解密结果：\n");
	for (int j = 0; j < len - 1; j += 2)//1...将字符串两两依次交换
	{
		temp = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = temp;
	}
	for (int i = 0; i < (len / 2); i++)//2...将字符串倒序
	{
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
	for (int k = 0; k < len; k++)printf("%c", arr[k]);
}

int main()//加密小算法
{
	char a[10000] = { 0 };
	char* p = a;
	int i, len = 0;
	printf("加密按1\n解密按2\n");
	scanf("%d", &i);
	while (getchar() != '\n');
	printf("请输入内容\n");
	scanf("%[^\n]", a);
	while (a[len] != '\0')
	{
		len++;
	}
	if (i == 1)Enc(a, len);
	else if (i == 2)Dec(a, len);
	return 0;
}