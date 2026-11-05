#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


void ChOf(char arr[], int len, int m, int t);
void Enc(char arr[], int len);
void Dec(char arr[], int len);


int main()//加密小算法
{
	char a[6000] = { 0 };
	int i, len = 0, m;

	printf("加密按1\n解密按0\n");
	scanf("%d", &i);
	printf("密钥（任意正整数）\n");//彩蛋：除了95的倍数
	scanf("%d", &m);
	while (getchar() != '\n');
	//输入并计算长度
	printf("请输入内容\n");
	scanf("%[^\n]", a);
	while (a[len] != '\0')
	{
		len++;
	}
	//加解密
	if (i == 1)
	{
		Enc(a, len);
		ChOf(a, len, m, 1);
	}
	else if (i == 0)
	{
		ChOf(a, len, m, 0);
		Dec(a, len);
	}
	//打印结果
	printf("[%s]\n", a);
	return 0;
}


void ChOf(char arr[], int len, int m, int t)//字符偏移：Character offset
{
	if (t == 1)//加密
	{
		for (int j = 0; j < len; j++)
		{
			arr[j] ^= m;
			arr[j] = (arr[j] - 32 + m) % 95 + 32;
		}
	}
	else	if (t == 0)//解密
	{
		for (int j = 0; j < len; j++)
		{
			//arr[j] = (arr[j]-30)%31;
			arr[j] = (arr[j] - 32 - m + 95) % 95 + 32;
			arr[j] ^= m;
		}
	}

}

void Enc(char arr[], int len)//[加密函数]
{
	char temp;
	printf("加密结果：\n");
	for (int i = 0; i < (len / 2); i++)//1.将字符串倒序
	{
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
	for (int j = 0; j < len - 1; j += 2)//2.将字符两两依次交换
	{
		temp = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = temp;
	}
}

void Dec(char arr[], int len)//[解密函数]
{
	char temp;
	printf("解密结果：\n");
	for (int j = 0; j < len - 1; j += 2)//1..将字符串两两依次交换
	{
		temp = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = temp;
	}
	for (int i = 0; i < (len / 2); i++)//2..将字符串倒序
	{
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
}