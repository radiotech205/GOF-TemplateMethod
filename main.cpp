#include <iostream>

using namespace std;

class Edication
{
protected:
    virtual void Enter() = 0; //Чисто ВФ. Обязательно переопределяяется.
    virtual void Study() = 0;
    virtual void PassExams() {cout << "Pass Exams" << endl;} // реализация по умолчинию.
    virtual void DiplomaExam() {} // Хук. Метод без тела, м.б. или не м.б. переопределён.
    virtual void GetDocument() = 0;
public:
    void Learn()
    {
        Enter();
        Study();
        PassExams();
        DiplomaExam();
        GetDocument();
    }
    virtual ~Edication() {}
};

class School: public Edication
{
public:
    void Enter()    {cout  << "Go to 1 class" << endl;}
    void Study()    {cout << "Lessons and homework" << endl;}
    void GetDocument(){cout << "Certificate of secondary edication" << endl;}
};

class Univercity: public Edication
{
public:
    void Enter()    {cout  << "Go to 1 course" << endl;}
    void Study()    {cout << "Lections and practices" << endl;}
    void GetDocument(){cout << "Certificate of higher edication" << endl;}
    void DiplomaExam() {cout  << "Diploma examination" << endl;}
};

int main()
{
    Edication* school = new School();
    school->Learn();
    cout << endl;

    Edication* univercity = new Univercity();
    univercity->Learn();


    delete school;
    delete univercity;
    cout << "Hello World!" << endl;
    return 0;
}
