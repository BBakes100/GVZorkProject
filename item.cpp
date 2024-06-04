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
* This class contains functions realted to an Item object 
*/

#include <string>
#include <iostream>
#include "item.h"

Item::Item(std::string name, std::string description, int calories, float weight) {

    try {
        this->name = name;
        this->description = description;
        this->calories = calories;
        this->weight = weight;
    
        // Make sure conditions for an item are satisfied
        if (name.empty()) {
            throw std::invalid_argument("Name can not be empty");
        }
        if (description.empty()) {
            throw std::invalid_argument("Description can not be empty");
        }
        if (calories < 0 || calories > 1000) {
            throw std::invalid_argument("Calories must be an int between 0 and 1000");
        }
        if (weight < 0.0 || weight > 500.0) {
            throw std::invalid_argument("Weight must be a float between 0.0 and 500.0");
        }
    } catch(std::invalid_argument& e) {
        std::cerr << "Invalid arguments: " << e.what() << std::endl;
        exit(1);
    }
}

int Item::getCalories() {
    return calories;
}

float Item::getWeight() {
    return weight;
}

std::string Item::getName(){
    return name;
}

std::ostream& operator<<(std::ostream& os, const Item& item) {
    
    // Print item values in correct format
    os << item.name << " (" << item.calories << " calories) - " << item.weight << " lb - " << item.description;
    return os;
}
