/*
 * shargsutils.c
 *
 *  Created on: 29.03.2021
 *      Author: alexander
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/shargutils.h"

static int shargutils_tablehead;
static int shargutils_tablesize;
static char*** shargutils_tableptr; //this is hideous
static char** shargutils_args;
static int shargutils_argc;

void shargutils_initalize(int optionscount, int parargc, char** parargs) {
	shargutils_tableptr = malloc(optionscount * sizeof(char**));
	shargutils_tablehead = 0;
	shargutils_tablesize = optionscount;
	shargutils_args = parargs;
	shargutils_argc = parargc;
}

SHARGUTILS_ARGUMENT shargutils_register_argument(char** argument) {
	(shargutils_tableptr)[shargutils_tablehead] = argument;

	return shargutils_tablehead++;
}

void shargutils_cleanup(void) {
	free(shargutils_tableptr);
}

SHARGUTILS_BOOLEAN shargutils_get_flag_set(SHARGUTILS_ARGUMENT key) {
	char* argtype = *(shargutils_tableptr[key]);
	for(int i = 0; i < shargutils_argc; i++) {
		char* arg = shargutils_args[i];

		if(strcmp(arg, argtype) == 0) {
			return true;
		}
	}

	return false;
}

char* shargutils_get_value_for_key(SHARGUTILS_ARGUMENT key) {
	char* found = NULL;

	SHARGUTILS_BOOLEAN bf = false;
	int fIndex = 0;

	char* argtype = *(shargutils_tableptr[key]);

	for(int i = 0; i < shargutils_argc; i++) {
		char* arg = shargutils_args[i];
		if(strcmp(arg, argtype) == 0) {
			bf = true;
			fIndex = i;
			goto found; //yes, I know, goto is bad, but there is no straight-forward way to break out of nested loops
		}
	}

	printf("Fired2\n");

	return found;

	found:
	if(bf && (++fIndex) < shargutils_argc) {
		found = shargutils_args[fIndex];
	}

	return found;
}

