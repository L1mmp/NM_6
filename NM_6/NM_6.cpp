#include "QrEq.h"

int main()
{
	QrEq qreq(1.4, 0.8, pow(10, -6));
	qreq.SetXY(4, -1);
	qreq.SetXY(6, -1.5);
	return 0;
}


