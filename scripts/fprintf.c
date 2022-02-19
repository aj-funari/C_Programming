#include <stdio.h>

int main (void) {

	FILE *fp;
	char name[25];
	int age;

	printf("Enter ur name and age\n");
	scanf("%s%d", name, &age);

	fp = fopen("temp.c", "w");

	if (fp == NULL) {
		printf("Unable to open the file\n");
	} else  {
		fprintf(fp, "%s\t%d", name, age);
		printf("data written successfully\n");
		fclose(fp);
	}

	return(0);
}
