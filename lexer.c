#include "minishell.h"

t_token	*lexer(char	*input)
{
	int		i;
	t_token	*token_list;

	token_list = NULL;
	i = 0;
	while (input[i])
	{
		while (input[i] && (input[i]==' ' || input[i] == '\t'))
			i++;
		if (!input[i])
			break;
		//operatörleri yakalmak için
		if (input[i] == '|' || input[i] == '<' || input[i] == '>')
			i += handle_operator(&token_list, input, i);
		else
		{
			//kelime kısmı
		}
	}
	return (token_list);
}

int	handle_operator(t_token	**token_list, char *input, int i)
{
	t_token_type	type;
	char			*content;

	if (input[i + 1] && input[i]== '<' && input[i + 1] == '<')
	{
		content = ft_strdup("<<");
		type = HEREDOC;
		//TOKEN_LİSTESİNE CONTENTİ EKLEME FUNC GELECEK
		return (2);
	}
	if (input[i + 1] && input[i]== '>' && input[i + 1] == '>')
	{
		content = ft_strdup(">>");
		type = APPEND;
		//TOKEN_LİSTESİNE CONTENTİ EKLEME FUNC GELECEK
		return (2);
	}
	if (input[i] == '<')
        type = REDIRECT_IN;
    else if (input[i] == '>')
        type = REDIRECT_OUT;
    else
        type = PIPE;
	
	content = ft_substr(input, i, 1);
	//FUNC
	return (1);
}