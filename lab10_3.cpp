#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>


using namespace std;



int main(){
    const int MAX=100;
    double numbers[MAX];
    double sum = 0;
    int count = 0;

    ifstream source;
    source.open("score.txt");
    double number;
    while (source >> number)
    {
        numbers[count] = number;
        sum += numbers[count];
        count++;
    }
    source.close();

    double mean = sum / count;
    double sumSquaredDiff = 0;

    for (int i = 0; i < count; i++) {
        sumSquaredDiff += pow(numbers[i] - mean, 2);
    }

    double standardDeviation = sqrt(sumSquaredDiff / count);


    cout << "Number of data = " << count << endl;
    cout << setprecision(3) ;
    cout << "Mean = " << mean << endl;
    cout << "Standard deviation = " << standardDeviation ;

    return 0;
}