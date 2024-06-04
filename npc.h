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

#ifndef _H__NPC__
#define _H__NPC__

#include <string>
#include <vector>
#include <iostream>

/**
* This class represents information about a character that can be in a Location.
*/
class Npc {

    public:

        /**
        * Constructs an NPC with a name and description.
        *
        * @param name The name of the NPC.
        * @param desc The description of the NPC.
        */
        Npc(std::string name, std::string desc);

        /**
        * Gets the name of the NPC.
        *
        * @return The name of the NPC.
        */
        std::string getName();

        /**
        * Gets the description of the NPC.
        *
        * @return The description of the NPC.
        */
        std::string getDescription();

        /**
        * Gets the NPC's message.
        *
        * @return The NPC's message.
        */
        std::string getCurrentMessage();

        /**
        * Adds a new message to the NPC's vector of messages.
        * 
        * @param newMessage The message to add.
        */
        void addMessage(std::string newMessage);

        /**
        * Overloaded stream operator that returns only the name of the
        * NPC. 
        * Declare the overloaded << operator as a friend (CHAT GPT)
        * 
        * @param os The stream operator.
        * @param npc The NPC.
        */
        friend std::ostream& operator<<(std::ostream& os, Npc npc);


    private:
        std::string name;
        std::string desc;
        int messageNum;
        std::vector<std::string> messages;

};

#endif 
