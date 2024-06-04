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

#ifndef _H__LOCATION__
#define _H__LOCATION__

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include "item.h"
#include "npc.h"

/**
* This class represents a place on campus that may be visited. 
*/
class Location {

    public:

        /**
        * Default constructor for a Location.
        */
        Location();

        /**
        * Constructor for a Location that takes a name and description.
        *
        * @param name The name of the Location.
        * @param desc The description of the Location.
        */
        Location(std::string name, std::string desc);

        /**
        * Gets the neighboring locations to a Location.
        *
        * @return A map of the neighboring locations.
        */
        std::map<std::string, std::reference_wrapper<Location>> getLocations();

        /**
        * Adds a specified location into the map with the provided direction string.
        * 
        * @param direction The provided direction.
        * @param location The Location to add to the map.
        */
        void addLocation(std::string direction, Location& location);

        /**
        * Adds an NPC to the Location's vector. 
        *
        * @param npc The NPC to add to the Location.
        */
        void addNpc(Npc npc);

        /**
        * Gets all of the NPCs at a Location.
        *
        * @return A vector of NPCs.
        */
        std::vector<Npc>& getNPCs();

        /**
        * Adds an Item to the Location's vector.
        *
        * @param item The Item to add to the location.
        */
        void addItem(Item item);

        /**
        * Gets all of the Items at a Location.
        *
        * @return A vector of Items.
        */
        std::vector<Item>& getItems();

        /**
        * Changes the visited variable to true. Once a Location is visited, 
        * it can no longer be false. 
        */
        void setVisited();

        /**
        * Checks if a Location has been visited.
        *
        * @return True if the location has been visited, otherwise false.
        */
        bool getVisited();

        /**
        * Gets the name of the Location.
        * 
        * @return The name of the Location.
        */
        std::string getName();

        /**
        * Gets the description of the Location.
        *
        * @return The description of the Location. 
        */
        std::string getDesc();

        /**
        * Removes an Item from the Location.
        * 
        * @param itemName The Item to remove.
        */
        void removeItem(std::string itemName);

        /**
        * Helper function to remove an Npc from the Npc vector in Game::
        *
        * @param npcName Npc to remove 
        */
        void removeNpc(std::string npcName);

        /**
        * Gets a string of the Location name, description, which NPCs and 
        * which items are in the Location, and which directions are available.
        * Declare the overloaded << operator as a friend (CHAT GPT)
        * 
        * @param os The stream operator.
        * @param location The Location.
        */
        friend std::ostream& operator<<(std::ostream& os, Location location);

    private:
        std::string name;
        std::string desc;
        bool visited;
        std::map<std::string, std::reference_wrapper<Location>> neighbors;
        std::vector<Item> itemList;
        std::vector<Npc> npcList;
};

#endif
