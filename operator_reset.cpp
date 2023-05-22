#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    Complex operator=(const char* str){
        int n=0;
        char a[100]={};
        while(*str!='+'){
            a[n]=*str;
            n++;
            str++;
        }
        str++;
        a[n]='\n';
        r=atoi(a);
        i=atoi(str);
        return *this;//?
   } 
// 在此处补充你的代码
    // explicit Complex(const string str){
    //     r=(double)(str[0]-'0');
    //     i=(double)(str[2]-'0');
    // }
    // Complex(){}
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}