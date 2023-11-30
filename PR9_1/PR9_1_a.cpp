#include <iostream>
#include <iomanip>
#include <string>
//#include <Windows.h>
using namespace std;

enum Spec { KN, IT, ME, PI, TN };

//string specStr[] = { "Комп’ютернi науки", "Iнформатика", "Математика та економiка", "Фiзика та iнформатика", "Трудове навчання" };
string specStr[] = { "КН", "ІТ", "МЕ", "ФІ", "ТН" };

struct Student
{
    string prizv;
    Spec spec;
    int kurs;
    double physicm;
    double mathm;
    double itm;

};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double Average(Student st, const int N);
double SearchProc(Student* p, const int N);
void Exelent(Student* p, const int N);


int main()
{
    // SetConsoleCP(1251); 
    // SetConsoleOutputCP(1251);
    int N;
    cout << "Введіть N: "; cin >> N;
    cout << endl;
    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);
    Exelent(p, N);

    double percent = SearchProc(p, N);
    cout << "Процент студентів, у яких середній бал більший за 4,5 = " << percent << "%" << endl;



    delete[] p;
    return 0;
}

void Create(Student* p, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Cтудент No " << i + 1 << ":" << endl; cin.get();
        cout << "прізвище: "; getline(cin, p[i].prizv);
        cout << "курс: "; cin >> p[i].kurs;
        cout << "спеціальність (0 - Комп’ютерні науки (КН), 1 - Iнформатика (IT), 2 - Математика та економiка (МЕ), 3 - Фiзика та iнформатика (ФI), 4 - Трудове навчання (ТН) ): "; cin >> spec;
        p[i].spec = (Spec)spec;
        cout << "оцінка з фізики: "; cin >> p[i].physicm;
        cout << "оцінка з математики: "; cin >> p[i].mathm;
        cout << "оцінка з інформатики: "; cin >> p[i].itm;
        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    cout << "| №     Прізвище     Курс    Спеціальність     Фізика    Математика   Інформатика|" << endl;
    cout << ".................................................................................." << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(2) << right << i + 1 << " "
            << setw(8) << right << p[i].prizv << "         "
            << setw(3) << right << p[i].kurs << "  "
            << setw(12) << right << specStr[p[i].spec] << "       "
            << setw(8) << right << p[i].physicm << " "
            << setw(10) << right << p[i].mathm << "    "
            << setw(10) << right << p[i].itm << " "
            << "    |" << endl;
    }
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    cout << endl;
}


double Average(Student st, const int N)
{
    return (st.physicm + st.mathm + st.itm) / 3.0;
}

double SearchProc(Student* p, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        double res = Average(p[i], N);
        if (res > 4.5)
            k++;
    }

    return (double)k / N * 100;
}

void Exelent(Student* p, const int N)
{
    cout << "Прізвища студентів, які вчаться на відмінно: ";
    for (int i = 0; i < N; i++)
    {
        if (Average(p[i], N) == 5)
            cout << p[i].prizv << " ";
    }
    cout << endl;
}
