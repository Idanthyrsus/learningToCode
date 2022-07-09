// double-linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

class List
{
    Node* head;
    Node* tail;
    int count;
public:
    List();
    List(const List&);
    ~List();

    int getCount();
    Node* getElement(int);
    void delAll();
    void del(int pos = 0);
    void insert(int pos = 0);
    void addTail(int);
    void addHead(int);
    void print(int);
    void print();

    List& operator = (const List&);
    List operator + (const List&);
    bool operator == (const List&);
    bool operator != (const List&);
    bool operator <= (const List&);
    bool operator >= (const List&);
    bool operator < (const List&);
    bool operator > (const List&);

    List operator - ();
};

int main()
{
    List l;
    const int N = 10;
    int a[N] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            l.addHead(a[i]);
        }
        else
        {
            l.addTail(a[i]);
        }
    }

    cout << "List l: \n";
    l.print();
    cout << endl;
    l.insert();
    cout << "List l: \n";
    l.print();
    cout << endl;
    l.print(2);
    l.print(8);

    List t;

    t = l;
    cout << "List t: \n";
    t.print();

    cout << "List sum:\n";
    List sum;
    sum = -l + t;
    sum.print();
}

List::List()
{
    head = tail = nullptr;
    count = 0;
}

List::List(const List& l)
{
    head = tail = nullptr;

    Node* temp = l.head;
    while (temp != 0)
    {
        addTail(temp->data);
        temp = temp->next;
    }
}

List::~List()
{
    delAll();
}
void List::addHead(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->prev = 0;
    temp->next = head;
    if (head != 0)
    {
        head->prev = temp;
    }

    if (count == 0)
    {
        head = tail = temp;
    }
    else
    {
        head = temp;
    }
    count++;
}

void List::addTail(int n)
{
    Node* temp = new Node;
    temp->next = 0;
    temp->data = n;
    temp->prev = tail;

    if (tail != 0)
    {
        tail->next = temp;
    }

    if (count == 0)
    {
        head = tail = temp;
    }
    else
    {
        tail = temp;
    }

    count++;
}

void List::insert(int pos)
{
    if (pos == 0)
    {
        cout << "Input position: ";
        cin >> pos;
    }

    if (pos < 1 || pos > count + 1)
    {
        cout << "Incorrect position\n";
        return;
    }

    if (pos == count + 1)
    {
        int data;
        cout << "Input new number: ";
        cin >> data;
        addTail(data);
        return;
    }
    else if (pos == 1)
    {
        int data;
        cout << "Input new number: ";
        cin >> data;
        addHead(data);
        return;
    }

    int i = 1;
    Node* ins = head;

    while (i < pos)
    {
        ins = ins->next;
        i++;
    }

    Node* prevIns = ins->prev;
    Node* temp = new Node;

    cout << "Input new number: ";
    cin >> temp->data;

    if (prevIns != 0 && count != 1)
    {
        prevIns->next = temp;
    }

    temp->next = ins;
    temp->prev = prevIns;
    ins->prev = temp;

    count++;
}

void List::del(int pos)
{
    if (pos == 0)
    {
        cout << "Input position: ";
        cin >> pos;
    }

    if (pos < 1 || pos > count)
    {
        cout << "Incorrect position!\n";
        return;
    }

    int i = 1;
    Node* del = head;

    while (i < pos)
    {
        del = del->next;
        i++;
    }

    Node* prevDel = del->prev;
    Node* afterDel = del->next;

    if (prevDel != 0 && count != 1)
    {
        prevDel->next = afterDel;
    }

    if (afterDel != 0 && count != 1)
    {
        afterDel->prev = prevDel;
    }

    if (pos == 1)
        head = afterDel;
    if (pos == count)
        tail = prevDel;

    delete del;
    count--;
}

void List::print(int pos)
{
    if (pos < 1 || pos > count)
    {
        cout << "Incorrect position!\n";
        return;
    }

    Node* temp;

    if (pos <= count / 2)
    {
        temp = head;
        int i = 1;

        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
    }
    else
    {
        temp = tail;
        int i = 1;

        while (i <= count - pos)
        {
            temp = temp->prev;
            i++;
        }
    }
    cout << pos << " element: ";
    cout << temp->data << endl;
}

void List::print()
{
    if (count != 0)
    {
        Node* temp = head;
        cout << "(";
        while (temp->next != 0)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << temp->data << ")\n";
    }
}

void List::delAll()
{
    while (count != 0)
    {
        del(1);
    }
}

int List::getCount()
{
    return count;
}

Node* List::getElement(int pos)
{
    Node* temp = head;

    if (pos < 1 || pos > count)
    {
        cout << "Incorrect position!\n";
        return 0;
    }

    int  i = 1;

    while (i < pos && temp != 0)
    {
        temp = temp->next;
        i++;
    }

    if (temp == 0)
    {
        return 0;
    }
    else
    {
        return temp;
    }
}

List& List::operator = (const List& right)
{
    if (this == &right)
    {
        return *this;
    }

    this->~List();
    Node* temp = right.head;

    while (temp != 0)
    {
        addTail(temp->data);
        temp = temp->next;
    }
    return *this;
}

List List::operator + (const List& right)
{
    List result(*this);
    Node* temp = right.head;
    while (temp != 0)
    {
        result.addTail(temp->data);
        temp = temp->next;
    }
    return result;
}

bool List::operator == (const List& right)
{
    if (count != right.count)
    {
        return false;
    }
    Node* t1, * t2;
    t1 = head;
    t2 = right.head;

    while (t1 != 0)
    {
        if (t1->data != t2->data)
        {
            return false;
        }

        t1 = t1->next;
        t2 = t2->next;
    }
    return true;
}
bool List::operator != (const List& right)
{
    return !(*this == right);
}

bool List::operator >= (const List& right)
{
    if (count > right.count)
    {
        return true;
    }

    if (*this == right)
    {
        return true;
    }

    return false;
}
bool List::operator <= (const List& right)
{
    if (count < right.count)
    {
        return true;
    }

    if (*this == right)
    {
        return true;
    }

    return false;
}
bool List::operator < (const List& right)
{
    if (count < right.count)
    {
        return true;
    }

    return false;
}
bool List::operator > (const List& right)
{
    if (count > right.count)
    {
        return true;
    }
    return false;
}

List List::operator - ()
{
    List result;

    Node* temp = head;

    while (temp != 0)
    {
        result.addHead(temp->data);
        temp = temp->next;
    }
    return result;
}

