#include <iostream> 
#include <cmath> 
using namespace std;



double f(int x, int y)
{
    return x ^ 2 + 2 * y;
}

//double trap(double a, double b, int n) { 
//    double h = (b - a) / n; 
//    double result = 0.5 * (f(a) + f(b)); 
//    for (int i = 1; i < n; ++i) { 
//        double x = a + i * h; 
//        result += f(x); 
//    } 
//    return result * h; 
//} 
//double sim(double a, double b, int n) { 
//    double h = (b - a) / n; 
//    double sum = 0; double x; 
//    for (int i = 1; i < n; i+=2) 
//    { 
//        x = a + i * h; 
//       sum += 4 * f(x); 
// 
//    } 
//    for (int i = 2; i < n-1; i+=2) 
//    { 
//        x = a + i * h; 
//        sum += 2 * f(x); 
//    } 
//    return (h / 3) * (f(a) + f(b) + sum); 
//} 

double simson(double a, double b, double c, double d, int n)
{
    double h1 = (b - a) / n;
    double h2 = (d - c) / n;
    double integral = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            double x = a + i * h1;
            double y = c + j * h2;
            double coeff = 1;
            if (i == 0 || i == n)
            {
                coeff *= 1;
            }
            else if (i % 2 == 1)
            {
                coeff *= 4;
            }
            else
            {
                coeff *= 2;
            }
            if (j == 0 || j == n)
            {
                coeff *= 1;
            }
            else if (j % 2 == 1) {
                coeff *= 4;
            }
            else coeff *= 2;
            integral += coeff * f(x, y);
        }
    }
    return(h1 * h2) / 9 * integral;
}
int main() {
    setlocale(LC_ALL, "ru");
    double a = 0;
    double b = 2;
    double c = 2;
    double d = 1;
    int n = 100;


    /*  double result = trap(a, b, n);
      double summ = sim(a, b, n);*/
    double simon = simson(a, b, c, d, n);
    /*cout << "Определенный интеграл (трапеции): " << result << endl;*/
    /*cout << "Определенный интеграл (симсон): " << summ << endl;*/
    cout << "Определенный интеграл (куб симсон): " << (-1) * simon << endl;
    return 0;
}