#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <cmath>

using namespace std;

void generateHistogram(vector<double> data, int numBins) {

    double minVal = *min_element(data.begin(), data.end()); 
    double maxVal = *max_element(data.begin(), data.end());

        // Создаем вектор для хранения частот
        vector<int> histogram(numBins, 0);
    int totalCount = 0;

    for (double value : data) {
        int binIndex = static_cast<int>((value - minVal) / (maxVal - minVal) * numBins);
        if (binIndex == numBins) {
            binIndex = numBins; // Учтем точки, которые равны maxVal
        }
        if (binIndex >= 0 && binIndex < numBins) {
            histogram[binIndex]++;
        }
    }

    // Вычисляем кол-во частот
    for (int i = 0; i < numBins; i++) {
        totalCount += histogram[i];
    }

    // Выводим гистограмму и кол-во частот
    for (int i = 0; i < numBins; i++) {
        double binStart = static_cast<double>(i) / numBins;
        double binEnd = static_cast<double>(i + 1) / numBins;
        cout << fixed << setprecision(2) << "\n[" << binStart << " - " << binEnd << "): " << histogram[i] << endl;
    }

    cout << "\nTotal number of frequencies: " << totalCount << endl;

    // Ожидаемое количество точек в каждом отрезке для равномерного распределения
    int expectedCount = data.size() / numBins;

    // Вычисляем статистику хи-квадрат
    double chiSquare = 0.0;
    for (int count : histogram) {
        double deviation = count - expectedCount;
        chiSquare += (deviation * deviation) / expectedCount;
    }

    // Число степеней свободы
    int degreesOfFreedom = numBins - 1;

    // Критическое значение для 0.05 уровня значимости и числа степеней свободы 19
    double criticalValue = 30.1;

    if (chiSquare < criticalValue) {
        cout << "Chi-square test passed with significance level 0.5" << endl;
    }
    else {
        cout << "Chi-square test failed with significance level 0.5" << endl;
    }

    cout << "Chi-square value: " << chiSquare << endl;
}

class FibonacciGenerator {

    vector<long long> fib; int currentIndex;

public: FibonacciGenerator() { 
    fib = { 0, 1, 1 }; 
    currentIndex = 0; 
}

          long long next() {
          if (currentIndex >= fib.size()) {
              int n = fib.size();
              fib.push_back(fib[n - 1] + fib[n - 2]);
          }

          long long result = fib[currentIndex];
          currentIndex++;

          return result;
      }
};

int main() {
    FibonacciGenerator generator;

        cout << "First 1000 Fibonacci numbers: " << endl;
    for (int i = 0; i < 1000; i++) {
        cout << setw(20) << right << generator.next() << " ";
        if (i % 5 == 4) {
            cout << endl;
        }
    }
    cout << endl;

    vector<double> fibDouble;

    fibDouble.push_back(0.0); // Добавляем начальное значение вектора fibDouble

    double minVal = 0.0;

    double maxVal = pow(2, 63) - 1; // Максимальное значение для деления на интервалы

    for (int i = 0; i < 1000; i++) {
        double fibValue = static_cast<double>(generator.next()) / maxVal;
        fibDouble.push_back(fibValue);
    }

    generateHistogram(fibDouble, 20);

    return 0;
}
