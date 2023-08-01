#include<iostream>
#include<string.h>
//41 mins
using namespace std;

class Hero {
    //properties
    

    private:
    int level;


    public:
    int health;   //we can use public functions out of class also in main function
    char *name;
    static int TimetoComplete;    //static data member

    Hero(Hero& temp){               //copy constructor 
        this->level=temp.level;
        this->health=temp.health;
    }

    Hero(){                     //default constructor
        cout<<"Simple constructor"<<endl;
        name=new char[100];
    }

    Hero(int level,int health){
        // cout<<"this->"<<this<<endl;
        this->level=level;
        this->health=health;
    }
    

    void print(){
        cout<<level<<endl;
        cout<<health<<endl;     //we can use private properties in the class itself not out side the class
        cout<<name<<endl;
    }
    int getlevel(){
        return level;   //thats how we can get private elements also
    }

    void setlevel(int n){
        level=n;
    }
    void sethealth(int n){
        this->health=n;
    }
    void setname(char name[]){
        strcpy(this->name,name);
    }

    static int random(){
        return TimetoComplete;    //static function
    }

    ~Hero(){
        cout<<"I am distructor !";
    }
};

int Hero::TimetoComplete =10;

int main() {

    //static keyword
    // cout<<Hero::TimetoComplete<<endl;

    //static function call

    cout<<Hero::random()<<endl;




    // cout<<"Hi"<<endl;
    //object created statically
    // Hero a;
    // cout<<"Hello"<<endl;


    // Hero ramesh(2);
    // cout<<"Address of hero is "<<&ramesh<<endl;
    // ramesh.getlevel();


    // Hero A(2,80);
    // A.print();

    // Hero B(A);
    // B.print();


    // Hero hero1;
    // hero1.setlevel(5);
    // hero1.sethealth(75);
    // char name[10]="Ankan";
    // hero1.setname(name);

    // hero1.print();
    
    //static
    // Hero a;

    //dynamic
    // Hero *b=new Hero();

    //manually destructor call
    // delete b;

    //static allocation
    // Hero a;
    // a.setlevel(15);
    // cout<<"Level is : "<<a.getlevel()<<endl;

    //dynamic allocation
    // Hero *b=new Hero;
    // (*b).setlevel(15150);
    // cout<<"In b level is : "<<(*b).getlevel()<<endl;



    // Hero h1;
    // h1.health=10;
    // cout<<"Health is : "<<h1.health<<endl;

    // //getting private elements of class
    // h1.setlevel(5);
    // cout<<"Level is "<<h1.getlevel()<<endl;


    // // cout<<"Level is : "<<h1.level<<endl;


    // // cout<<"size : "<<sizeof(h1)<<endl;
    return 0;
}