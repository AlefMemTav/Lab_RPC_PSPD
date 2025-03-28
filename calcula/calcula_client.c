/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calcula.h"

int add(CLIENT *clnt, int x, int y)
{
	operandos ops;
	int *result;

	ops.x = x;
	ops.y = y;
	result = add_100(&ops, clnt);
	return (*result);
}

int sub(CLIENT *clnt, int x, int y)
{
	operandos ops;
	int *result;

	ops.x = x;
	ops.y = y;
	result = sub_100(&ops, clnt);
	return (*result);
}

int main(int argc, char *argv[])
{
	char *host;
	CLIENT *clnt;
	int x, y;

	if (argc < 2)
	{
		printf("usage: %s server_host\n", argv[0]);
		exit(1);
	}
	host = argv[1];
	clnt = clnt_create(host, PROG, VERSAO, "udp");
	x = atoi(argv[2]);
	y = atoi(argv[3]);
	printf("%d + %d = %d\n", x, y, add(clnt, x, y));
	printf("%d - %d = %d\n", x, y, sub(clnt, x, y));
	exit(0);
}
