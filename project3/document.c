/*
Name: Kevin Liap
UID: 117815542
Directory ID: kliao
*/

#include <stdio.h>
#include <string.h>
#include "document.h"

/* Maximum # of characters for a line in a file */
#define MAX_LINE 1024

static char* replace_in_line(const char *target, const char *replacement, 
                             char *line);
static char* highlight_line(const char *target, char *line);
int load_file(Document *doc, const char *filename);
int save_document(Document *doc, const char *filename);
static int blank_line(char *line);

/* Initializes the document to be empty and initializes the name 
   with the parameter value */
int init_document(Document *doc, const char *name) {
    /* if doc is NULL, name is NULL, or if the length of the name 
       provided exceeds MAX_STR_SIZE */
    if (doc == NULL || name == NULL || (int)strlen(name) > MAX_STR_SIZE) {
        return FAILURE;
    } else {
        strcpy(doc->name, name); /* Strings cannot be reassigned */
        doc->number_of_paragraphs = 0;
        return SUCCESS;
    }
}

/* Sets the # of paragraphs to 0 */
int reset_document(Document *doc) {
    if (doc == NULL) {
        return FAILURE;
    } else {
        doc->number_of_paragraphs = 0;
        return SUCCESS;
    }
}

/* Prints the document’s name, number of paragraphs, 
   followed by the paragraphs. */
int print_document(Document *doc) {
    if (doc == NULL) {
        return FAILURE;
    } else {
        char *name = doc->name;
        int number_of_paragraphs = doc->number_of_paragraphs;
        int paragraph;

        printf("Document name: \"%s\"\n", name);
        printf("Number of Paragraphs: %d", number_of_paragraphs);

        /* Prints out the paragraphs */
        /* Loops through the paragraphs */
        for (paragraph = 0; paragraph < number_of_paragraphs; paragraph++) {
            int number_of_lines = doc->paragraphs[paragraph].number_of_lines;
            int line_num;

            printf("\n");
            /* Loops through the lines */
            for (line_num = 0; line_num < number_of_lines; line_num++) {
                char *line = doc->paragraphs[paragraph].lines[line_num];
                printf("%s", line); /* Space automaticlly printed after */
            }
        }

        return SUCCESS;
    }
}

/* Adds a paragraph after the specified paragraph number.
   There is no need to initialize the lines array when a paragraph is added. 
   There will be garbage in the lines array. */
int add_paragraph_after(Document *doc, int paragraph_number) {
    /* Also checks if paragraph_number is negative */
    if (doc == NULL || doc->number_of_paragraphs >= MAX_PARAGRAPHS
        || paragraph_number < 0
        || paragraph_number > doc->number_of_paragraphs) {
            return FAILURE;
    } else {
        int index; /* Index of lines */ 
        /* # of paragraphs increased by 1 */
	    doc->number_of_paragraphs += 1; 
	 
	    /* Shifts paragraphs down by 1 */ 
	    for (index = doc->number_of_paragraphs - 1; index > 
             paragraph_number; index--) { 
	        doc->paragraphs[index] = doc->paragraphs[index - 1]; 
	    } 
	    /* Initializes the dimensions of the new paragraph */ 
	    doc->paragraphs[paragraph_number].number_of_lines = 0; 
	 
	    return SUCCESS;
    }
}

/* Adds a new line after the line with the specified line number */
int add_line_after(Document *doc, int paragraph_number, int line_number,
		   const char *new_line) {
    /* Also checks if paragraph_number or line_number is negative */
    if (doc == NULL || paragraph_number > doc->number_of_paragraphs 
    || doc->paragraphs[paragraph_number - 1].number_of_lines 
       >= MAX_PARAGRAPH_LINES
    || paragraph_number < 0
    || line_number > doc->paragraphs[paragraph_number - 1].number_of_lines
    || line_number < 0
    || new_line == NULL) {
        return FAILURE;
    } else {
        int index; /* Index of lines */
        Paragraph *paragraph = &doc->paragraphs[paragraph_number - 1];

        /* # of lines for the paragraph increased by 1 */
        paragraph->number_of_lines += 1;

        /* Preceding lines shifted right */
        for (index = paragraph->number_of_lines - 1; index > line_number;
             index--) {
            strcpy(paragraph->lines[index], "");
            strcpy(paragraph->lines[index], paragraph->lines[index - 1]);
        }
        /* Adds the line to the paragraph */
        strcpy(paragraph->lines[line_number], new_line);

        return SUCCESS;
    }
}

/* Returns the number of lines in a paragraph using the 
   number of lines out parameter */
int get_number_lines_paragraph(Document *doc, int paragraph_number, 
                               int *number_of_lines) {
    /* Also checks if paragraph_number is negative */
    if (doc == NULL || number_of_lines == NULL 
        || paragraph_number > doc->number_of_paragraphs
        || paragraph_number < 0) {
        return FAILURE;
    } else {
        *number_of_lines = doc->paragraphs[paragraph_number 
                           - 1].number_of_lines;
        return SUCCESS;
    }
}

