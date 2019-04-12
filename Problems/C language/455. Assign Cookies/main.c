#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

int findContentChildren(int* g, int gSize, int* s, int sSize);
int Compare(const int* i, const int* j);

int main(void)
{
	int inputChildren[] = { 10,9,8,7 };
	int inputCookies[] = {5,6,7,8};
	int inputChildrenSize = sizeof(inputChildren) / sizeof(inputChildren[0]);
	int inputCookiesSize = sizeof(inputCookies) / sizeof(inputCookies[0]);
	printf("%d\n", findContentChildren(inputChildren, inputChildrenSize, inputCookies, inputCookiesSize));
	_getch();
	return 0;
}

int Compare(const int* i, const int* j)
{
	return *i - *j;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
	int result = 0;
	qsort(g, gSize, sizeof(int), (int(*)(const void*, const void*))Compare);
	qsort(s, sSize, sizeof(int), (int(*)(const void*, const void*))Compare);
	int j = 0;
	for (int i = 0; i < sSize; i++)
	{
		if (g[j] <= s[i])
		{
			result++;
			j++;
			if (j >= gSize)
			{
				break;
			}
		}
	}
	return result;
}
