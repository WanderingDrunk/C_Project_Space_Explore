#include "space_explorer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{
    unsigned int *previous_connections;
    int previous_num_connections;
    unsigned int last_planet; // last planet that was crt_planet
    double previous_distance_from_mixer; // needed so i can compare if i am heading in the right direction
    int jumps; // made to see how many jumps were done without actually getting treasure planet
    int jumped_connection; // the number which of which connections was jumped to. i.e. connections[0]

} travel_info;

ShipAction space_hop(unsigned int crt_planet,
                   unsigned int *connections, // array of planets connected so could use i.e. nextplanet = connections[0]
                   int num_connections,
                   double distance_from_mixer,
                   void *ship_state) // I set it to my travel_info struct
{
    /* your solution here 
    
    /*For backtracking need to have previous planet and an array of banned planets*/

    printf("You are %lf away from the treasure planet and striking it rich.\n", distance_from_mixer);
    printf("You are currently on planet %u.\n", crt_planet);
    printf("There are currently %d planets you can reach from here.\n", num_connections);

    travel_info *myguy;
    if (ship_state == NULL) {
        myguy = malloc(sizeof(travel_info));
        myguy->last_planet = 0;
        myguy->jumps = 0;
        myguy->previous_distance_from_mixer = 0.0;
        myguy->jumped_connection = 0;
        myguy->previous_num_connections = 0;
    }else{
            myguy = ship_state;
            printf("My Last Planet's ID was %u\n", myguy->last_planet);
        }

    myguy->previous_connections = malloc(sizeof(unsigned int)*num_connections); 
    // temp might need to change where it is later
    // assigns enough space every time for array

    // dynamically allocates memory and copies connections into previous connections
    myguy->previous_connections = malloc(sizeof(unsigned int)*num_connections);
    for (int i = 0; i < num_connections; i++)
    {
        myguy->previous_connections[i] = connections[i];
    }

    // trying to ccopy crt_planet to last_planet
    
    myguy->last_planet = crt_planet;

    

    ShipAction bruh;
    for (int i = 0; i < num_connections; i++)
    {
        printf("Planet %d ID: %u\n", i+1, connections[i]); // Prints out the id of all the planets in jumpoing distance
    }
    
    //      TEST TO SEE IF CONNECTIONS ARRAY WAS SUCCSEFULLY COPIED
    // for (int i = 0; i < num_connections; i++)
    // {
    //     printf("Planet %d ID: %u\n", i+1, myguy.previous_connections[i]); // Prints out the id of all the planets in jumpoing distance
    // }


    printf("Connection 0 is %u\n",connections[0]);
    
    for (int i = 0; i < num_connections; i++)
    {
        printf("Connection: %d\n", connections[i]);
    }

    for(int i = 0; i < num_connections; i++){
        myguy->previous_connections[i] = connections[i];
    }

    // test to see if the previous connections were added
    
    if(myguy->previous_num_connections != 0){
        for (int i = 0; i < myguy->previous_num_connections; i++)
        {
            printf("Previous Connection: %d\n", myguy->previous_connections[myguy->previous_num_connections]);
        }
    }

    


    //          RANDOM HOP WORKING
    if(distance_from_mixer > 2){
        bruh.next_planet = RAND_PLANET;
        printf("This is jump %d\n", myguy->jumps);
        myguy->jumps++;
    } else {
        bruh.next_planet = connections[0];
        
    }


    // if(distance_from_mixer > 2){
    //     bruh.next_planet = RAND_PLANET;
    //     printf("This is jump %d\n", myguy->jumps);
    //     myguy->jumps++;
    // }else if (distance_from_mixer < myguy->previous_distance_from_mixer){ // Checks if treasure is now closer 
    //     bruh.next_planet = connections[myguy->jumped_connection];
    // }else if (distance_from_mixer > myguy->previous_distance_from_mixer){ // Checks if treasure is now farther away
    //     bruh.next_planet = myguy->last_planet; // If treasure is farther go back to previous planet
    //     myguy->jumped_connection++; // increase number to go to next conneciton instead
    // }
    




    myguy->previous_distance_from_mixer = distance_from_mixer;

    bruh.ship_state = myguy;
    return bruh;

    

    // make if else statement since switch statements do not support greater than or less than
    /*      TYPES OF IF-ELSE'S I WILL NEED
        -if connection 0 is farther than the previous planet i was on then go to connection 1
        -repeat for as many connections i.e. some sort of for or while loop
        -if all the connections do not lead to the treasure do a random hop and repeat previous 
        - */


} // ship state is my struct
