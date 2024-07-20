// #include<iostream>
// using namespace std;

// class Student
// {
// private:
//     string name, phone, address, program, course;
//     float cgpa;
// public:
//     Student(string name, string phone, string address, string program, string course, float cgpa)
//     {
//         this->name = name;
//         this->phone = phone;
//         this->address = address;
//         this->program = program;
//         this->course = course;
//         this->cgpa = cgpa;
//     }

//     Student(){};

//     void setData();
//     void getData();
// };


//  void Student::setData()
// {
//     cout<<"Enter your name: ";
//     cin>>name;
//     cout<<"\nEnter your phone number: ";
//     cin>>phone;
//     cout<<"\nEnter your address: ";
//     cin>>address;
//     cout<<"\nEnter your program: ";
//     cin>>program;
//     cout<<"\nEnter your course: ";
//     cin>>course;
//     cout<<"\nEnter your CGPA: ";
//     cin>>cgpa;
// }


// void Student::getData()
// {
//     cout<<"\nStudent Name: "<<name;
//     cout<<"\nPhone Number: "<<phone;
//     cout<<"\nAddress: "<<address;
//     cout<<"\nProgram: "<<program;
//     cout<<"\nCourse: "<<course;
//     cout<<"\nCGPA: "<<cgpa;
// }


// int main()
// {
//     Student student;

//     string name, phone, address, program, course;
//     float cgpa;

//     student.setData();

//     cout<<"\n================\n";
    
//     student.getData();

// return 0;
// }



#include<iostream>
using namespace std;

void func(int i)
{  
    static int x = i; // Assignment will be done only once and result will remain the same. 
    cout<<"x = "<<x<<endl;

    static int y; // Here assignment will be done each time function is executed and will print diff. result.
    y = i;
    cout<<"y = "<<y<<endl;
}

int main()
{
    func(10);
    func(20);
return 0;
}