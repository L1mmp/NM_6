#include "QrEq.h"

int main()
{
	setlocale(LC_ALL, "russian");
	cout << "Первое приближение: " << endl;
	QrEq qreq(2.7, 1.4, 1.e-6);

	cout << endl << "Второе приближение: " << endl;
	qreq.SetXY(1.0, 0.4);
	return 0;
}


