#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "photo_album.h"
#include "my_memory_checker_216.h"

int main() {
   Album album;

   initialize_album(&album);
   add_photo_to_album(&album, 1, "In the park"); 
   add_photo_to_album(&album, 2, "At home"); 
   print_album(&album);
   destroy_album(&album);

   return EXIT_SUCCESS;
}
