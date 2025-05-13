#include <iostream>
#include <string>
using namespace std;


class Animal
{
protected:
    string classification; 
    int limbs;             
    int descendants;      

public:
    
    Animal() : classification(""), limbs(0), descendants(0) {}
    Animal(string c, int l, int d) : classification(c), limbs(l), descendants(d) {}

    
    ~Animal() {}

    
    void input() //метод
    {
        cout << "Animal classification: ";
        getline(cin, classification);
        cout << "Number of limbs: ";
        cin >> limbs;
        cout << "Number of descendants: ";
        cin >> descendants;
        cin.ignore(); // Очищення буфера після вводу
    }

    
    void print()
    {
        cout << "Classification: " << classification << "\nLimbs: " << limbs << "\nDescendants: " << descendants << endl;
    }

    // Метод для зміни кількості кінцівок
    void setlimbs(int newlimbs)
    {
        limbs = newlimbs;
    }
};


class Domesticated : public Animal
{
private:
    string alias; // Прізвисько тварини

public:
    // Конструктори
    Domesticated() : Animal(), alias("") {}
    Domesticated(string c, int l, int d, string a) : Animal(c, l, d), alias(a) {}

    
    ~Domesticated() {}

    
    void input()
    {
        Animal::input(); 
        cout << "Animal alias: ";
        getline(cin, alias);
    }

    // Перевизначення методу виводу (додає вивід прізвиська)
    void print()
    {
        Animal::print(); // Виклик методу базового класу
        cout << "Alias: " << alias << endl;
    }

    // Метод для зміни прізвиська
    void setalias(string newalias)
    {
        alias = newalias;
    }
};

int main()
{
    Domesticated Domesticated; // Створення об'єкта класу Domesticated

    cout << "Input data:\n";
    Domesticated.input(); 

    cout << "Output data:\n";
    Domesticated.print(); 

    cout << "Limbs and alias change\n";
    int newlimbs;
    string newalias;

    
    cout << "New limbs: ";
    cin >> newlimbs;
    Domesticated.setlimbs(newlimbs);
    cin.ignore(); // Очищення буфера

    cout << "New alias: ";
    getline(cin, newalias);
    Domesticated.setalias(newalias);

    cout << "New output:\n";
    Domesticated.print(); // Виведення оновлених даних

    return 0;
}
