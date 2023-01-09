#include<bits/stdc++.h>
using namespace std;

// interface observable
class Observer{
    public:
     virtual void update()=0;
};
class ProductObservable{
    public:
     virtual void addObserver(Observer *obs)=0;
     virtual void removeObserver(Observer *obs)=0;
     virtual void notify()=0;
     virtual void setData(int items)=0;
     virtual int getData()=0;

};


// concrete class implementation
class StockObservable : public ProductObservable{
    set<Observer*> st;
    int items=0;
    public:
    void addObserver(Observer *obs){
        st.insert(obs);
    }
    void removeObserver(Observer *obs){
        st.erase(st.find(obs));
    }
    void notify(){
        //cout<<"notify called "<<st.size()<<endl;
        for(auto obs: st){
            obs->update();
        }
    }
    void setData(int items){
        int prev= this->items;
        this->items= items;
        if(prev==0){
            notify();
        }
        
    }
    int getData(){
        return items;
    }
    
};


class EmailObserver : public Observer{
    ProductObservable *obs;
    public:
    EmailObserver(ProductObservable *obs){
        this->obs= obs;
    }
    void update(){
        cout<<"Emailed updated amount"<<endl;
    } 
};
class SmsObserver : public Observer{
    ProductObservable *obs;
    public:
    SmsObserver(ProductObservable *obs){
        this->obs= obs;
    }
    void update(){
        cout<<"Messaged updated amount"<<endl;
    } 
};

int main(){
    ProductObservable* obs= new StockObservable();
    Observer* observer1= new EmailObserver(obs);
    Observer* observer2= new SmsObserver(obs);
    obs->addObserver(observer1);
    obs->addObserver(observer2);
    obs->setData(10);
    obs->setData(100);
    obs->setData(0);
    obs->setData(5);
    

    return 0;
}