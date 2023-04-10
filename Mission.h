#ifndef MISSION_H
#define MISSION_H
#include <iostream>
#include <cstring>
#include <ctime>

#include "Person.h"

using namespace std;

class PassengersNode;
class CrewNode;

class Mission{
 
  string name;
  int missionNumber;
  int cost;
  int faultProbability;
  bool completed;
  PassengersNode *passengers;
  CrewNode *crew;
  static int numMissions;

public:
  Mission* Next=NULL;
  //constructors
  Mission(string name="",int cost=0,int faultProbability=0,int missionNumber=0,bool completed=false,Passenger *passengers=NULL,Astronaut *crew=NULL,/*static*/int numMissions=0);//??
  Mission(const Mission &ptr);
  ~Mission();

  //getters setters
  void setName(std::string Name){name=Name;}
  std::string getName(){return name;}

  void setMissionNumber(int MissionNumber){missionNumber=MissionNumber;}
  int getMissionNumber(){return missionNumber;}

  void setCost(int Cost){cost=Cost;}
  int getCost(){return cost;}

  void setFaultProbability(int FaultProbability){faultProbability=FaultProbability;}
  int getFaultProbability(){return faultProbability;}

  void setCompleted(bool Completed){completed=Completed;}
  bool getCompleted(){return completed;}

  
  PassengersNode* getPassengers(){return passengers;}

  CrewNode* getAstronauts(){return crew;}

  void setNumMissions(int NumMissions){numMissions=NumMissions;}
  int getNumMissions(){return numMissions;}

  //functions
  void operator += (Passenger*);
  void operator += (Astronaut*);
  bool executeMission();//??
  int calculateProfit(int ticketPrice);
};

class PassengersNode{
  public:
  Passenger *element;
  PassengersNode *next;
  PassengersNode(Passenger*);
  ~PassengersNode();
};

class CrewNode{
  public:
  Astronaut *element;
  CrewNode *next;
  CrewNode(Astronaut*);
  ~CrewNode();
};

#endif
