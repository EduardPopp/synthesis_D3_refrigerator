/*
** EPITECH PROJECT, 2021
** synthesis_D3_refrigerator
** File description:
** fridgeloop_utils
*/

#include "../include/helper.h"
#include "../include/my.h"

int do_display(char *linestr, llist_t *fridge)
{
    if (strcmp(linestr, "disp fridge\n") == 0) {
        display_fridge_content(fridge);
        return 1;
    }
    return 1;
}

int do_exit(char *linestr, llist_t *fridge)
{
    if (strcmp(linestr, "exit\n") == 0){
        exit_command(fridge);
        return 0;
    }
    return 1;
}

int check_for_invalid_commands(char *linestr)
{
    char *displaystr = NULL;
    int len = my_strlen(linestr) - 1;

    if (strcmp(linestr, "disp fridge\n") != 0 && \
    strcmp(linestr, "exit\n") != 0 && strncmp(linestr, "addToFridge", 7) != 0 \
    && strncmp("make", linestr, 3) != 0) {
        displaystr = strdup(linestr);
        displaystr[len] = '\0';
        printf("'%s': Invalid operation\n", displaystr);
    }
    free(displaystr);
    return 1;
}

void free_input(char **inputarray)
{
    for (int i = 0; inputarray[i] != NULL; i++) {
    free(inputarray[i]);
    }
    free(inputarray);
}

void low(char *linestr, char *itemname)
{
    int len = my_strlen(linestr) - 1;
    char *displaystr = NULL;

    displaystr = strdup(linestr);
    displaystr[len] = '\0';
    printf("'%s': not enough %s\n", displaystr, itemname);
    free(displaystr);
}