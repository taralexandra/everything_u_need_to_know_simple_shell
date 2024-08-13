#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s filename ...\n", argv[0]);
        return (1);
    }

    char *path_env = getenv("PATH");
    if (!path_env)
    {
        perror("getenv");
        return (1);
    }

    char *path = strtok(path_env, ":");
    while (path)
    {
        for (int i = 1; i < argc; i++)
        {
            char filepath[1024];
            snprintf(filepath, sizeof(filepath), "%s/%s", path, argv[i]);

            struct stat st;
            if (stat(filepath, &st) == 0)
            {
                printf("%s FOUND\n", filepath);
            }
            else
            {
                printf("%s NOT FOUND\n", filepath);
            }
        }
        path = strtok(NULL, ":");
    }

    return (0);
}

