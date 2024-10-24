#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/***** ***** ***** ***** ***** MACROS ***** ***** ***** ***** *****/

// Macro to check if a condition is true and jump to a label if it is not
#define ASSERT_TRUE(call, label) do {   \
  /* Evaluate the condition */          \
  int result = (call);                  \
                                        \
  /* Check if the condition is false */ \
  if (!result) {                        \
    /* Jump to the specified label */   \
    goto label;                         \
  }                                     \
} while (0)

// Macro to check if a condition is false and jump to a label if it is not
#define ASSERT_FALSE(call, label) do { \
  /* Evaluate the condition */         \
  int result = (call);                 \
                                       \
  /* Check if the condition is true */ \
  if (result) {                        \
    /* Jump to the specified label */  \
    goto label;                        \
  }                                    \
} while (0)

// Macro to check if there is a next argument
#define HAS_NEXT_ARG (i + 1 < argc)

// Macro to check if the current argument matches the given string
#define IS_OPTION(arg) (strcmp(argv[i], (arg)) == 0)

// Macro to safely free a pointer and set it to NULL
#define SAFE_FREE(ptr) do {     \
  /* Free the memory */         \
  free(ptr);                    \
                                \
  /* Set the pointer to NULL */ \
  ptr = NULL;                   \
} while (0)

/***** ***** ***** ***** ***** FUNCTIONS ***** ***** ***** ***** *****/

void * library_open(const char * filename);
void * library_proc(void * handle, const char * symbol);
int library_close(void * handle);

bool parse_ulong(const char *arg, unsigned long *value);
bool parse_ulong_array(const char *arg, const char *delimiter, const size_t max_count, unsigned long *values, size_t *count);
