#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining input buffer

typedef struct 
{
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
    /* data */
} InputBuffer;

InputBuffer* new_input_buffer()
{
    InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;

    return input_buffer;
}

// Defining a prompt to the user. 

void print_prompt() {printf("db >");}

// Reading each line of the user input

ssize_t getline(char **lineptr, size_t *n, FILE *stream); // Read an entire line from a stream

/*
lineptr : pointer to the variable we use point to the buffer containing the read line
n : A pointer to the variable we use to save the size of allocated buffer
steam: the input stream to read from
*/

void read_input(InputBuffer* input_buffer)
{
    ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

    if(bytes_read <= 0)
    {
        printf("Error reading user input\n");
        exit(EXIT_FAILURE);
    }


    // Ignore trailing newline
    input_buffer->input_length = bytes_read -1;
    input_buffer->buffer[bytes_read -1 ] = 0;
}


// Free memory

void close_input_buffer(InputBuffer* input_buffer) {
    free(input_buffer->buffer);
    free(input_buffer);
}

int main(int argc, char* argv[]) {
  InputBuffer* input_buffer = new_input_buffer();
  while (true) {
    print_prompt();
    read_input(input_buffer);

    if (strcmp(input_buffer->buffer, ".exit") == 0) {
      close_input_buffer(input_buffer);
      exit(EXIT_SUCCESS);
    } else {
      printf("Unrecognized command '%s'.\n", input_buffer->buffer);
    }
  }
}