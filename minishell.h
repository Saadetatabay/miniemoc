#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

//Token türlerini
typedef enum e_token_type
{
    WORD,       // Komutlar, argümanlar (echo, ls, -l, dosya.txt)
    PIPE,       // |
    REDIRECT_IN, // <
    REDIRECT_OUT, // >
    APPEND,     // >>
    HEREDOC     // <<
} t_token_type;

typedef struct s_token
{
	char			*value; // token içeriği echo mesela
	t_token_type	type;//token türü (WORD)
	struct s_token	*next; //sonraki token
}	t_token;

#endif