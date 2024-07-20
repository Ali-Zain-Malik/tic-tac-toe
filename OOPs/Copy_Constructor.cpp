##include<iostream>
using namespace std;


class A
{
private:
    int x, y;
public:
    A(int x, int y)
    {
        this->x =  x;
        this->y = y;
    }


    // Creating a copy constructor. Same class and a reference is passed in parameters.
    A(A &ref)
    {
        x = ref.x; // x of this constructor is initialized to the x of other consturctor using its reference
        y = ref.y; // y of this constructor is initialized to the y of other consturctor using its reference
    }

    void show()
    {
        cout<<"x: "<<x<<endl;
        cout<<"y: "<<y<<endl;
    }
};

int main()
{
    A obj1(10, 20); // Creating first object of class A.
    A obj2 = obj1; // Initializing the object 2 to the object 1 and values will be passed using copy constructor.

    obj1.show();
    obj2.show();
return 0;
}
