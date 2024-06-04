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
* This class holds all the logic for a game instance.
*/

#ifndef _H__GAME__
#define _H__GAME__

#include "location.h"
#include "item.h"
#include "npc.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <functional>

/**
* This class holds all the logic for a game instance.
*/
class Game {

    public:

        /**
        * Creates a Game. Sets the commands map, calls upon the createWorld mehtod, 
        * and sets default values for all other variables.
        */
        Game();

        /**
        * Creates the Location, Items, and NPCs in the Game. 
        */
        void createWorld();

        /**
        * Creates a map of all the available commands.
        * 
        * @return a map containing the commands.
        */
        std::map<std::string, void (Game::*)(std::vector<std::string>)> setupCommands();
        
        /**
        * Selects a random Location from the locations vector.
        *
        * @return Location
        */
        Location randomLocation();

        /**
        * The core game loop. 
        */
        void play();

        /**
        * Prints out a help message and all the commands from thecommand 
        * map's keys. This method must also post the current time.
        */
        void show_help(std::vector<std::string> target);

        /**
        * Checks if the provided NPC is in the current room. If it is, a message from
        * the NPC will be printed.
        * 
        * @param target The provided NPC.
        */
        void talk(std::vector<std::string> target);

        /**
        * Checks if the NPC is in the room. If it is the NPC's descruption will 
        * be printed.
        * 
        * @param target The provided NPC. 
        */
        void meet(std::vector<std::string> target);

        /**
        * Checks if the specified item is in the room. If it is, it will be removed 
        * from the room and added to the user's inventory. The weight of the item will
        * be added to the user's carried weight. 
        * 
        * @param target The item to take.
        */
        void take(std::vector<std::string> target);

        /**
        * Checks if the specified item exists in the user's inventory. If it does, the
        * item will be removed from the user's inventory and added to the current location's
        * inventory. The weight of the item will be subtracted from the user's carried weight. 
        * Checks if the location is the woods. If the item is edible, it will be given to the elf 
        * and the current number of calories that the elf needs will decrease by the item's 
        * calories. If the item was not edible, the user will be transported to a new location.
        * 
        * @param target The item to give. 
        */
        void give(std::vector<std::string> target);

        /**
        * Helper function to remove an Item from the playerInventory vector in Game::
        *
        * @param itemName Item to remove 
        */
        void removeItem(std::string itemName);

        /**
        * Sets the current location's visited status to True. Checks if the player has over
        * 30 weight. Checks if the provided direction exists in the current location's neighbor
        * map. If it does, go to that location. 
        * 
        * @param target The provided direction to go.
        */
        void go(std::vector<std::string> target);

        /**
        * Prints all items the player is carrying, and the current amount of weight carried.
        *
        * @param target Nothing needs to be passed in. 
        */
        void show_items(std::vector<std::string> target);

        /**
        * Prints the current location, a vector of the Items in the location or a message indicating
        * there are none, a vector of NPCs in the room or the message "you are alone", and a vector 
        * of directions in which the player can go.
        *
        * @param target Nothing needs to be passed in.
        */
        void look(std::vector<std::string> target);

        /**
        * Prints a failure message and exits the game.
        *
        * @param target Nothing needs to be passed in.
        */
        void quit(std::vector<std::string> target);

        /**
        * Compares two strings to determine if they are the same (case insensitive). 
        * Returns 1 if the strings are the same, returns 0 if the strings are not the same.
        *
        * @param s1 The first string to compare.
        * @param s2 The second string that is compared with the first string.
        */
        int case_insensitive_match(std::string s1, std::string s2);

        /**
        * Gets the current time in 12 hour format. 
        */
        void getCurrentTime();
        
        /**
        * Removes the passed Item from the user's inventory. 
        * One of the additional custom commands.
        * 
        * @param target The Item to remove.
        */
        void eat(std::vector<std::string> target);

        /**
        * Moves the NPC from its Location to the user's current location.
        * The second additional custom command.
        *
        * @param target The NPC to call.
        */
        void callNpc(std::vector<std::string> target);


    private:
        std::map<std::string, void (Game::*)(std::vector<std::string>)> commands;
        int elfCaloriesLeft;
        bool gameInprogress;
        std::vector<Location> worldLocations;
        Location currentLocation;
        std::vector<Item> playerInventory;
        float playerCarryWeight;

};

#endif
