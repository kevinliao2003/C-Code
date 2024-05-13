/*
Name: Kevin Liap
UID: 117815542
Directory ID: kliao
*/

#include <stdio.h>
#include <string.h>
#include <sysexits.h> 
#include <stdlib.h>
#include <ctype.h>
#include "document.h"

#define MAX_LEN 80
/* Maximum # of characters for a line in a file */
#define MAX_LINE 1024

static int valid_line(char line[MAX_LINE + 1]);
static char* get_target(char line[MAX_LINE + 1]);
static char* get_replacement(char line[MAX_LINE + 1]);

/* COMPILE document.c and user_interface.c together 
    Using %s with sscanf will NOT read a string with spaces */

int main(int argc, char *argv[]) {
    FILE *input;
    /* substr - a substring */
    char filename[MAX_LEN + 1] = "", line[MAX_LINE + 1] = "", 
    command[MAX_LINE + 1] = "", target[MAX_LEN + 1] = "", 
    replacement[MAX_LEN + 1] = "", *substr, last_char = ' ';
    int entries_read = 0, paragraph_number = 0, line_number = 0;
    Document doc;
    init_document(&doc, "main_document"); /* Document initialized */

    if (argc == 1) { /* If a file was NOT provided */
        input = stdin; /* Standard input */
    } else if (argc == 2) { /* A file was provided */
        input = fopen(argv[1], "r");
        if (input == NULL) {
            fprintf(stderr, "FILENAME cannot be opened.\n");
            exit(EX_OSERR);
        }
    } else { /* An invalid # of arguments were provided */
        fprintf(stderr, "Usage: user_interface\n");
        fprintf(stderr, "Usage: user_interface <filename>");
        exit(EX_USAGE);
    }

    /* Commands are entered */
    while (fgets(line, MAX_LINE + 1, input) != NULL) { /* Reads next line */
        if (input == stdin) {
            fprintf(stdout, "> "); /* Prints out > */
        }

        /* Checks if a line is valid */
        if (valid_line(line) == 0) {
            printf("Invalid Command\n");
            continue;
        } else if (valid_line(line) == 2 || valid_line(line) == 3) {
            continue;
        }

        /* Reads the command from the line - IGNORES WHITE SPACE */
        sscanf(line, "%s", command);

        /* Executes the commands accordingly */
        if (strcmp(command, "add_paragraph_after") == 0) {
            entries_read = sscanf(line, "%s %d %c", command, 
            &paragraph_number, &last_char);            

            /* If paragraph number is missing, OR
            last_char ISN'T \0, there is additional data */
            if (entries_read < 2 || entries_read == 3 || 
            paragraph_number < 0) {
                fprintf(stdout, "Invalid Command\n");
            } else if (add_paragraph_after(&doc, paragraph_number) 
                        == FAILURE) {
                fprintf(stdout, "add_paragraph_after failed\n");
            }

            /* Reinitializes last_char */
            last_char = '\0';
        } else if (strcmp(command, "add_line_after") == 0) {
            entries_read = sscanf(line, "%s %d %d", command,
            &paragraph_number, &line_number);

            /* Invalid paragraph_number or line_number 
                or missing * */
            if (entries_read != 3 || paragraph_number <= 0 
                || line_number < 0 || strstr(line, "*") == NULL) {
                fprintf(stdout, "Invalid Command\n");
            } else {
                substr = strstr(line, "*");
                /* Increments the pointer to remove * */
                substr = substr + 1;
                if (add_line_after(&doc, paragraph_number, 
                line_number, substr) == FAILURE) {
                    fprintf(stdout, "add_line_after failed\n");
                }
            }
        } else if (strcmp(command, "print_document") == 0) {
            entries_read = sscanf(line, "%s %c", command, &last_char);
            
            /* Checks if there is anything after print_document */
            if (entries_read == 2) {
                fprintf(stdout, "Invalid Command\n");
            } else {
                print_document(&doc); /* Document printed */
            }

            /* Reinitializes last_char */
            last_char = '\0';
        } else if (strcmp(command, "quit") == 0) {
            entries_read = sscanf(line, "%s %c", command, &last_char);

            /* Checks if there is anything after quit */
            if (entries_read == 2) {
                fprintf(stdout, "Invalid Command\n");
            } else {
                exit(EXIT_SUCCESS); /* User interface exited */
            }

            /* Reinitializes last_char */
            last_char = '\0';
        } else if (strcmp(command, "exit") == 0) {
            entries_read = sscanf(line, "%s %c", command, &last_char);

            /* Checks if there is anything after exit */
            if (entries_read == 2) {
                fprintf(stdout, "Invalid Command\n");
            } else {
                exit(EXIT_SUCCESS); /* User interface exited */
            }

            /* Reinitializes last_char */
            last_char = '\0';
        } else if (strcmp(command, "append_line") == 0) {
            entries_read = sscanf(line, "%s %d", command,
            &paragraph_number);

            if (entries_read != 2 || paragraph_number <= 0 ||
                strstr(line, "*") == NULL) {
                fprintf(stdout, "Invalid Command\n");
            } else {
                substr = strstr(line, "*");
                /* Increments the pointer to remove * */
                substr = substr + 1;
                if (append_line(&doc, paragraph_number, 
                    substr) == FAILURE) {
                    fprintf(stdout, "append_line failed\n");
                }
            }
        } else if (strcmp(command, "remove_line") == 0) {
            entries_read = sscanf(line, "%s %d %d %c", command,
            &paragraph_number, &line_number, &last_char);

            /* Checks for missing fields and additional data */
            if (entries_read < 3 || entries_read == 4 
                || paragraph_number <= 0 || line_number <= 0) {
                fprintf(stdout, "Invalid Command\n");
            } else if (remove_line(&doc, paragraph_number, 
            line_number) == FAILURE) {
                fprintf(stdout, "remove_line failed\n");
            }

            /* Reinitializes last_char */
            last_char = '\0';
        } else if (strcmp(command, "load_file") == 0) {
            entries_read = sscanf(line, "%s %s %c", command, 
                filename, &last_char);

            /* Checks for missing fields and additional data */
            if (entries_read < 2 || entries_read == 3) {
                fprintf(stdout, "Invalid Command\n");
            } else if (load_file(&doc, filename) == FAILURE) {
                fprintf(stdout, "load_file failed\n");
            }

            /* Reinitializes last_char */
            last_char = '\0';
        } else if (strcmp(command, "replace_text") == 0) {
	        /* Missing target or replacement 
            - NO DATA AFTER REPLACEMENT */ 
	        if (get_target(line) == NULL ||  
	            get_replacement(line) == NULL) { 
	            fprintf(stdout, "Invalid Command\n"); 
	        } else {
                strcpy(target, get_target(line)); 
	            strcpy(replacement, get_replacement(line));
                if (replace_text(&doc, target, replacement)  
	                == FAILURE) {
                    fprintf(stdout, "replace_text failed\n");
                } 
	        }

            /* Reinitializes target and replacement */
            target[0] = '\0';
            replacement[0] = '\0';
        } else if (strcmp(command, "highlight_text") == 0) {
            entries_read = sscanf(line, "%s %s", command, target);

            /* Missing target - NO DATA AFTER TARGET */
            if (entries_read < 2) {
                fprintf(stdout, "Invalid Command\n");
            } else {
                strcpy(target, get_target(line));
                highlight_text(&doc, target);

                /* Reinitializes target */
                target[0] = '\0';
            }
        } else if (strcmp(command, "remove_text") == 0) {
            entries_read = sscanf(line, "%s %s", command, target);

            /* Missing target - NO DATA AFTER TARGET */
            if (entries_read < 2) {
                fprintf(stdout, "Invalid Command\n");
            } else {
                strcpy(target, get_target(line));
                remove_text(&doc, target);
                
                /* Reinitializes target */
                target[0] = '\0';
            }
        } else if (strcmp(command, "save_document") == 0) {
            entries_read = sscanf(line, "%s %s %c", command, 
                filename, &last_char);

            /* Checks for missing fields and additional data */
            if (entries_read < 2 || entries_read == 3) {
                fprintf(stdout, "Invalid Command\n");
            } else {
                if (save_document(&doc, filename)
                    == FAILURE) {
                    fprintf(stdout, "save_document failed\n");
                }
            }

            /* Reinitializes last_char */
            last_char = '\0';
        } else if (strcmp(command, "reset_document") == 0) {
            entries_read = sscanf(line, "%s %c", command, &last_char);

            /* Checks if there is anything after reset_document */
            if (entries_read == 2) {
                fprintf(stdout, "Invalid Command\n");
            } else {
                reset_document(&doc);
            }

            /* Reinitializes last_char */
            last_char = '\0';
        }
    }

    return 0;
}

