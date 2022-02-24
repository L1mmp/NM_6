#pragma once
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

class QrEq
{
private:
	ofstream ofile;
	double e;
	double x;
	double y;
	double W[2][2];
	double W_1[2][2];
	int iter;

	void FillW();
	double F(double x, double y);
	double G(double x, double y);
	double F_X(double x, double y);
	double F_Y(double x, double y);
	double G_X(double x, double y);
	double G_Y(double x, double y);
	double det();
	void FillW_1();
	bool Stop(double bufX, double bufY);
	void StartIter();

public:
	void SetXY(double x0, double y0);
	QrEq(double x0, double y0, double E);
	~QrEq();
	void OutResult();
};

