# include "meanError.h"
#include <math.h>

double hmean(double a, double b) {
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}
double gmean(double a, double b) {
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    double a, b;
    cout << "Enter two numbers (q to quit): ";
    while (cin >> a >> b) {
        try {
            cout << "Harmonic mean: " << hmean(a, b) << endl;
            cout << "Geometric mean: " << gmean(a, b) << endl;
        } catch(meanError & e){
            if(typeid(e) == typeid(bad_hmean)) {
                bad_hmean * ph = dynamic_cast<bad_hmean*>(&e);
                ph->mseg();
            } else if(typeid(e) == typeid(bad_gmean)) {
                bad_gmean * gh = dynamic_cast<bad_gmean*>(&e);
                gh->mseg();
            }
        }
        cout << "Enter next set of numbers (q to quit): ";
    }
    return 0;
}