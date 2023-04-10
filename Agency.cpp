#include "Agency.h"
#include "Mission.h"
#include "Person.h"

//CONSTRUCTORS
Agency::Agency(string Name,int Cash,int TicketPrice, Mission*ptr,Mission*ptr2){
    name=Name;
    cash=Cash;
    if(TicketPrice<0){
        TicketPrice=0;
        cout<<"Ticket price can't be negative. It is set to 0."<<endl;
    }
    ticketPrice=TicketPrice;
    completedMissions=ptr;
    nextMissions=ptr2;
}
Agency::Agency(const Agency&ptr){
    name=ptr.name;
    cash=ptr.cash;
    ticketPrice=ptr.ticketPrice;
    completedMissions=ptr.completedMissions;
    nextMissions=ptr.nextMissions;
}
Agency::~Agency(){}

//FUNCTIONS

std::ostream& operator << (std::ostream& output, Agency& ptr){
    output<<"Agency name: "<<ptr.getName()<<", "<<"Total cash: "<<ptr.getCash()<<", "<<"Ticket Price: "<<ptr.getTicketPrice()<<endl;
    output<<"Next Missions:"<<endl;
    if(ptr.getNextMissions()!=NULL){
        Mission* tempMission=ptr.getNextMissions();
        while(tempMission!=NULL){
            output<<"Mission number: "<<tempMission->getMissionNumber()<<" Mission name: "<<tempMission->getName()<<" Cost: "<<tempMission->getCost()<<endl;
            tempMission=tempMission->Next;
        }
    }else if(ptr.getNextMissions()==NULL){
        output<<"No missions available."<<endl;
    }

    output<<"Completed Missions:"<<endl;
    if(ptr.getCompletedMissions()!=NULL){
        Mission* tempMission=ptr.getCompletedMissions();
        while(tempMission!=NULL){
            output<<"Mission number: "<<tempMission->getMissionNumber()<<" Mission name: "<<tempMission->getName()<<" Cost: "<<tempMission->getCost()<<endl;
            tempMission=tempMission->Next;
        }
    }else if(ptr.getCompletedMissions()==NULL){
        output<<"No missions completed before."<<endl;
    }
    return output;
}



void Agency::addMission(Mission& new_mission){
    Mission* tempMissions=nextMissions;
    if(nextMissions==NULL){
        nextMissions = &new_mission;
    }else{
        while(tempMissions->Next!=NULL){
            tempMissions=tempMissions->Next;
        }
        tempMissions->Next = &new_mission;
    }
}

void Agency::executeNextMission(){
    
    Mission* tempMission = completedMissions;
    Mission* tempNext=nextMissions;
    Mission* tempAdd=nextMissions;
    
    if(tempNext==NULL){
        cout<<"No available mission to execute!"<<endl;
    }
    else{
        tempNext->executeMission();
        setCash(cash+tempNext->calculateProfit(ticketPrice));
        if(tempNext->getCompleted()==true){
            nextMissions=tempNext->Next;
            tempNext->Next=NULL;
            if(completedMissions==NULL){
                completedMissions=tempNext;
            }
            else{
                while(tempMission->Next!=NULL){
                    tempMission=tempMission->Next;
                }
                tempMission->Next=tempNext;
                tempNext->Next=NULL;
            }


        }else{
            //add end of the next list 
            if(nextMissions->Next==NULL){
                nextMissions=tempNext;
            }
            else{
            nextMissions=tempNext->Next;
            while(tempAdd->Next!=NULL){
                tempAdd=tempAdd->Next;
            } tempAdd->Next =  tempNext;
            tempNext->Next=NULL;
        }}
    
    }
}

  
  
