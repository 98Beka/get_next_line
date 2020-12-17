#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
    int fd;
    int i;
   char *line;

   i = 0;
    fd = open("/Users/ehande/Desktop/gnl/t2.txt", O_RDONLY);
    get_next_line(fd, &line);
       printf("%d %s\n", i, line);
       /* while(get_next_line(fd, &line)) {
            i++;
            printf("%d %s\n", i, line);
            free(line);
        }*/
}
