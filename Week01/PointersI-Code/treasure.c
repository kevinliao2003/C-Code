#include <stdio.h>

/*
 * Everything is C is passed by value.  
 *
 */

/* Prototypes */
void first_pirate(int *mapf, int how_much_to_take);
void second_pirate(int *mapf);

/* Would it make a difference if we change mapf to map? */
void first_pirate(int *mapf, int how_much_to_take) {
   *mapf = *mapf - how_much_to_take; 
   printf("First pirate took %d and left %d\n", *mapf, how_much_to_take); 
}

/* Would it make a difference if we change mapf to map? */
void second_pirate(int *mapf) {
   int took = *mapf / 3; 
   
   *mapf -= took;
   printf("Second pirate took %d and left %d\n", took, *mapf); 
}

int main() {
   int treasure = 100, how_much_to_take = 20;
   int *map = &treasure;
 
   first_pirate(map, how_much_to_take);
   printf("How much left of the treasure after first pirate: %d\n\n", treasure);

   second_pirate(map);
   printf("How much left of the treasure after second pirate: %d\n", treasure);

   return 0;
}
