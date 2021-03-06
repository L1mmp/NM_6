#include"QrEq.h"

using namespace std;

double QrEq::F(double x, double y)// Превая функция системы.
{
	return pow(2, x - y) - y - 1;
}
double QrEq::G(double x, double y)// Вторая функция системы.
{
	return y*y*y + x*x - 6 * x + 6;
}
QrEq::QrEq(double x0, double y0, double E)
{
	ofile.open("output.txt");
	e = E;
	x = x0;
	y = y0;
	iter = 0;
	StartIter();
}
QrEq::~QrEq()
{
	ofile.close();
}
double QrEq::F_X(double x, double y)// Производная F по x.
{
	return pow(2, x - y) * log(2);
}
double QrEq::F_Y(double x, double y)// Производная F по y.
{
	return  -pow(2, x - y) * log(2) - 1;
}
double QrEq::G_X(double x, double y)// Производная G по x.
{
	return 2 * x - 6;
}
double QrEq::G_Y(double x, double y)// Производная G по y.
{
	return 3 * y * y;
}
void QrEq::SetXY(double x0, double y0)// Задает начальное приближение.
{
	x = x0;
	y = y0;
	StartIter();
}
void QrEq::FillW()// Составляет матрицу W.
{
	W[0][0] = F_X(x, y);
	W[0][1] = F_Y(x, y);
	W[1][0] = G_X(x, y);
	W[1][1] = G_Y(x, y);
}
void QrEq::StartIter()// Итерационный процесс.
{

	double bufX = 0;
	double bufY = 0;
	iter = 0;
	do
	{
		iter++;
		FillW();
		FillW_1();
		bufX = x;
		bufY = y;
		x = bufX - W_1[0][0] * F(bufX, bufY) - W_1[0][1] * G(bufX, bufY);
		y = bufY - W_1[1][0] * F(bufX, bufY) - W_1[1][1] * G(bufX, bufY);
		OutResult();
	} while (!Stop(bufX, bufY));
	OutResult();
}
double QrEq::det()// Считает детерминант.
{
	return W[0][0] * W[1][1] - 1 * W[1][0] * W[0][1];
}
void QrEq::FillW_1()// Гененрирует обратную матрицу.
{
	double Det = det();
	if (Det == 0)
	{
		cout << "Det = 0 \n";
		return;
	}
	W_1[0][0] = W[1][1] / Det;
	W_1[0][1] = -1 * W[0][1] / Det;
	W_1[1][0] = -1 * W[1][0] / Det;
	W_1[1][1] = W[0][0] / Det;
}
bool QrEq::Stop(double bufX, double bufY)// Признак остановки итерационного процесса.
{
	if (iter >= 20) return true;
	if ((fabs(x - bufX) > e) || (fabs(y - bufY) > e)) return false;
	return true;
}

void QrEq::OutResult()// Выводит результат на консоль и файл.
{
	cout << "x = " << setprecision(6) << x << endl;
	cout << "y = " << setprecision(6) << y << endl;
	cout << "Iter = " << iter << endl << endl;

	ofile << "x = " << setprecision(6) << x << endl;
	ofile << "y = " << setprecision(6) << y << endl;
	ofile << "Iter = " << iter << endl << endl;
}
