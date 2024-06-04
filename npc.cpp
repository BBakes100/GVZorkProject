/*
* ---------------
* GVZork Project
* CIS 343-01
* October 5, 2023
*
* Bailey Compton
* Brandon Baker
* Sarah Wight
* ---------------
*
* This class contains functions realted to an NPC object 
*/

#include <string>
#include <vector>
#include <iostream>
#include "npc.h"

Npc::Npc(std::string name, std::string desc){
    try{
        this->name = name;
        this->desc = desc;
        this->messageNum = 0;

        // Name and desc field must have values
        if(name.empty()){
            throw std::invalid_argument("Name can not be empty");
        } 
        if (desc.empty()){
            throw std::invalid_argument("Description can not be empty");
        }
    } catch (std::invalid_argument& e) {
        std::cerr << "Invalid arguments: " << e.what() << std::endl;
        exit(1);
    }
}

std::string Npc::getName(){
    return name;
}

std::string Npc::getDescription(){
    return desc;
}

void Npc::addMessage(std::string newMessage){
    try {
        // Message must have value
        if(newMessage.empty()){
            throw std::invalid_argument("Message can not be empty");
        }

        // Add message to Npc
        messages.push_back(newMessage);
    } catch (std::invalid_argument& e) {
        std::cerr << "Invalid arguments: " << e.what() << std::endl;
        exit(1);
    }
}

std::string Npc::getCurrentMessage(){

    if(messages.empty()){
        return "No messages";
    }

    // Increment message num and grab current message
    std::string currentMessage = messages[messageNum++];
    if(messageNum == messages.size()){
        messageNum = 0;
    }
    return currentMessage;
}

std::ostream& operator<<(std::ostream& os, Npc npc){

    // Print npc name
    os << npc.getName();
    return os;
}
