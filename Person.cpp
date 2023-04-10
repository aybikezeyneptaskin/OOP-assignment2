#include "Person.h"
#include "Mission.h"
#include "Agency.h"

//CONSTRUCTORS

Person::Person(string Name,string Surname){
    name=Name;
    surname=Surname;
}

Person::Person(const Person& ptr){
    name=ptr.name;
    surname=ptr.surname;
}

Person::~Person(){};

Passenger::Passenger(string Name,string Surname,int Cash,bool Ticket):Person{Name,Surname}{
    if(Cash<0){
        Cash=0;
        cout<<"Passenger cash can't be negative. It is set to 0."<<endl;
    }
    cash=Cash;
    ticket=Ticket;
    Next=NULL;
}

Passenger::Passenger(const Passenger& ptr){
    cash=ptr.cash;
    ticket=ptr.ticket;
    Next=ptr.Next;
}

Passenger::~Passenger(){};

Astronaut::Astronaut(string Name,string Surname,int NumMissions):Person{Name,Surname}{
    if(NumMissions<0){
        NumMissions=0;
        cout<<"Number of missions that astronaut completed can't be negative. It is set to 0."<<endl;
    }
    numMissions=NumMissions;
    Next=NULL;
}
Astronaut::Astronaut(const Astronaut &ptr){
    numMissions=ptr.numMissions;
    Next=ptr.Next;
}
Astronaut::~Astronaut(){}


//FUNCTIONS
bool Passenger::buyTicket(int ticket_price){
    if(cash>=ticket_price){
        cash=cash-ticket_price;
        Passenger::setCash(cash);
        setTicket(true);
        return true;
    }
    else{
        setTicket(false);
        return false;
    }
}

void Astronaut::completeMission(){
    numMissions++;
    setNumMissions(numMissions);
   
}
