/*
** EPITECH PROJECT, 2020
** helper.h
** File description:
** header file containing prototypes and definitions from all project files
*/

#ifndef HELPER_H_
#define HELPER_H_

typedef struct linked_list {
    struct linked_list *next;
    struct linked_list *prev;
    char *item;
    int quantity;
    int size;
} llist_t;

char **my_str_to_word_array(char *str, char sep, int in_word);

llist_t *create_list(void);

int new_node(llist_t *list, char **itemchain, int i);

void exit_command(llist_t *fridge);

void display_fridge_content(llist_t *fridge);

void fridge_loop(llist_t *fridge, int loopstate, char **command_array);

int count_words(char *str, char sep);

#endif /* !HELPER_H_ */
