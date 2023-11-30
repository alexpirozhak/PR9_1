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
    union
    {
        double programs;
        double nummeths;
        double pedagogs;
    };


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
        switch (p[i].spec)
        {
        case KN:
            cout << "оцінка з програмування: "; cin >> p[i].programs;
            break;

        case IT:
            cout << "оцінка з чисельних методів: "; cin >> p[i].nummeths;
            break;

        case ME:
        case PI:
        case TN:
            cout << "оцінка з педагогіки: "; cin >> p[i].pedagogs;
            break;
        }

        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    cout << "| №     Прізвище     Курс    Спеціальність     Фізика    Математика   Програмування   Чисельні методи   Педагогіка |" << endl;
    cout << "...................................................................................................................." << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(2) << right << i + 1 << " "
            << setw(14) << right << p[i].prizv << "   "
            << setw(3) << right << p[i].kurs << "  "
            << setw(12) << right << specStr[p[i].spec] << "       "
            << setw(8) << right << p[i].physicm << " "
            << setw(10) << right << p[i].mathm << "    ";

        switch (p[i].spec)
        {
        case KN:
            cout << setw(12) << right << p[i].programs << setw(38) << "|";
            break;

        case IT:
            cout << setw(27) << right << p[i].nummeths << setw(23) << "|";
            break;

        case ME:
        case PI:
        case TN:
            cout << setw(43) << right << p[i].pedagogs << setw(7) << "|";
            break;

        default:
            break;
        }
        cout << endl;
    }
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    cout << endl;
}


double Average(Student st, const int N)
{
    switch (st.spec)
    {
    case KN:
        return (st.physicm + st.mathm + st.programs) / 3.0;
        break;

    case IT:
        return (st.physicm + st.mathm + st.nummeths) / 3.0;
        break;

    case ME:
    case PI:
    case TN:
        return (st.physicm + st.mathm + st.pedagogs) / 3.0;
        break;
    }
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
