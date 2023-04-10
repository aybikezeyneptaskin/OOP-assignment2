#include "Mission.h"
#include "Person.h"
#include "Agency.h"
#include <cstdlib>

//CONSTRUCTORS
Mission::Mission(string Name,int Cost,int FaultProbability,int MissionNumber,bool Completed,Passenger *Passengers,Astronaut *Crew,/*static*/int NumMissions){
    char c = '-';
    if(Name.length()!=5 || Name.find(c)!=2 || int(Name[0])<65 || int(Name[1])<65 || int(Name[0])>90 || int(Name[1])>90 || int(Name[3])<48 || int(Name[4])<48 || int(Name[3])>557 || int(Name[4])>57)
    {
        Name="AA-00";
        cerr<<"Given name does not satisfy the mission naming convention. Please set a new name!"<<endl;//cerr mi olmalı??

    }
    name=Name;
    cost=Cost;
    faultProbability=FaultProbability;
    completed=Completed;
    passengers=NULL;
    crew=NULL;
    numMissions++;
    missionNumber=numMissions;
    Next=NULL;
    
}
Mission::Mission(const Mission &ptr){
    name=ptr.name;
    missionNumber=ptr.missionNumber;
    cost=ptr.cost;
    Next=ptr.Next;
    passengers=ptr.passengers;
    crew=ptr.crew;
}
Mission::~Mission(){
    PassengersNode* tempPass=passengers;
    CrewNode* tempCrew=crew;
   if(passengers!=NULL){
    while(tempPass->next!=NULL){
        passengers=passengers->next;
        delete tempPass;
        tempPass=passengers;
    }delete tempPass;}
if(crew!=NULL){
    while(tempCrew->next!=NULL){
        crew=crew->next;
        delete tempCrew;
        tempCrew=crew;
    }delete tempCrew;
}}

//FUNCTIONS
void Mission::operator += (Passenger* new_passenger){
    if(new_passenger->getTicket()==true){
        //add
        if(passengers==NULL){
            passengers=new PassengersNode(new_passenger);
        }else{
            PassengersNode* tempPassenger=passengers;
            while (tempPassenger->next!=NULL){
                tempPassenger=tempPassenger->next;
            }
            tempPassenger->next=new PassengersNode(new_passenger);
            new_passenger->Next=NULL;            
        }

    }else{
        //error message
        cerr<<"Passenger "<<new_passenger->getName()<<" "<<new_passenger->getSurname()<<" does not have a valid ticket!"<<endl;
    }
}

void Mission::operator += (Astronaut* new_astronaut){
    //add
    if(crew==NULL){
        crew=new CrewNode(new_astronaut);
    }else{
        CrewNode* tempAstronaut=crew;
        while(tempAstronaut->next!=NULL){
            tempAstronaut=tempAstronaut->next;
        }
        tempAstronaut->next=new CrewNode(new_astronaut);
        new_astronaut->Next=NULL;
    }

}

bool Mission::executeMission(){
    int num=rand()%100+1;
    if(num>faultProbability){
        //success
        CrewNode* tempAstronaut=crew;
        cout<<"MISSION "<<name<<" SUCCESSFUL!"<<endl;

        while(tempAstronaut!=NULL){
            tempAstronaut->element->completeMission();
            cout<< "Astronaut "<< tempAstronaut->element->getName()<<" "<< tempAstronaut->element->getSurname()<<" successfully completed "<< tempAstronaut->element->getNumMissions()<< " missions." <<endl;
            tempAstronaut=tempAstronaut->next;
        }
        
        completed=true;
    }else{
        //fail
        cout<<"MISSION "<<name<<" FAILED!"<<endl;
        cout<<"Agency reschedules the mission."<<endl;
        completed=false;
    }
   
    return completed;
}


int Mission::calculateProfit(int ticketPrice){
    int profit;
    int num=0;
    PassengersNode* tempPas = passengers;
    while(tempPas!=NULL){
        num++;
        tempPas=tempPas->next;
    }

    if(completed==true){
        profit=ticketPrice*num - getCost();
    }else if(completed==false){ 
        profit = - getCost();
    }  
    return profit; 
}

PassengersNode::PassengersNode(Passenger* newPass){
    element = newPass;
    next = NULL;
}
PassengersNode::~PassengersNode(){}

CrewNode::CrewNode(Astronaut* newAstr){
    element = newAstr;
    next = NULL;
}

CrewNode::~CrewNode(){}
