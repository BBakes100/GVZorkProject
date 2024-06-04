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

#ifndef _H__ITEM__
#define _H__ITEM__

#include <string>
#include <iostream>

/**
* This class represents objects the player may encounter along the way. 
*/
class Item {

    public:
        
        /**
        * Constructs an Item with a name, description, number of calories it can provide, 
        * and a weight. 
        *
        * @param name The name of the Item.
        * @param description The description of the Item
        * @param calories The number of calories the Item can provide.
        * @param weight The weight of the Item.
        */
        Item(std::string name, std::string description, int calories, float weight);

        // Declare the overloaded << operator as a friend (CHAT GPT)
        friend std::ostream& operator<<(std::ostream& os, const Item& item);

        /**
        * Gets the Item's calories.
        *
        * @return The Item's calories.
        */
        int getCalories();

        /**
        * Gets the Item's weight.
        *
        * @return the Item's weight.
        */
        float getWeight();

        /**
        * Gets the Item's name.
        *
        * @return The Item's name.
        */
        std::string getName();

    private:
        std::string name;
        std::string description;
        int calories;
        float weight;
};

#endif
