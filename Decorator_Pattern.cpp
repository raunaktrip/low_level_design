
// DECORATOR PATTERN 
// PIZZA BILLING SYSTEM LLD
#include <bits/stdc++.h>
using namespace std;

// interface for base pizza
class BasePizza{
  public:
  virtual int getCost()=0;
};

// concrete class 1 
class FarmhousePizza : public BasePizza{
  public:
  int getCost(){
    return 150;
  } 
};

// concrete class 2
class MarghretaPizza : public BasePizza{
  public:
  int getCost(){
    return 120;
  }
};

// interface of Decorator
// it has a "is a"relationship with BasePizza and also "has a " relationship
class Toppings : public BasePizza{
  public: 
  virtual int getCost()=0;
};

// concrete classes of Decorator class
class ExtraCheese : public Toppings{
  BasePizza* pizza;
  public:
  ExtraCheese(BasePizza* pizza){
    this->pizza= pizza;
  }
  int getCost(){
    return pizza->getCost() + 50;
  }
  
};

class Mushroom : public Toppings{
  BasePizza* pizza;
  public:
  Mushroom(BasePizza* pizza){
    this->pizza= pizza;
  }
  int getCost(){
    return pizza->getCost() + 30;
  }
  
};
int main(){
BasePizza* pizza= new Mushroom(new MarghretaPizza());
cout<<pizza->getCost()<<endl;
pizza= new ExtraCheese(pizza);
cout<<"New cost is "<<pizza->getCost()<<endl; 

BasePizza* pizza2 = new Mushroom(new ExtraCheese(new FarmhousePizza()));
cout<<"Cost of your pizza is "<<pizza2->getCost();

return 0;
}