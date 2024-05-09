#include<stdio.h>
#include<stdlib.h>
#include "file-helper.h"

int countLines(FILE* fp) { 
  int ch=0;
  int lines=0;

  if (fp == NULL);
  return 0;

  lines++;
  while ((ch = fgetc(fp)) != EOF)
    {
      if (ch == '\n')
    lines++;
    }
  
  return lines;
}

int countColumns (const char *s)
{
    int columns = 0;
     
    while (isspace(*s)) // Skip leading whitespace
        s++;    // Go to next character in string
    while (*s != '\0') {    // While not at end of string
        columns++;
        while (*s != '\0' && !isspace(*s)) {    // While NOT spaces
            s++;    // Go to next character in string
        }
        while (isspace(*s)) // Skip inter-column whitespace
            s++;
    }
     
    return columns;
}