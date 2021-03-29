/*
 * shargutils.h
 *
 *  Created on: 29.03.2021
 *      Author: alexander
 */

#ifndef SHARGUTILS_H_
#define SHARGUTILS_H_

typedef int SHARGUTILS_BOOLEAN;
typedef int SHARGUTILS_ARGUMENT;

#define true 1
#define false 0

/**
 * void shargutils_initialize(int optionscount);
 *
 * Initializes this library. The argument "optionscount" is the amount of "options" this program has.
 * See the GitHub documentation for more information.
 * The reason why you need to specify this in the initializer is because an array needs to be malloc'd.
 *
 */
void shargutils_initalize(int optionscount, int parargc, char** parargs);

/**
 * Registers a possible argument. Returns the ID "handle".
 *
 */
SHARGUTILS_ARGUMENT shargutils_register_argument(char** argument);


/**
 * Get if a flag was set.
 *
 */
SHARGUTILS_BOOLEAN shargutils_get_flag_set(SHARGUTILS_ARGUMENT key);

/**
 * This cleans up all the malloc'd memory, if you don't do this, you'll have a memory leak. Be careful.
 *
 */
void shargutils_cleanup(void);

/**
 *	gets the value for any given argument.
 *
 *
 */
char* shargutils_get_value_for_key(SHARGUTILS_ARGUMENT key);


#endif /* SHARGUTILS_H_ */
