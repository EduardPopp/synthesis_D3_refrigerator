/*
** EPITECH PROJECT, 2021
** synthesis_D3_refrigerator
** File description:
** main
*/

#include "../include/helper.h"
#include "../include/my.h"

llist_t *generate_list(llist_t *fridge, char **itemchain)
{
    int control = 0;

    for (int i = 0; itemchain[i] != NULL; i++) {
        if (strcmp(itemchain[i], "=") == 0) {
            i++;
            continue;
        }
        control = new_node(fridge, itemchain, i);
        if (control == -1)
            return NULL;
    }
    return (fridge);
}

void check_itemchain(char **itemchain)
{
    if (strcmp(itemchain[0], "tomato") != 0 \
    || strcmp(itemchain[3], "dough") != 0 || \
    strcmp(itemchain[6], "onion") != 0 || strcmp(itemchain[9], "pasta") != 0 \
    || strcmp(itemchain[12], "olive") != 0 || \
    strcmp(itemchain[15], "pepper") != 0 || strcmp(itemchain[18], "ham") != 0 \
    || strcmp(itemchain[21], "cheese") != 0) {
        exit(84);
    }
    for (int i = 0; itemchain[i] != NULL; i++) {
        if (itemchain[i][0] == ' ') {
            exit(84);
        }
    }
}

void init_savefile(FILE *savefile)
{
    savefile = fopen(".save", "w+");
    fprintf(savefile, "%s = %s\n", "tomato", "50");
    fprintf(savefile, "%s = %s\n", "dough", "50");
    fprintf(savefile, "%s = %s\n", "onion", "50");
    fprintf(savefile, "%s = %s\n", "pasta", "50");
    fprintf(savefile, "%s = %s\n", "olive", "50");
    fprintf(savefile, "%s = %s\n", "pepper", "50");
    fprintf(savefile, "%s = %s\n", "ham", "50");
    fprintf(savefile, "%s = %s\n", "cheese", "50");
    fclose(savefile);
}

char **savefile_handler(llist_t *fridge, char *buffer, char **itemchain)
{
    FILE *savefile = NULL;

    savefile = fopen(".save", "r");
    if (savefile == NULL) {
        init_savefile(savefile);
        buffer = read_file();
        itemchain = my_str_to_word_array(buffer, ' ', 0);
        generate_list(fridge, itemchain);
    } else {
        buffer = read_file();
        itemchain = my_str_to_word_array(buffer, ' ', 0);
        check_itemchain(itemchain);
        generate_list(fridge, itemchain);
        fclose(savefile);
    }
    free(buffer);
    return itemchain;
}

int main(void)
{
    llist_t *fridge = create_list();
    char *buffer = NULL;
    char **itemchain = NULL;
    char *commandstring = "disp fridge;addToFridge;make;exit";
    char **command_array = my_str_to_word_array(commandstring, ';', 0);
    int loopstate = 1;

    itemchain = savefile_handler(fridge, buffer, itemchain);
    fridge_loop(fridge, loopstate, command_array);
    free_items(itemchain);
    list_free(fridge, command_array);
}