#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    const int N = 8;
    int matrix[N][N];


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 101 - 50;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) { 
            if (matrix[i][j] > 0 && matrix[i][j] % 2 == 0) {
                count++;
            }
        }
    }

    cout << "Количество положительных чётных : " << count << "\n";

    int maxAr[4];
    int index = 0;

    for (int i = 1; i < N; i += 2) { 
        int maxNum = matrix[i][0]; 
        for (int j = 1; j < N; j++) {
            if (matrix[i][j] > maxNum) {
                maxNum = matrix[i][j];
            }
        }
        maxAr[index] = maxNum;
        index++;
    }


    cout << "\nМаксимумы ч строк:" << "\n";
    for (int i = 0; i < 4; i++) {
        cout << maxAr[i] << " ";
    }
    cout << endl;

    return 0;
}
