#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <cstring>

using namespace std;

class Person{
  protected:
  string name;
  string surname;

public:
  //constructors
  Person(string name="",string surname="");
  Person(const Person &ptr);
  ~Person();
  //getters setters
  void setName(string Name){name=Name;}
  string getName(){return name;}

  void setSurname(string Surname){surname=Surname;}
  string getSurname(){return surname;}
};

class Passenger : public Person {
  int cash;
  bool ticket;

public:
  Passenger* Next=NULL;
  //constructors
  Passenger(string name="",string surname="",int cash=0,bool Ticket=false);
  Passenger(const Passenger &ptr);
  ~Passenger();

  //getters setters
  void setCash(int Cash){cash=Cash;}
  int getCash(){return cash;}

  void setTicket(bool Ticket){ticket=Ticket;}
  bool getTicket(){return ticket;}

    void setName(string Name){name=Name;}
  string getName(){return name;}

  void setSurname(string Surname){surname=Surname;}
  string getSurname(){return surname;}

  //functions
  bool buyTicket(int ticket_price);
};

class Astronaut : public Person {
  int numMissions;

public:
  Astronaut* Next=NULL;
  //constructors
  Astronaut(string name="",string surname="",int numMissions=0);
  Astronaut(const Astronaut &ptr);
  ~Astronaut();

  //getteers setters
  void setNumMissions(int NumMissions){numMissions=NumMissions;}
  int getNumMissions(){return numMissions;}

    void setName(string Name){name=Name;}
  string getName(){return name;}

  void setSurname(string Surname){surname=Surname;}
  string getSurname(){return surname;}

  //functions
  void completeMission();
};

#endif
