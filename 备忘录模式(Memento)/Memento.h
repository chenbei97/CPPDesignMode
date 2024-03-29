/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-09-18 16:23:18
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-10-20 17:22:50
 * @FilePath: \CPPDesignMode\备忘录模式(Memento)\Memento.h
 * @Copyright (c) 2023 by ${chenbei}, All Rights Reserved.  
 */

#ifndef Memento_H
#define Memento_H
#include <string>
using std::string;

class Fighter;
class Memento
{
public:
    void setAge(int age){mage = age;};
    void setName(string name){mname = name;};
    void display(){
        printf("age = %d,name = %s\n",mage,mname.c_str());
    }
private:
    friend class Fighter;
    Memento(int age,string name):mage(age),mname(name){}
    int mage;
    string mname;
};

class Fighter{
    public:
        Fighter(int age,string name):mage(age),mname(name){}
        void setAge(int age){mage = age;};
        void setName(string name){mname = name;};
        void display(){
            printf("age = %d,name = %s\n",mage,mname.c_str());
        }
        Memento* createMemento() {
            return new Memento(mage,mname);
        }
        void restoreMemento(Memento* m) {
            mage = m->mage;
            mname = m->mname;
        }
    private:
        int mage;
        string mname;
};

/*
 备忘录构造函数private，要定义为使用者的友元类可供访问
 使用者可以创建备忘录和传递备忘录进行恢复
*/


#endif