#include <stdio.h>
#include <stdlib.h>

void main(){
	for (int i = 0; i < 256; i++){
		printf("%i\t%c\n", i, i);
	}
	system("pause");
}