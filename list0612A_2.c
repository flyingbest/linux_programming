#include <stdio.h>

int main(int argc, char* argv[], char* envp[]){
	int i = 0;
	while(envp[i] != NULL){
		printf("%d : %s\n", i, envp[i]);
		i++;
	}
	return 0;
}
