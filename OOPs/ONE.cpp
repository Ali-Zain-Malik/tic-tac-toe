// Student ID: BC230200024 Name: Muhammad Ali Zain
#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    int employeeID;
    string name;

    Employee(int id, const string &empName) : employeeID(id), name(empName) {}
};

class Node
{
public:
    Employee *employee;
    Node *left;
    Node *right;

    Node(Employee *emp) : employee(emp), left(nullptr), right(nullptr) {}
};

class BST
{
public:
    Node *root;

    BST() : root(nullptr) {}

    void insertEmployee(int id, const string &empName)
    {
        Employee *emp = new Employee(id, empName);
        root = insertEmployeeHelper(root, emp);
        cout << "Employee with ID " << id << " has been added.\n";
    }

    Node *insertEmployeeHelper(Node *curr, Employee *emp)
    {
        if (!curr)
        {
            return new Node(emp);
        }
        if (emp->employeeID < curr->employee->employeeID)
        {
            curr->left = insertEmployeeHelper(curr->left, emp);
        }
        else if (emp->employeeID > curr->employee->employeeID)
        {
            curr->right = insertEmployeeHelper(curr->right, emp);
        }
        return curr;
    }

    void removeEmployee(int id)
    {
        root = removeEmployeeNode(root, id);
        cout << "\nEmployee with ID " << id << " has been removed.\n\n";
    }

    Node *removeEmployeeNode(Node *curr, int id)
    {
        if (!curr)
        {
            return nullptr;
        }
        if (id < curr->employee->employeeID)
        {
            curr->left = removeEmployeeNode(curr->left, id);
        }
        else if (id > curr->employee->employeeID)
        {
            curr->right = removeEmployeeNode(curr->right, id);
        }
        else
        {
            if (!curr->left)
            {
                Node *temp = curr->right;
                delete curr;
                return temp;
            }
            else if (!curr->right)
            {
                Node *temp = curr->left;
                delete curr;
                return temp;
            }
            Node *minRight = findMin(curr->right);
            curr->employee = minRight->employee;
            curr->right = removeEmployeeNode(curr->right, minRight->employee->employeeID);
        }
        return curr;
    }

    Node *findMin(Node *curr)
    {
        while (curr->left)
        {
            curr = curr->left;
        }
        return curr;
    }

    void printBST()
    {
        cout << "Display Employee Records:\n";
        printBSTInOrder(root);
    }

    void printBSTInOrder(Node *curr)
    {
        if (!curr)
        {
            return;
        }
        printBSTInOrder(curr->left);
        cout << "Employee ID: " << curr->employee->employeeID << ", Name: " << curr->employee->name << "\n";
        printBSTInOrder(curr->right);
    }
};

int main()
{
    BST employeeBST;
    cout << "Employee Management System by BC230200024\n\n";
    employeeBST.insertEmployee(1, "Bilal");
    employeeBST.insertEmployee(2, "Kaleem");
    employeeBST.insertEmployee(3, "Akmal");

    cout<<endl;
    employeeBST.printBST();
    employeeBST.removeEmployee(2);
    employeeBST.printBST();

    system("pause"); 
    return 0;
}
