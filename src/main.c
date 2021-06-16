/*
** EPITECH PROJECT, 2021
** synthesis_D3_refrigerator
** File description:
** main
*/

#include "../include/helper.h"
#include "../include/my.h"

char *prepare_buffer(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = ' ';
        }
    }
    return buffer;
}

llist_t *generate_list(llist_t *fridge, char **itemchain)
{
    for (int i = 0; itemchain[i] != NULL; i++) {
        if (strcmp(itemchain[i], "=") == 0) {
            i++;
            continue;
        }
        new_node(fridge, itemchain, i);
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

void check_amount_of_rows(char *buffer)
{
    int count_nl = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            count_nl++;
        }
    }
    if (count_nl != 8)
        exit(84);
}

void check_spacing(char *buffer)
{
    int count_space = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ' ') {
            count_space++;
        }
    }
    if (count_space != 16) {
        exit(84);
    }
}

void check_buffer(char *buffer)
{
    if (buffer == NULL)
        exit(84);
    check_amount_of_rows(buffer);
    check_spacing(buffer);
}

char *read_file(void)
{
    char *buffer = NULL;
    int fd = open(".save", O_RDONLY);
    struct stat st;

    stat(".save", &st);
    buffer = calloc((st.st_size + 1), sizeof(char));
    if (fd < 0) {
        write(2, "File opening failed.\n", 21);
        return NULL;
    }
    read(fd, buffer, st.st_size);
    check_buffer(buffer);
    close(fd);
    buffer = prepare_buffer(buffer);
    return (buffer);
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

void free_items(char **itemchain)
{
    for (int i = 0; itemchain[i] != NULL; i++) {
        free(itemchain[i]);
    }
    free(itemchain);
}

void list_free(llist_t *fridge, char **command_array)
{
    llist_t *cur = fridge->prev;
    llist_t *next;

    for (int i = 0; command_array[i] != NULL; i++) {
        free(command_array[i]);
    }
    free(command_array);
    while (cur != NULL) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    fridge->prev = NULL;
    free(fridge);
}

// void print_list(llist_t *fridge)
// {
//     llist_t *cur = malloc(sizeof(llist_t));

//     for (cur = fridge->prev; cur != NULL; cur = cur->next) {
//         printf("%s = %d\n", cur->item, cur->quantity);
//     }
//     free(cur);
// }

void savefile_handler(llist_t *fridge)
{
    FILE *savefile = NULL;
    char *buffer = NULL;
    char **itemchain = NULL;

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
    }
    //print_list(fridge);
    free_items(itemchain);
    free(buffer);
}

int main(void)
{
    llist_t *fridge = create_list();
    //int len = 33;
    //char *commandstring = calloc((len + 1), sizeof(char));
    char *commandstring = "disp fridge\n;addToFridge\n;make\n;exit\n";
    char **command_array = my_str_to_word_array(commandstring, ';', 0);
    int loopstate = 1;

    for (int i = 0; command_array[i] != NULL; i++) {
        printf("%d - %s", i, command_array[i]);
    }
    savefile_handler(fridge);
    fridge_loop(fridge, loopstate, command_array);
    list_free(fridge, command_array);
    free(commandstring);
}