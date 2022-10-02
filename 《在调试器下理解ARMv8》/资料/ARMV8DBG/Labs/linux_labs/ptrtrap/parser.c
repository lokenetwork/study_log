// parser.c
#include <string.h>

const char * get_name(const char* full_path)
{
	const char * sep = strrchr(full_path, '/');
	return (sep == NULL)? "errname": sep+1;	
}
