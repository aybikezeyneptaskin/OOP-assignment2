#ifndef AGENCY_H
#define AGENCY_H
#include <iostream>
#include <cstring>
#include "Mission.h"
#include "Person.h"

using namespace std;

class Agency{
  string name;
  int cash;
  int ticketPrice;
  Mission* completedMissions;
  Mission* nextMissions;
  friend std::ostream& operator << (std::ostream&, Agency&);

public:
  
  //constructors
  Agency(string name="",int cash=0,int ticketPrice=0,Mission* ptr=NULL,Mission* ptr2=NULL);
  Agency(const Agency&ptr);
  ~Agency();
  

  //getters setters
  void setName(string Name){name=Name;}
  string getName(){return name;}

  void setCash(int Cash){cash=Cash;}
  int getCash(){return cash;}

  void setTicketPrice(int TicketPrice){ticketPrice=TicketPrice;}
  int getTicketPrice(){return ticketPrice;}

  void setCompletedMissions(Mission* CompletedMissions){completedMissions=CompletedMissions;}
  Mission* getCompletedMissions(){return completedMissions;}

   void setNextMissions(Mission* NextMissions){nextMissions=NextMissions;}
  Mission* getNextMissions(){return nextMissions;}

  //functions
  
  void addMission(Mission&);
  void executeNextMission();
  
};

std::ostream& operator << (std::ostream&, Agency&);


#endif
