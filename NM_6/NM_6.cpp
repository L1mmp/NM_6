#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}


double F(double x, double y)
{
    return pow(2, x - y) - y - 1;
}
double G(double x, double y)
{
    return pow(y, 3) + pow(x, 2) - 6 * x + 6;
}

///     x0 = 1.4    y0 = 0.8
///
///     2^(x-y)*ln2     -2^(x-y)*ln2 - 1
///     
///     2*x - 6         3y^2-
/// 
///
    

