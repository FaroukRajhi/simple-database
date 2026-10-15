#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "in_memory.h"
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

void print_prompt() {printf("db > ");}

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

typedef enum
{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT } PrepareResult;

MetaCommandResult do_meta_command(InputBuffer* input_buffer)
{
    if(strcmp(input_buffer->buffer, "exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }else{
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}

typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

typedef struct {
  StatementType type;
  Row row_to_insert; // used by insert statement not more
} Statement;

PrepareResult prepare_statement(InputBuffer* input_buffer,
                                Statement* statement) {
  if (strncmp(input_buffer->buffer, "insert", 6) == 0) {
    statement->type = STATEMENT_INSERT;
    int args_assigned = sscanf(
	input_buffer->buffer, "insert %d %s %s", &(statement->row_to_insert.id),
	statement->row_to_insert.username, statement->row_to_insert.email
	);
    if (args_assigned < 3) {
	return PREPARE_SYNTAX_ERROR;
    }
    return PREPARE_SUCCESS;
  }
  if (strcmp(input_buffer->buffer, "select") == 0) {
    statement->type = STATEMENT_SELECT;
    return PREPARE_SUCCESS;
  }

  return PREPARE_UNRECOGNIZED_STATEMENT;
}


