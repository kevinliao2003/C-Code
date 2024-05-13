#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "photo_album.h"
#include "my_memory_checker_216.h"

int main() {
   Album album, second_album, third_album;
   Photo *photo;

   start_memory_check(); /* Start memory check */

   photo = create_photo(5, NULL);
   print_photo(photo);
   destroy_photo(photo);

   initialize_album(&album);
   add_photo_to_album(&album, -1, NULL); 
   add_photo_to_album(&album, 40, "Car"); 
   add_photo_to_album(&album, 8, "TV"); 
   print_album(&album);
   destroy_album(&album);

   initialize_album(&second_album);
   add_photo_to_album(&second_album, 100, "Shirt"); 
   add_photo_to_album(&second_album, 200, "Pants"); 
   add_photo_to_album(&second_album, 300, "Ties");
   add_photo_to_album(&second_album, 400, "Delicious Food");
   print_album(&second_album);
   destroy_album(&second_album);
   print_album(&second_album);

   initialize_album(&third_album);
   add_photo_to_album(&third_album, 100, NULL);
   print_album(&third_album);
   destroy_album(&third_album);

   stop_memory_check(); /* End memory check */

   return EXIT_SUCCESS;
}