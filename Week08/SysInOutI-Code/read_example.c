#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>
#include <sysexits.h>

#define LENGTH 9

int main(void) {
   int fd;
   char buf[LENGTH];  /* Buffer for our data */
   ssize_t bytes_read; /* Notice the type ssize_t (compare against size_t) */

   /* O_RDONLY - read only */
   fd = open("message.txt", O_RDONLY);   /* fd has the file descriptor */
   if (fd == -1) { /* operation failed */
      err(EX_OSERR,"Cannot open file");
   } else { /* operation successful */
      int i;
      bytes_read = read(fd, buf, LENGTH); /* Reading LENGTH bytes from the file */
      if (bytes_read != LENGTH) { /* LENGTH bytes were NOT read */
         err(EX_OSERR, "Problem reading data");
      }
      for (i = 0; i < LENGTH; i++) { /* Needed as we don't have a strnig */
         printf("%c", buf[i]);
      }
   }

   if (close(fd) == -1) {
      err(EX_OSERR, "Closing file failed");
   } 

   return 0;
}
