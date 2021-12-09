#include <locale.h>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include <cstring>
#include <cstdlib>

using namespace std;
class Spisok
{
public:

    struct Person
    {
        string lastName;
        string Name;
        string Otch;
        string Status;
        Person* sled;
    };

    Person* phead; //Указатель на заглавное звено списка.
    // Person* Res; //Указатель на найденное звено списка.

    Spisok() {
        phead = nullptr;
    }

    ~Spisok() {
        if (!isEmpty()) {
            OCHISTKA();
        }
    }

    void POSTROENIE();
    void VYVOD();

    //Поиск звена с элементом el в списке. В случае успешного поиска функция возвращает адрес 
    //найденного звена списка, содержащего элемент с фамилией el,
    //в случае неуспеха возвращает NULL.
    Person* POISK(string el)
    {
        Person* t;

        Person* Res = nullptr;
        t = phead;
        while (t != nullptr) {
            if ((*t).lastName == el) {
                Res = t;
                break;
            } else {
                t = (*t).sled;
            }
        }
        return Res;
    }

    // возвращает true если список пустой (не содержит элементов)
    bool isEmpty();
    void VSTAV_POSLE(Spisok::Person *p_el, string el, string Name1, string Otch1, string Status1);
    void VSTAV_DO(Spisok::Person *p_el, string el, string Name1, string Otch1, string Status1);
    void OCHISTKA();
    // void OCHISTKA2();
    void DELETE_EL(Person* p_el);
};

void main()
{
    int otv = 0;
    string  el, el1;
    string Name1, Otch1, Status1, Name11, Otch11, Status11;
    Spisok::Person *Finded=nullptr;
    // создание нового списка
    Spisok A;

    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ввод элементов списка
    A.POSTROENIE();

    // вывод начального варианта списка
    A.VYVOD();

    do
    {
        cout << "1. Добавление ПОСЛЕ\n" << "2. Добавление ДО\n";
        cout << "3. Вывод\n" << "4. ОЧИСТКА ВСЕГО СПИСКА\n" ;
        cout << "5. Удаление элемента списка\n" << "0.Выход\n";
        cin >> otv;
        switch (otv)
        {
        case 1:
            cout << "ПОСЛЕ кого осуществляется добавление?:\n";

            // поиск в списке буднт осуществляться по фамилии
            cout << "Фамилия";
            cout << ": ";
            cin >> el;

            // cout << "Имя";
            // cout << ": ";
            // cin >> Name1;

            // cout << "Отчество";
            // cout << ": ";
            // cin >> Otch1;

            // cout << "Статус";
            // cout << ": ";
            // cin >> Status1;

            // находим элемент списка с фамилией el
            Finded = A.POISK(el);
            if ( Finded != nullptr)
            {
                // если элемент найден

                cout << "НОВЫЙ человек в списке : \n";

                cout << "Фамилия";
                cout << ": ";
                cin >> el1;

                cout << "Имя";
                cout << ": ";
                cin >> Name11;

                cout << "Отчество";
                cout << ": ";
                cin >> Otch11;

                cout << "Статус";
                cout << ": ";
                cin >> Status11;

                // вставляем новый элемент после найденного
                A.VSTAV_POSLE(Finded, el1, Name11, Otch11, Status11);
                // вывод списка
                A.VYVOD();

            } else {
                // элемент с фамилией el не найден
                cout << "Человека с заданным фио в списке нет!";
            } 


            break;

        case 2:
            cout << "ПЕРЕД кем осуществляется вставка?:\n";

            cout << "Фамилия";
            cout << ": ";
            cin >> el;

            // cout << "\nИмя";
            // cout << ":\n";
            // cin >> Name1;

            // cout << "\nОтчество";
            // cout << ":\n";
            // cin >> Otch1;

            // cout << "\nСтатус";
            // cout << ":\n";
            // cin >> Status1;

            // находим элемент списка с фамилией el
            Finded = A.POISK(el);
            if ( Finded != nullptr)
            {
                // если элемент найден

                cout << "НОВЫЙ человек в списке:\n";

                cout << "Фамилию";
                cout << ": ";
                cin >> el1;

                cout << "Имя";
                cout << ": ";
                cin >> Name11;

                cout << "Отчество";
                cout << ": ";
                cin >> Otch11;

                cout << "Статус";
                cout << ": ";
                cin >> Status11;

                // вставляем новый элемент до найденного
                A.VSTAV_DO(Finded, el1, Name11, Otch11, Status11);
                // вывод списка
                A.VYVOD();

            } else {
                // элемент с фамилией el не найден
                cout << "Человека с заданным фио в списке нет!";
            } 
            break;

        case 3:
            if (A.isEmpty())
                cout << "Список пуст" << endl;
            else
                A.VYVOD();
            break;

        case 4:
            A.OCHISTKA();
            break;

        case 5:
            cout << "кого удалить?\n";

            // поиск в списке буднт осуществляться по фамилии
            cout << "Фамилия";
            cout << ": ";
            cin >> el;

            // находим элемент списка с фамилией el
            Finded = A.POISK(el);
            if ( Finded != nullptr)
            {
                // удаляем найденный элемент
                A.DELETE_EL(Finded);
                // вывод списка
                A.VYVOD();

            } else {
                // элемент с фамилией el не найден
                cout << "Человека с заданным ФИО в списке нет!";
            } 
            break;

        }

    } while (otv != 0);
}

