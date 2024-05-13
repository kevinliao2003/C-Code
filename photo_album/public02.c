#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "photo_album.h"
#include "my_memory_checker_216.h"

int main() {
   Album album;

   initialize_album(&album);
   print_album(&album);
   destroy_album(&album);

   return EXIT_SUCCESS;
}
