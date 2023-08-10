#include <iostream>
#include <typeinfo>

using namespace std;

void func_1() {
    int var =  42;
    int &ref = var;
    ref = 99;
    cout << var << endl;
}

void func_2() {
    int &&i = 42;
    int &&j = 42;
    int &k = i;
    cout << "&i = " << &i << endl;
    cout << "&j = " << &j << endl;
    cout << "&k = " << &k << endl;
}

void func_3() {
    int a = 42;                 // a is a lvalue
    int &b = a;                 // b is a lvalue reference
    int *c = &a;                // c is a pointer to lvalue
    int const &d = a;           // d is a lvalue reference to const
    int const *e = &a;          // e is a pointer to const lvalue
    int * const f = &a;         // f is a const pointer to lvalue
    int const * const g = &a;   // g is a const pointer to const lvalue
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "e = " << e << endl;
    cout << "f = " << f << endl;
    cout << "g = " << g << endl;
}

void func_4() {
    int a = 10;
    int &refA = a;
    int &&refB = 20;
    int &&refC = refA + refB;
    int *refD = &refA;
    cout << "refD = " << refD << endl;
    int * &refE = refD;
    cout << "refE = " << refE << endl;
    refE = &refB;
    cout << "refE = " << refE << endl;
    cout << "refD = " << refD << endl;
    int * &&refF = &refB;
    cout << typeid(&refB).name() << endl;
    cout << "&refB = " << &refB << endl;
    cout << "refF = " << refF << endl;
    refF = &refA;
    cout << "refF = " << refF << endl;
    cout << "&refB = " << &refB << endl;
}

class type_5 {
public:
    int call() { 
        cout << "call()" << endl;
        return 0; 
    }
    int call() const { 
        cout << "call() const" << endl;
        return 0; 
    }

    type_5() {
        cout << "type_5()" << endl;
    }

    // type_5(type_5 &f) {
    //     cout << "type_5(type_5 &f)" << endl;
    // }

    type_5(type_5 const &f) {
        f.call();
        cout << "type_5(type_5 const &f)" << endl;
    }

    type_5(type_5 &&f) {
        f.call();
        cout << "type_5(type_5 &&f)" << endl;
    }

    // type_5(type_5 const &&f) {
    //     // useless
    //     cout << "type_5(type_5 const &&f)" << endl;
    // }
};

void func_6_int(int& x) { std::cout << "lvalue\n"; }
void func_6_int(int&& x) { std::cout << "rvalue\n"; }

template <typename T>
void func_6(T&& arg) {
    func_6_int(std::forward<T>(arg));
}


int main() {
    int x = 42;
    func_6(x);  // 调用bar(int&), 打印 "lvalue"
    func_6(42); // 调用bar(int&&)，打印 "rvalue"
}

