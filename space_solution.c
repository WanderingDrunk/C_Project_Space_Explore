#include "space_explorer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    unsigned int *previous_connections; // array of connections from last_planet
    unsigned int *banned_connections; // array of banned connections that i wont go to and wont get me closer
    int banned_connection_counter; // counts how many banned connections there are
    int previous_num_connections; // number of array connections form last_planet
    unsigned int last_last_planet; // the planet before last_planet
    unsigned int last_planet; // last planet that was crt_planet
    double previous_distance_from_mixer; // needed so i can compare if i am heading in the right direction
    int jumps; // made to see how many jumps were done without actually getting treasure planet
    int jumped_connection; // the number which of which connections was jumped to. i.e. connections[0]
    int distance_checker; // checks if the random teleport has gotten close enough

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
        last_space_hop->last_last_planet = 0;
        last_space_hop->last_planet = 0;
        last_space_hop->jumps = 0;
        last_space_hop->previous_distance_from_mixer = 0.0;
        last_space_hop->jumped_connection = 0;
        last_space_hop->previous_num_connections = 0;
        last_space_hop->distance_checker = 0;
        last_space_hop->banned_connection_counter = 0;

        // dynamically allocates memory and copies connections into previous connections
        last_space_hop->previous_connections = malloc(sizeof(unsigned int)*num_connections);
        last_space_hop->banned_connections = malloc(sizeof(unsigned int)* 50);

    }else{
            last_space_hop = ship_state;
            if (last_space_hop->previous_num_connections !=  num_connections) { // if the size of connections is not the same i reallocate the memory
              last_space_hop->previous_connections = realloc(last_space_hop->previous_connections, sizeof(unsigned int) * num_connections);
            }
            
            printf("My Last Planet's ID was %u\n", last_space_hop->last_planet);
        }


    // test to see if the previous connections were added
    printf("Number of previous Connections %d\n", last_space_hop->previous_num_connections);
    
    if(last_space_hop->previous_num_connections != 0){
        for (int i = 0; i < last_space_hop->previous_num_connections; i++){
            
            printf("Previous Connection: %u\n", last_space_hop->previous_connections[i]);
        }
    }

    ShipAction current_space_hop;
    for (int i = 0; i < num_connections; i++)
    {
        printf("Planet %d ID: %u\n", i+1, connections[i]); // Prints out the id of all the planets in jumping distance
    }

    printf("Connection 0 is %u\n",connections[0]);


    if(distance_from_mixer > 1){
        current_space_hop.next_planet = RAND_PLANET;
    } 
    if(distance_from_mixer < 3 ){
        current_space_hop.next_planet = connections[last_space_hop->jumped_connection];
        last_space_hop->jumped_connection++;
    } else {
        last_space_hop->jumped_connection++;}
    if(distance_from_mixer > last_space_hop->previous_distance_from_mixer){
        current_space_hop.next_planet = last_space_hop->last_planet; // FUCK GO BACK IF YOU GOT FARTHER FROM THE TREASURE
        last_space_hop->banned_connections[last_space_hop->banned_connection_counter]; // adds the planet to banned connections array
        last_space_hop->banned_connection_counter++;
    } else if(last_space_hop->last_last_planet == crt_planet){
        current_space_hop.next_planet = connections[last_space_hop->jumped_connection];
        last_space_hop->jumped_connection++;
    } else if(last_space_hop->jumped_connection >= num_connections){
        current_space_hop.next_planet = RAND_PLANET;
    }
    
    printf("This is jump %d\n", last_space_hop->jumps);
        last_space_hop->jumps++;
    
    for (int i = 0; i < num_connections; i++) {
        last_space_hop->previous_connections[i] = connections[i];
    }
    last_space_hop->last_last_planet = last_space_hop->last_planet;
    last_space_hop->last_planet = crt_planet; // moves current planet to last planet
    last_space_hop->previous_num_connections = num_connections; // Sets number of connections to the last connections
    last_space_hop->previous_distance_from_mixer = distance_from_mixer; // moves distnace form mixer to previous distnace from mixer
    current_space_hop.ship_state = last_space_hop;
    return current_space_hop;
} 
