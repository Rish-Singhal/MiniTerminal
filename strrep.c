#include "library.h"
#include "func.h"

char *replace_str(char *str, char *orig, char *rep)
{
  static char buffer[4096];
  char *p;

  if(!(p = strstr(str, orig))) 
    return str;

  strncpy(buffer, str, p-str); 

  sprintf(buffer+(p-str), "%s%s", rep, p+strlen(orig));

  return buffer;
}