/* Appends a line to the specified paragraph */
int append_line(Document *doc, int paragraph_number, const char *new_line) {
    /* # of lines at paragraph_number */
    int num_lines = doc->paragraphs[paragraph_number - 1].number_of_lines;
    return add_line_after(doc, paragraph_number, num_lines, new_line);
}

/* Removes the specified line from the paragraph */
int remove_line(Document *doc, int paragraph_number, int line_number) {
    /* Also checks if paragraph_number and line_number are negative */
    if (doc == NULL || paragraph_number > doc->number_of_paragraphs
    || line_number > doc->paragraphs[paragraph_number - 1].number_of_lines
    || paragraph_number < 0 || line_number < 0) {
        return FAILURE;
    } else {
        /* paragraph - current paragraph */
        Paragraph *paragraph = &doc->paragraphs[paragraph_number - 1];

        /* If the last line is NOT being removed */
        if (line_number != paragraph->number_of_lines) {
            /* Removes the specified line */
            int index;
            for (index = line_number - 1; index < paragraph->number_of_lines 
                 - 1; index++) {
                strcpy(paragraph->lines[index], "");
                strcpy(paragraph->lines[index], paragraph->lines[index + 1]);
                strcpy(paragraph->lines[index + 1], "");
            }
        }

        /* # of lines decreased by 1 */
        paragraph->number_of_lines -= 1;

        return SUCCESS;
    }
}

/* Adds the first data lines number of lines from the 
   data array to the document */
int load_document(Document *doc, char data[][MAX_STR_SIZE + 1], 
                  int data_lines) {
    if (doc == NULL || data == NULL || data_lines == 0) {
        return FAILURE;
    } else {
        int line_num = 0; /* Line number */
        int paragraph_num = 0; /* Paragraph number - initialized to 0 */

        /* The 1st paragraph is created by default */
        char *line = data[line_num];
        /* Paragraph added to front */
        add_paragraph_after(doc, paragraph_num); 
        paragraph_num++;
        /* Line added to the 1st paragraph */
        append_line(doc, paragraph_num, line);

        for (line_num = 1; line_num < data_lines; line_num++) {
            line = data[line_num];
            /* An empty string will create a new paragraph */
            if (strcmp(line, "") == 0) {
                add_paragraph_after(doc, paragraph_num);
                paragraph_num++;
            } else {
                append_line(doc, paragraph_num, line);
            }
        }

        return SUCCESS;
    }
}

/* Replaces the text target with the text replacement everywhere 
   it appears in the document */
int replace_text(Document *doc, const char *target, 
                 const char *replacement) {
    if (doc == NULL || target == NULL || replacement == NULL) {
        return FAILURE;
    } else {
        /* index1 - paragraph index, 
           index2 - line index
           target_length - length of target */
        int index1, index2 = 0, target_length = (int)strlen(target);
        for (index1 = 0; index1 < doc->number_of_paragraphs; index1++) {
            /* Pointer to paragraph */
            Paragraph *paragraph = &doc->paragraphs[index1];

            for (index2 = 0; index2 < paragraph->number_of_lines; index2++) {
                char *line = paragraph->lines[index2];
                /* If the target IS found in the line */
                if (strstr(line, target) != NULL) {
                    char *result = replace_in_line(target, replacement, 
                                                   line);
                    /* line is updated */
                    strcpy(line, "");
                    /* Replaces line with resulting string */
                    strcpy(line, result);
                }
            }
        }

        return SUCCESS;
    }
}

/* Auxiliary function that replaces text within a line */
static char* replace_in_line(const char *target, const char *replacement, 
                      char *line) {
    /* index - character index
       target_length - length of target
       replace_length - length of replacement 
       result - resulting string from replacement */
    int index = 0, target_length = (int)strlen(target), 
    replace_length = (int)strlen(replacement);
    /* Initializes resulting string to empty */
    char result[MAX_STR_SIZE + 1] = "";

    while (*line != '\0') {
        /* If the program is AT the target */
        if (strstr(line, target) == line) {
            /* The replacement string is appended */
            strcat(result, replacement);
            index += replace_length;
            line = line + target_length;
        } else {
            result[index] = *line;
            index++;
            line = line + 1;
        }
    }
    result[index] = '\0'; /* Null character added */

    return result;
}

/* Highlights the text associated with target everywhere it appears 
   in the document by surrounding the text with the strings 
   HIGHLIGHT START STR and HIGHLIGHT END STR */
int highlight_text(Document *doc, const char *target) {
    if (doc == NULL || target == NULL) {
        return FAILURE;
    } else {
        /* index1 - paragraph index, 
           index2 - line index
           target_length - length of target */
        int index1, index2, target_length = (int)strlen(target);
        for (index1 = 0; index1 < doc->number_of_paragraphs; index1++) {
            /* Pointer to paragraph */
            Paragraph *paragraph = &doc->paragraphs[index1];
            for (index2 = 0; index2 < paragraph->number_of_lines; index2++) {
                char *line = paragraph->lines[index2];
                /* If the target IS found in the line */
                if (strstr(line, target) != NULL) {
                    char *result = highlight_line(target, line);
                    /* line is updated */
                    strcpy(line, "");
                    /* Replaces line with resulting string */
                    strcpy(line, result);
                }
            }
        }

        return SUCCESS;
    }
}

