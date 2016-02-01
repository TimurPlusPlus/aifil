#include <iostream>
#include <cmath>

using namespace std;

void vectorCut(int N, int M) //2! OK!
{
    double avgPart = (double) N / M;                               //������� ������ ������ ����� �������.
    double shift = 0;                                             //�������� ������� �� ������ �������.
    double avgPartCurrent = avgPart;                             //����������� ������ ������� �������.
    if((int)avgPart - avgPart != 0)                             //���� ������� ����� ������� - ���������� �����.
    {
        int decimalSign = 1;                                  //������� ����������� �����. ����� �������.
        avgPartCurrent = avgPart * 10;                       //��� �������� 1 ����������� �����.
        while((int)avgPartCurrent % 10 == 0)                //������� ������� �� �������� ����������� �����.
        {
            avgPartCurrent *= 10;
            decimalSign++;
        }

        avgPartCurrent = (int)(avgPart * pow(10, decimalSign)) / (double)pow(10, decimalSign); //������� ������ ����� �������
                                                                                              //� ������ ��������.
        shift = (N - avgPartCurrent * M) / 2;                                                //�������� �������.

    }

    for(int i = 0; i < M - 1; i++)                                                     //����� ��������� ��������.
    {
      cout << "[" << i * avgPartCurrent + shift << "; "
           << i * avgPartCurrent + shift + avgPartCurrent << ")"
           << endl;
    }
    M--;
    cout << "[" << M * avgPartCurrent + shift << "; "               //�������� ������� ���������� ���������� �������,
         << M * avgPartCurrent + shift + avgPartCurrent << "]"     //����� ������� ���������� �������.
         << endl;

}


int main()
{
    vectorCut(10, 7);
    return 0;
}
