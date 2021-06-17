/*
** EPITECH PROJECT, 2021
** synthesis_D3_refrigerator
** File description:
** buffer_utils
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