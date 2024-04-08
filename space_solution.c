#include "space_explorer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ShipAction space_hop(unsigned int crt_planet,
                   unsigned int *connections, // array of planets connected so could use i.e. nextplanet = connections[0]
                   int num_connections,
                   double distance_from_mixer,
                   void *ship_state) // can be anything i want it to be
{
    /* your solution here 
    need  structure to store these variables:
                                            planets jumped to
                                            previous planet*/
    
    /*For backtracking need to have previous planet and an array of banned planets*/

    printf("You are %lf away from the treasure planet and striking it rich.\n", distance_from_mixer);
    printf("You are currently on planet %x.\n", crt_planet);
    printf("There are currently %d planets you can reach from here.\n", num_connections);
    

ShipAction bruh;

    bruh.next_planet = connections[0];


    //          RANDOM HOP WORKING
    if(distance_from_mixer > 2){
        bruh.next_planet = RAND_PLANET;
    } else {
        bruh.next_planet = connections[0];
    }
    return bruh;

}
