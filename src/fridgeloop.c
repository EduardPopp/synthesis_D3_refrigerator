/*
** EPITECH PROJECT, 2021
** synthesis_D3_refrigerator
** File description:
** fridgeloop
*/

#include "../include/helper.h"
#include "../include/my.h"

int get_input(llist_t *fridge, char **command_array)
{
    char *linestr = NULL;
    size_t len = 0;
    int nread = 0;
    char **inputarray = NULL;

    nread = getline(&linestr, &len, stdin);
    if (nread == -1)
        exit(84);
    if (strcmp(linestr, command_array[0]) == 0)
        display_fridge_content(fridge);
    //if (strcmp(inputarray[0], command_array[1]) == 0)
        //add_items_to_fridge(linestr, fridge);
    //if (strcmp(inputarray[0], command_array[2]) == 0)
        //make_meal(linestr, fridge);
    if (strcmp(linestr, "exit\n") == 0){
        exit_command(fridge);
        free(linestr);
        return 0;
    }
    //check_for_invalid_commands(linestr, command_array, fridge);
    free(linestr);
}

void fridge_loop(llist_t *fridge, int loopstate, char **command_array)
{
    while (loopstate == 1) {
        loopstate = get_input(fridge, command_array);
    }
}
