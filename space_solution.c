#include "space_explorer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{
    unsigned int *previous_connections; // array of connections from last_planet
    int previous_num_connections; // number of array connections form last_planet
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

    travel_info *last_space_hop;
    if (ship_state == NULL) {
        last_space_hop = malloc(sizeof(travel_info));
        last_space_hop->last_planet = 0;
        last_space_hop->jumps = 0;
        last_space_hop->previous_distance_from_mixer = 0.0;
        last_space_hop->jumped_connection = 0;
        last_space_hop->previous_num_connections = 0;


        // dynamically allocates memory and copies connections into previous connections
        last_space_hop->previous_connections = malloc(sizeof(unsigned int)*num_connections);

    }else{
            last_space_hop = ship_state;
            // if (last_space_hop->previous_num_connections !=  num_connections) { // if the size of connections is not the same i reallocate the memory
            //   last_space_hop->previous_connections = realloc(last_space_hop->previous_connections, sizeof(unsigned int) * num_connections);
            // }
            printf("My Last Planet's ID was %u\n", last_space_hop->last_planet);
        }


    // test to see if the previous connections were added
    
    if(last_space_hop->previous_num_connections != 0){
        for (int i = 0; i < last_space_hop->previous_num_connections; i++){
            
            printf("Previous Connection: %u\n", last_space_hop->previous_connections[i]);
            last_space_hop->previous_connections[i] = connections[i];
        }
    }


    // for (int i = 0; i < num_connections; i++)
    // {
    //     last_space_hop->previous_connections[i] = connections[i];
    //     printf("Previous Connection: %u\n", last_space_hop->previous_connections[i]);
    // }


    

    ShipAction current_space_hop;
    for (int i = 0; i < num_connections; i++)
    {
        printf("Planet %d ID: %u\n", i+1, connections[i]); // Prints out the id of all the planets in jumping distance
    }


    printf("Connection 0 is %u\n",connections[0]);
    

    //          RANDOM HOP WORKING
    if(distance_from_mixer > 2){ // simple run of prog to see if it
        current_space_hop.next_planet = RAND_PLANET;
        printf("This is jump %d\n", last_space_hop->jumps);
        last_space_hop->jumps++;
    } else {
        current_space_hop.next_planet = connections[0];
        
    }

    //getchar();

    // if(distance_from_mixer > 2){
    //     current_space_hop.next_planet = RAND_PLANET;
    //     printf("This is jump %d\n", last_space_hop->jumps);
    //     last_space_hop->jumps++;
    // }else if (distance_from_mixer < last_space_hop->previous_distance_from_mixer){ // Checks if treasure is now closer 
    //     current_space_hop.next_planet = connections[last_space_hop->jumped_connection];
    // }else if (distance_from_mixer > last_space_hop->previous_distance_from_mixer){ // Checks if treasure is now farther away
    //     current_space_hop.next_planet = last_space_hop->last_planet; // If treasure is farther go back to previous planet
    //     last_space_hop->jumped_connection++; // increase number to go to next conneciton instead
    // }
    
    


    last_space_hop->last_planet = crt_planet; // moves current planet to last planet
    last_space_hop->previous_num_connections = num_connections; // Sets number of connections to the last connections
    last_space_hop->previous_distance_from_mixer = distance_from_mixer; // moves distnace form mixer to previous distnace from mixer

    current_space_hop.ship_state = last_space_hop;
    return current_space_hop;

    

    // make if else statement since switch statements do not support greater than or less than
    /*      TYPES OF IF-ELSE'S I WILL NEED
        -if connection 0 is farther than the previous planet i was on then go to connection 1
        -repeat for as many connections i.e. some sort of for or while loop
        -if all the connections do not lead to the treasure do a random hop and repeat previous 
        - */


} // ship state is my struct