static char* highlight_line(const char *target, char *line) {
    /* index - character index
       target_length - length of target 
       result - resulting string from replacement */
    int index = 0, target_length = (int)strlen(target);
    /* Initializes resulting string to empty */
    char result[MAX_STR_SIZE + 1] = "";

    while (*line != '\0') {
        /* If the program is AT the target */
        if (strstr(line, target) == line) {
            /* The target is highlighted */
            strcat(result, HIGHLIGHT_START_STR);
            strcat(result, target);
            strcat(result, HIGHLIGHT_END_STR);
            index += target_length + 2;
            line = line + target_length;
        } else {
            result[index] = *line;
            index++;
            line = line + 1;
        }
    }
    result[index] = '\0'; /* Null character added */

    return result;
}

/* Removes the text target everywhere it appears in the document */
int remove_text(Document *doc, const char *target) {
    if (doc == NULL || target == NULL) {
        return FAILURE;
    } else {
        /* index1 - paragraph index, 
           index2 - line index
           target_length - length of target */
        int index1, index2, target_length = (int)strlen(target);
        for (index1 = 0; index1 < doc->number_of_paragraphs; index1++) {
            /* Pointer to paragraph */
            Paragraph *paragraph = &doc->paragraphs[index1];
            for (index2 = 0; index2 < paragraph->number_of_lines; index2++) {
                char *line = paragraph->lines[index2];
                /* If the target IS found in the line */
                if (strstr(line, target) != NULL) {
                     char *result = replace_in_line(target, "", line);
                     /* If the ENTIRE line will be removed */
                     if (strcmp(result, "") == 0) {
                        remove_line(doc, index1 + 1, index2 + 1);
                     } else {
                        /* line is updated */
                        strcpy(line, "");
                        /* Replaces line with resulting string */
                        strcpy(line, result);
                     }
                }
            }
        }

        return SUCCESS;
    }
}

/* All data will be loaded from a file */
int load_file(Document *doc, const char *filename) {
    if (doc == NULL || filename == NULL || !fopen(filename, "r")) {
        return FAILURE;
    } else {
        FILE *input = fopen(filename, "r"); /* Reads from the file */
        /* data - all lines in file (accounts for largest # of lines 
        and characters), index - data index */
        char *line, data[MAX_PARAGRAPHS * MAX_PARAGRAPH_LINES 
        + MAX_PARAGRAPHS][MAX_LINE + 1], str[MAX_LINE + 1];
        /* index - data index, # of lines in file */
        int index = 0, line_num = 0, paragraph_num = 0;

        /* Reads next line, builds data */
        while (fgets(str, MAX_LINE + 1, input) != NULL) { /* SEG FAULT */
            strcpy(data[index], str);
            index++;
        }

        /* Loads the document - similar to load_document function */
        /* The 1st paragraph is created by default */
        line = data[line_num];
        /* Paragraph added to front */
        add_paragraph_after(doc, paragraph_num); 
        paragraph_num++;
        /* Line added to the 1st paragraph */
        append_line(doc, paragraph_num, line);

        for (line_num = 1; line_num < index; line_num++) {
            line = data[line_num];
            /* An empty string will create a new paragraph,
            ALSO accounts for \n */
            if (blank_line(line) == 1) {
                add_paragraph_after(doc, paragraph_num);
                paragraph_num++;
            } else {
                append_line(doc, paragraph_num, line);
            }
        }

        fclose(input); /* Closes the file */

        return SUCCESS;
    }
}

/* Returns true if a line is blank and false otherwise */
static int blank_line(char *line) {
    if ((int)strlen(line) == 0) { /* Empty string */
        return 1;
    }

    while (*line != '\0') {
        /* The line is NOT blank */
        if (*line != ' ' && *line != '\n') {
            return 0;
        }

        line = line + 1;
    }

    return 1;
}

/* Prints the paragraphs associated with the doc to the specified file */
int save_document(Document *doc, const char *filename) {
    if (doc == NULL || filename == NULL || !fopen(filename, "w")) {
        return FAILURE;
    } else {
        int paragraph, line; /* Paragraph index, line index */
        FILE *input = fopen(filename, "w"); /* Writes to the file */

        /* Loops through all paragraphs */
        for (paragraph = 0; paragraph < doc->number_of_paragraphs; 
            paragraph++) {
            /* # of lines in a paragraph */
            int num_lines = doc->paragraphs[paragraph].number_of_lines;
            /* Loops through all lines */
            for (line = 0; line < num_lines; line++) {
                char *str = doc->paragraphs[paragraph].lines[line];
                fputs(str, input); /* Adds the string to the file */
            }

            /* Each paragraph separated by a new line */
            fputs("\n", input);
        }

        return SUCCESS;
    }
}
