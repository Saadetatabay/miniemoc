#include "minishell.h"

void    print_env(t_env *env)
{
    while (env)
    {
        printf("Key: %s | Value: %s\n", env->key, env->value);
        env = env->next;
    }
}