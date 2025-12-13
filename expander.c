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

void	expand_token(t_token *temp, t_env *env_list)
{

}

char	*var_name(char *s)
{
	int i;

	i = 0;
	if (s[0])
		return (ft_strdup("?"));
	if (ft_isdigit(s[0]))
		return (ft_substr(s, 0, 1));
	while (s[i] && (ft_isalnum(s[i]) || s[i] == '_'))
		i++;
	return (ft_substr(s, 0,i));
}