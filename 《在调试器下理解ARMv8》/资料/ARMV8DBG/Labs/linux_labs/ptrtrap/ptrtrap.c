#include <stdio.h>

int main(int argc, char* argv[])
{
	char* name = get_name(argv[0]);
	printf("Demo of pointer trap by Raymond.\n");
	printf("Name: %s\n", name);
	
	return 0;
}

