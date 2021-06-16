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