bool Spisok::isEmpty()
{
    if (phead == nullptr) {
        return true;
    }
    return false;
}

void Spisok::POSTROENIE()
    // Построение однонаправленного списка.
    // phead - указатель на заглавное звено списка           
{
    string   el, Name1, Otch1, Status1;
    cout << "ЗАПОЛНИТЕ список: ";
    cout << endl;
    while(true) {
        cout << "Вводите фамилию: ";
        cin >> el;
        cout << "Вводите имя: ";
        cin >> Name1;
        cout << "Вводите отчество: ";
        cin >> Otch1;
        cout << "Вводите статус: ";
        cin >> Status1;
        if (el == "0") {
            break;
        }
        VSTAV_POSLE(nullptr, el, Name1, Otch1, Status1);  
    }
}

// Вывод содержимого однонаправленного списка с 
// заглавным звеном.  phead - указатель на заглавное звено списка.
void Spisok::VYVOD()
{
    Person* t;
    cout << "Список: ";
    // t = (*phead).sled;
    t = phead;
    while (t != nullptr)
    {
        cout << "(" << (*t).lastName << " ; " << (*t).Name << " ; " << (*t).Otch << " ; " << (*t).Status << ")" << endl;
        t = (*t).sled;
    }
    cout << endl;
}

// Включение нового звена в список после звена, на которое указывает p_el
// Если p_el==nullptr, то звено вставляется в конец списка
void Spisok::VSTAV_POSLE(Person *p_el, string el, string Name1, string Otch1, string Status1)
{
    if (p_el == nullptr) {
        if (phead != nullptr) {
            p_el = phead;
            while (p_el->sled != nullptr) {
                p_el = p_el->sled;
            }
        }
    }
    // создание и вставка нового элемента
    Person  *q = new(Person);
    (*q).lastName = el;
    (*q).Name = Name1;
    (*q).Otch = Otch1;
    (*q).Status = Status1;
    if (p_el != nullptr) {
        Person *temp = (*p_el).sled;
        (*p_el).sled = q;
        (*q).sled = temp;    
    } else {
        phead = q;
        (*q).sled = nullptr;
    }
}

// Удаление элемента списка p_el
void Spisok::DELETE_EL(Person* p_el)
{
    if ((phead != nullptr) && (p_el != nullptr)) {
        // находим предыдущий элемент до элемента p_el в списке
        if (phead == p_el) {
            // нужно удалить первый элемент списка
            Person *temp = phead->sled;
            delete phead;
            phead = temp;
        } else {
            // проходим элементы списка, находим элемент до элемента p_el
            Person* p = phead;
            Person* p_pred = nullptr;
            while ((*p).sled != nullptr) {
                if (p_el == (*p).sled) {
                    p_pred = p;
                    break;
                }
                p = (*p).sled;
            }
            if (p_pred == nullptr) {
                // если элемент p_el не найден в списке
                cout << "Ошибка, p_el не найден в списке для удаления\n";
                return;
            }
            // p_pred - элемент предыдущий элементу p_el в списке
            p_pred->sled=p_el->sled;
            delete p_el;
        }
    }
}

// Включение звена в список перед звеном, на которое указывает p_el.
void Spisok::VSTAV_DO(Person *p_el, string el, string Name1, string Otch1, string Status1)
{
    // проверка, что указатель на элемент списка не nullptr
    if ((phead != nullptr) && (p_el != nullptr)) {
        Person* q = new (Person);
        (*q).lastName = el;
        (*q).Name = Name1;
        (*q).Otch = Otch1;
        (*q).Status = Status1;

        // находим предыдущий элемент до элемента p_el в списке
        if (phead == p_el) {
            // нужно вставить до первого элемента в списке
            (*q).sled = phead;
            phead = q;
        } else {
            // проходим элементы списка, находим элемент до элемента p_el
            Person* p = phead;
            Person* p_pred = nullptr;
            while ((*p).sled != nullptr) {
                if (p_el == (*p).sled) {
                    p_pred = p;
                    break;
                }
                p = (*p).sled;
            }
            if (p_pred == nullptr) {
                // если элемент p_el не найден в списке
                cout << "Ошибка, p_el не найден в списке\n";
                return;
            }
            // вставляем новый элемент между элементами p_pred и p_el
            Person *temp = (*p_pred).sled;
            (*p_pred).sled = q;
            (*q).sled = temp;    
        }
    }
}

// Удаление однонаправленного списка из памяти.
// phead - указатель на заглавное звено списка.
void Spisok::OCHISTKA()
{
    // проходим весь список, удаляем элементы списка
    Person* p = phead;
    while (p != nullptr)
    {
        Person* temp = (*p).sled;
        delete p;
        p = temp;
    }
    // в списке нет элементов 
    phead = nullptr;
}

// void Spisok::OCHISTKA2()
// {
//     Person* q = new Person;
//     while (phead != nullptr)
//     {
//         q = q->sled = phead;
//     }

// }

