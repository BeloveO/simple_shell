#include "main.h"
/**
 * execcmd - main function
 * @argv: is argument vector
 * Return: Nothing
 */
void execcmd(char **argv){
    char *cmd = NULL;

    if (argv){
        /* get the cmd */
        cmd = argv[0];

        /* generate the path to this cmd before passing it to execve */
        /* real_cmd = getpath(cmd); */

        /* execute the real cmd with execve */
        if (execve(cmd, argv, NULL) == -1){
            perror("./shell");
        }
    }

}
