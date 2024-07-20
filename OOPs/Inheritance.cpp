// // =========== Simple Inheritance =========== //
// #include<iostream>
// using namespace std;

// class Father
// {
// // Using protected here because if I will use private, I will not be able to access these parameters in other derived classes in the form of inheritance. 
// protected: 
//     string name, surname;

// public:
//     Father()
//     {
//         this->name = "Shafiq Muzaffar";
//         this->surname = "Malik";
//     }
// };


// class Son1:Father
// {
// private:
//     string name;
// public:
//     Son1()
//     {
//         this->name = "Ali Zain";
//     }

//     void display()
//     {
//         cout<<"Son 1:\n";
//         cout<<name<<" "<<surname<<endl;
//     }

// };


// class Son2:Father
// {
// private:
//     string name;
// public:
//     Son2()
//     {
//         this->name = "Ali Hamd";
//     }

//     void display()
//     {
//         cout<<"Son 2:\n";
//         cout<<name<<" "<<surname<<endl;
//     }
// };


// int main()
// {
//     Son1 s1; 
//     Son2 s2;

//     s1.display();
//     s2.display();

// return 0; 
// }




// =========== Multiple Inheritance ============ //

#include<iostream>
using namespace std;

class Fish
{
public:
    void swim()
    {
        cout<<"Hey I can swim in water\n";
    }
};


class Woman
{
public:
    void walk()
    {
        cout<<"Hey I can walk on land\n";
    }
};



class Mermaid: Fish, Woman
{
public:
    void intro()
    {
        cout<<"Hey I am a mermaid\n";
        Fish::swim();
        Woman::walk();
    }
};


int main()
{
    Mermaid mermaid;

    mermaid.intro();
    // mermaid.swim();
    // mermaid.walk();
}