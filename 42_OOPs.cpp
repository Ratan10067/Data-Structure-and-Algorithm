#include<iostream>
using namespace std;
class Hero{
    int Health;
    char level;
    public:
    Hero(){
        cout <<"Constructor is called"<<endl;
    }
    int getHealth(){
        return Health;
    }
    char getLevel(){
        return level;
    }
    void setHealth(int Health){
        //!!!!! this keyword address store krke rkhta hai apne current class ka !!!!!!!!//
        this->Health=Health;
    }
    void setLevel(char ch){
        level=ch;
    }
};
int main(){
    Hero Ratan; // Hero Ratan likte hi Ratan.Hero() Function call ho jata hai.
    // Making a class from a heap memory
    Hero *b=new Hero;
    // Pointer ko access krne ke liye hmlog -> iska use krenge.
    b->setHealth(87);
    cout<<"Health of b is : "<<b->getHealth()<<endl;

    Hero c;
    c.setHealth(80);
    cout<<"Health of c is : "<<c.getHealth()<<endl;
    // Remember one important thing is that the  Size of Empty class is of 1 byte.
//     cout<<"Size of Ratan is : "<<sizeof(Ratan)<<endl;
//   Ratan.setHealth(70);  
//     cout<<"Health of Ratan is : "<<Ratan.getHealth()<<endl;    
    // cout<<"Level of Ratan is : "<<Ratan.level<<endl;    
    // cout<<"Level of Ratan is : "<<Ratan.Health<<endl;    

return 0;
}