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
* This class contains functions realted to a Location object 
*/

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include "item.h"
#include "npc.h"
#include "location.h"

Location::Location(){

    // Default values
    this->name = "default name";
    this->desc = "default desc";
    visited = false;
}

Location::Location(std::string name, std::string desc){
    try{
        this->name = name;
        this->desc = desc;
        visited = false;

        // Throw invalid argument if name or desc is empty
        if(name.empty()){
            throw std::invalid_argument("Name can not be empty");
        } 
        if (desc.empty()){
            throw std::invalid_argument("Description can not be empty");
        }
    } 
    // Exit game
    catch (std::invalid_argument& e) {
        std::cerr << "Invalid arguments: " << e.what() << std::endl;
        exit(1);
    }
}

void Location::addLocation(std::string direction, Location& location){
    try {
        // Direction can't be blank
        if(direction.empty()){
            throw std::invalid_argument("Direction can not be blank");
        }
        // Direction can't already exist
        if(neighbors.find(direction) != neighbors.end()){
            throw std::invalid_argument("Direction already exists");
        }
        neighbors.insert({direction, location});
    }
    // Exit if invalid argument 
    catch (std::invalid_argument& e) {
        std::cerr << "Invalid arguments: " << e.what() << std::endl;
        exit(1);
    }
}

void Location::addNpc(Npc npc){
    npcList.push_back(npc);
}

std::vector<Npc>& Location::getNPCs(){
    return npcList;
}

void Location::addItem(Item item){
    itemList.push_back(item);
}

std::vector<Item>& Location::getItems(){
    return itemList;
}

std::map<std::string, std::reference_wrapper<Location>> Location::getLocations(){
    return neighbors;
}

bool Location::getVisited(){
    return visited;
}

std::string Location::getName(){
    return name;
}

std::string Location::getDesc(){
    return desc;
}

void Location::setVisited(){
    visited = true;
}

void Location::removeItem(std::string itemName){
    int pos = 0;

    // Check item in location
    for (int i = 0; i < itemList.size(); i++) {
        if(itemName == itemList[i].getName()){
            pos = i;
        }
     }

     // Remove item
     itemList.erase(itemList.begin() + pos);
}

void Location::removeNpc(std::string npcName){
    int pos = 0;

    // Check npc in location
    for (int i = 0; i < npcList.size(); i++) {
        if(npcName == npcList[i].getName()){
            pos = i;
        }
     }

     // Remove Npc from location
     npcList.erase(npcList.begin() + pos);
}

std::ostream& operator<<(std::ostream& os, Location location){
    std::vector<Npc> listOfNpcs = location.getNPCs();
    std::vector<Item> listOfItems = location.getItems();
    std::map<std::string, std::reference_wrapper<Location>> mapOfLocations = location.getLocations();

    // Print location name, desc, and Npcs
    os << location.getName() << " - " << location.getDesc() << "\n\nYou see the following NPCs:\n" << std::endl;
    for(auto it = listOfNpcs.begin(); it != listOfNpcs.end(); ++it){
        os << "\t- " << *it << "\n" << std::endl;
    }
    
    // Print location's items
    os << "\nYou see the following Items:\n" << std::endl;
    for(auto it = listOfItems.begin(); it != listOfItems.end(); ++it){
        os << "\t- " << *it << "\n" << std::endl;
    }

    // Print location's neighbors
    os << "\nYou can go in the following Directions:\n" << std::endl;
    for (auto it = mapOfLocations.begin(); it != mapOfLocations.end(); ++it) {
        os << "\t- " << it->first << " - ";
        if(it->second.get().getVisited()){
            os << it->second.get().getName() << " (Visited)\n" << std::endl;
        } else {
            os << "Unknown\n" << std::endl;
        }
    }

    return os;
}
