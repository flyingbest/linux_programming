#include <stdio.h>

int main(){
	int a = 0;
	{
		int a = 1;
	}
	printf("a = %d\n", a);
	return 0;
}
