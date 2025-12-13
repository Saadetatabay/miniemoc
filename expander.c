#include "minishell.h"

void	expander(t_token **token_list, t_env *env_list)
{
	t_token	*token;
	token = *token_list;
	while (token)
	{
		if (token->type == WORD && ft_strchr(token->value,'$'))
		{
			expand_token(token, env_list);
		}
		token = token->next;
	}
}

void	expand_token(t_token *token, t_env *env_list)
{
	int	i;
	int	single_quote;
	int	double_quote;
	char	*name;
	char	*value;
	char	*new_deger;

	i = 0;
	single_quote = 0;
	double_quote = 0;
	while (token->value[i])
	{
		if (token->value[i] == '\'' && double_quote == 0)
			single_quote = !single_quote;
		else if (token->value[i] == '"' && single_quote == 0)
			double_quote = !double_quote;
		else if (token->value[i] == '$' && single_quote == 0)
		{
			name = var_name(&token->value[i + 1]);
			value = get_env_value(name, env_list);
			new_deger = replace_string(token->value, i,ft_strlen(name), ft_strlen(value));
			token->value = new_deger;
		}
		i++;
	}
}

char	*var_name(char *s)
{
	int i;

	i = 0;
	if (s[0] == '?')
		return (ft_strdup("?"));
	if (ft_isdigit(s[0]))
		return (ft_substr(s, 0, 1));
	while (s[i] && (ft_isalnum(s[i]) || s[i] == '_'))
		i++;
	return (ft_substr(s, 0,i));
}