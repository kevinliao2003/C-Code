#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>

/*
 * Example adapted from the manpage.  Compile with the -rdynamic and -ldl
 * options.
 */

#define PROMPT "\nEnter math library name (e.g., sqrt), CTRL-D to stop: "
#define MAX_LEN 20

typedef double (*Math_fn) (double);

int main() {
   void *handle;
   Math_fn function;
   char function_name[MAX_LEN + 1];      /* An arbitrary length */
   char *error;
   float argument;

   handle = dlopen("libm.so", RTLD_LAZY);
   if (handle == NULL) {
      fprintf(stderr, "%s\n", dlerror());
      exit(1);
   } else {
      printf(PROMPT);
      while (fgets(function_name, MAX_LEN + 1, stdin) != NULL) {
         *strchr(function_name, '\n') = '\0';
         printf("Enter argument to evaluate function upon: ");
         scanf("%f", &argument);
         getchar();             /* skip newline */

         dlerror();             /* clear any existing error */
         function = dlsym(handle, function_name);
         if ((error = dlerror()) != NULL) {
            fprintf(stderr, "%s\n", error);
         } else {
            printf("%s(%.2f) = %f\n", function_name, argument,
                   function(argument));
         }
         printf(PROMPT);
      }
      dlclose(handle);
      printf("\n\n");
   }

   return 0;
}
