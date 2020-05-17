// Implements a spell-checker

#include <ctype.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>

int main(void){

	struct rusage before, after;

	getrusage(RUSAGE_SELF, &before);
	printf("\n\n%d", before.ru_utime.tv_usec);

	getrusage(RUSAGE_SELF, &before);
	printf("\n\n%d", before.ru_utime.tv_usec);

	getrusage(RUSAGE_SELF, &before);
	printf("\n\n%d", before.ru_utime.tv_usec);
	
	getrusage(RUSAGE_SELF, &before);
	printf("\n\n%d", before.ru_utime.tv_usec);

	// printf("\n\n%d", before.ru_utime.tv_usec);
	// printf("\n%d", after.ru_utime.tv_usec);
}