#include <stdio.h>
#include<Windows.h>

void print_sizeof(size_t size)
{
	printf("%d\n", size);
}

int main(void)
{
	print_sizeof(sizeof(int)); // 4
	print_sizeof(sizeof(long)); // 4
	print_sizeof(sizeof(unsigned int)); // 4
	print_sizeof(sizeof(unsigned long)); // 4
	print_sizeof(sizeof(char)); // 1
	print_sizeof(sizeof(unsigned char)); // 1
	print_sizeof(sizeof(int*)); // 4
	print_sizeof(sizeof(int**)); // 4
	print_sizeof(sizeof(double)); // 8
	print_sizeof(sizeof(long double)); // 8
	print_sizeof(sizeof(double*)); // 4
	print_sizeof(sizeof(short)); // 2
	print_sizeof(sizeof(unsigned __int8)); // 1
	print_sizeof(sizeof(unsigned __int16)); // 2
	print_sizeof(sizeof(unsigned __int32)); // 4
	print_sizeof(sizeof(unsigned __int64)); // 8
	print_sizeof(sizeof(wchar_t)); // 2
	print_sizeof(sizeof(long long)); // 8
	
	print_sizeof(sizeof(HWND)); // 4
	print_sizeof(sizeof(void*)); // 4

	print_sizeof(sizeof(DWORD)); // 4
	print_sizeof(sizeof(COLORREF)); // DWORD 4

	print_sizeof(sizeof(WPARAM)); // 4
	print_sizeof(sizeof(UINT_PTR)); // 4
	print_sizeof(sizeof(unsigned int)); // 4

	getchar();
}