/* Determines if a line in a file is valid 
    3 - comment, 2 - blank line, 1 - command, 0 - invalid line */
static int valid_line(char line[MAX_LINE + 1]) {
    /* blanks - # of blank spaces, non_blanks - # of non-blank spaces */
    int non_blanks = 0;
    while (*line != '\0') {
        if (!isspace(*line)) {
            non_blanks++;
        }

        /* Checks for a comment */
        if (non_blanks == 1 && *line == '#') {
            return 3;
        }
        line = line + 1;
    }

    /* Checks for a blank line */
    if (non_blanks == 0) {
        return 2;
    } else if (non_blanks > 0) { /* Checks for a command */
        return 1;
    } else { /* Invalid line */
        return 0;
    }
}

/* Returns the target in a line */
static char* get_target(char line[MAX_LINE + 1]) {
    int length = 0; /* Length of line */
    /* first, second quotation 
    Reinitializes target */
    char *first, *second, target[MAX_LINE + 1] = "";

    first = strstr(line, "\""); /* \* FOR QUOTATION MARKS */
    if (first == NULL) { /* If there is NO target */
        return NULL;
    }

    first = first + 1;
    second = strstr(first, "\"");
    /* # of characters between 1st and 2nd quotations */
    length = second - first;

    /* Finds the target string */
    strncpy(target, first, length); /* SEG FAULT */
    return target;
}

/* Returns the replacement in a line */
static char* get_replacement(char line[MAX_LINE + 1]) {
    int length = 0; /* Length of line */
    /* first, second, third, and fourth quotation */
    char *first, *second, *third, *fourth, 
        replacement[MAX_LINE + 1] = ""; /* Reinitializes replacement */

    first = strstr(line, "\"");
    if (first == NULL) { /* If there are NO quotation marks */
        return NULL;
    }
    
    first = first + 1;
    second = strstr(first, "\"");
    second = second + 1;
    third = strstr(second, "\"");
    if (third == NULL) { /* If there is NO replacement */
        return NULL;
    }

    third = third + 1;
    fourth = strstr(third, "\"");
    /* # of characters between 3rd and 4th quotations */
    length = fourth - third;

    /* For replacement, 3rd and 4th quotations are used */
    /* Finds the target string */
    strncpy(replacement, third, length);
    return replacement;
}