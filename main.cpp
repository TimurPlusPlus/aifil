#include <iostream>
#include <cmath>

using namespace std;

void vectorCut(int N, int M) //2! OK!
{
    double avgPart = (double) N / M;                               //Средний размер каждой части вектора.
    double shift = 0;                                             //Величина отступа от начала вектора.
    double avgPartCurrent = avgPart;                             //Фактический размер каждого отрезка.
    if((int)avgPart - avgPart != 0)                             //Если средняя длина отрезка - десятичное число.
    {
        int decimalSign = 1;                                  //Позиция десятичного знака. После запятой.
        avgPartCurrent = avgPart * 10;                       //Для проверки 1 десятичного знака.
        while((int)avgPartCurrent % 10 == 0)                //Находим позицию не нулевого десятичного знака.
        {
            avgPartCurrent *= 10;
            decimalSign++;
        }

        avgPartCurrent = (int)(avgPart * pow(10, decimalSign)) / (double)pow(10, decimalSign); //Средний размер части вектора
                                                                                              //с учётом отступов.
        shift = (N - avgPartCurrent * M) / 2;                                                //Величина отступа.

    }

    for(int i = 0; i < M - 1; i++)                                                     //Вывод координат отрезков.
    {
      cout << "[" << i * avgPartCurrent + shift << "; "
           << i * avgPartCurrent + shift + avgPartCurrent << ")"
           << endl;
    }
    M--;
    cout << "[" << M * avgPartCurrent + shift << "; "               //Отдельно выводим координаты последнего отрезка,
         << M * avgPartCurrent + shift + avgPartCurrent << "]"     //чтобы закрыть квадратной скобкой.
         << endl;

}


int main()
{
    vectorCut(10, 7);
    return 0;
}
