#include "suma.h"

int *suma_1_svc(peticion *argp, struct svc_req *rqstp)
{
	static int  result;

	result = argp->a + argp->b;

	return(&result);
}
