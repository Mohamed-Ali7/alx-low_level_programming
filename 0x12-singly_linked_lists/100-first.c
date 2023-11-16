#include <stdio.h>


/**
 * print_before_main - prints a statement before the main funtion is excuted
 * Return: void
 */
__attribute__((constructor))void print_frist(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
