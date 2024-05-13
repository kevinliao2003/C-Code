#include <stdio.h>
#include <stdlib.h>  /* For malloc */
#include <string.h>
#include "photo_album.h"
#include "my_memory_checker_216.h"

/* Compile using gcc my_test1.c photo_album.c my_memory_checker_216.c */

/* Returns a dynamically-allocated Photo structure
initialized based on the provided parameters */
Photo *create_photo(int id, const char *description) {
    /* Memory allocated to Photo structure */
    /* If memory allocation fails */
    Photo *create_photo = malloc(sizeof(Photo));
    if (create_photo == NULL) {
        return NULL;
    }

    /* If description is NOT NULL */
    if (description != NULL) {
        int length = (int)strlen(description);
        create_photo->id = id;
        /* Memory allocated for description */
        /* 1 more char for null character */
        create_photo->description = malloc(length + 1);
        /* Checks if memory allocation was successful */
        if (create_photo->description == NULL) {
            return NULL;
        } else { /* description is copied over */
            strcpy(create_photo->description, description);
        }
    } else {
        /* Still initializes id */
        create_photo->id = id;
        /* If description IS NULL */
        /* description field initialized to NULL */
        create_photo->description = NULL;
    }
    return create_photo;
}

/* Prints a photo id and a description */
void print_photo(Photo *photo) {
    if (photo != NULL) {
        /* If the description is NULL */
        if (photo->description == NULL) {
            printf("Photo ID: %d, Description: None\n", photo->id);
        } else {
            printf("Photo ID: %d, Description: %s\n", photo->id, 
                photo->description);
        }
    }
}

/* Deallocates any dynamically-allocated memory associated with the
photo parameter */
void destroy_photo(Photo *photo) {
    if (photo != NULL) {
        /* NULL memory can't be freed */
        if (photo->description != NULL) {
            free(photo->description);
        }
        free(photo);
    }
}

/* Initializes the album size to 0 */
void initialize_album(Album *album) {
    if (album != NULL) {
        album->size = 0;
    }
}

/* Prints the contents of the album */
void print_album(const Album *album) {
    if (album != NULL) {
        if (album->size == 0) {
            printf("Album has no photos.\n");
        } else {
            int index;
            /* Photos are printed out */
            for (index = 0; index < album->size; index++) {
                print_photo(album->all_photos[index]);
            }
        }
    }
}

/* Deallocates any dynamically-allocated memory associated with
the album and sets the album size to 0 */
void destroy_album(Album *album) {
    if (album != NULL) {
        int index;
        /* Deallocates memory associated with each photo */
        for (index = 0; index < album->size; index++) {
            destroy_photo(album->all_photos[index]);
        }

        album->size = 0;
    }
}

/* Appends (to the end of the array) a photo if there is enough space 
(if the album size is less than MAX ALBUM SIZE) */
void add_photo_to_album(Album *album, int id, const char *description) {
    if (album != NULL) {
        if (album->size < MAX_ALBUM_SIZE) {
            Photo *add_photo = create_photo(id, description);
            if (add_photo != NULL) { /* Checks if the photo was created */
                album->all_photos[album->size] = add_photo;
                album->size++;
            }
        }
    }
}