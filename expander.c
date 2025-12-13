#include "minishell.h"

void	expander(t_token **token_list, t_env *env_list)
{
	t_token	*temp;
	temp = *token_list;
	while (temp)
	{
		if (temp->type == WORD && ft_strchr(temp->value,'$'))
		{
			expand_token(temp, env_list);
		}
		temp = temp->next;
	}
}