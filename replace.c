void	*ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
	}
	return (NULL);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)ft_malloc(sizeof(char), (s1_len + s2_len + 1));
	ft_strlcpy(ret, s1, s1_len + 1);
	ft_strlcpy(ret + s1_len, s2, s2_len + 1);
	free(s1);
	return (ret);
}

void	delete_argv(t_cmd *cmd, int *i)
{
	int		tmp;

	tmp = *i;
	cmd->argv[tmp] = ft_free(cmd->argv[tmp]);
	while (tmp < cmd->argc - 1)
	{
		cmd->argv[tmp] = cmd->argv[tmp + 1];
		tmp++;
	}
	*i = *i - 1;
	cmd->argc = cmd->argc - 1;
	cmd->is_dollar = false;
	cmd->argv[tmp] = 0;
}

void	argv_change(t_cmd *cmd, char *new, int i)
{
	cmd->argv[i] = ft_free(cmd->argv[i]);
	cmd->argv[i] = new;
}

int	parse_set_quotes(char line, int quotes, t_cmd *cmd)
{
	int	result;

	result = quotes;
	if (line == '$')
		cmd->is_dollar = true;
	if (line == '\'')
	{
		if (quotes == 1)
			result = 0;
		else if (quotes == 2)
			result = 2;
		else
			result = 1;
	}
	else if (line == '\"')
	{
		if (quotes == 2)
			result = 0;
		else if (quotes == 1)
			result = 1;
		else
			result = 2;
	}
	return (result);
}

char	*ft_strjoin_char(char *s1, char s2)
{
	char	*ret;
	size_t	s1_len;

	if (!s1 && !s2)
	{
		return (0);
	}
	else if (!s1)
	{
		return (ft_strdup(&s2));
	}
	s1_len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (s1_len + 2));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, s1_len + 1);
	ft_strlcpy(ret + s1_len, &s2, 2);
	free(s1);
	return (ret);
}

static char	*replace_while_dollar(char str, char *new, t_env *head, int quotes)
{
	static char	*env = NULL;

	if (ft_isalnum(str) || str == '_')
		env = ft_strjoin_char(env, str);
	else if (str == '?' && env == NULL)
	{
		env = ft_itoa(g_exit_code);
		new = ft_strjoin_free(new, env);
		env = ft_free(env);
	}
	else
	{
		if (env != NULL)
		{
			new = ft_strjoin_free(new, ft_getenv(head, env));
			if (!(str == '\"' && quotes != 1) && !(str == '\'' && quotes != 2))
				new = ft_strjoin_char(new, str);
			env = ft_free(env);
			g_exit_code = 0;
		}
		else
			new = ft_strjoin_char(new, '$');
	}
	return (new);
}

static char	*replace_while_else(char c, char *new, int quotes)
{
	char	*result;

	result = NULL;
	if (c == -32)
		result = ft_strjoin_char(new, ' ');
	else if (!(c == '\"' && quotes != 1) && !(c == '\'' && quotes != 2))
	{
		result = ft_strjoin_char(new, c);
	}
	else
	{
		return (new);
	}
	return (result);
}

static int	dollar_check(char c)
{
	if (ft_isalnum(c) || c == '_' || c == '$')
		return (1);
	else
		return (0);
}

static char	*replace_while(t_cmd *cmd, t_env *head, int i)
{
	int		j;
	char	*new;
	int		dollar;
	int		quotes;

	quotes = 0;
	dollar = 0;
	j = 0;
	new = NULL;
	while (j <= (int)ft_strlen(cmd->argv[i]))
	{
		quotes = parse_set_quotes(cmd->argv[i][j], quotes, cmd);
		if (cmd->argv[i][j] == '$' && quotes != 1 && dollar == 0)
			dollar = 1;
		else if (dollar == 1)
		{
			new = replace_while_dollar(cmd->argv[i][j], new, head, quotes);
			dollar = dollar_check(cmd->argv[i][j]);
		}
		else
			new = replace_while_else(cmd->argv[i][j], new, quotes);
		j++;
	}
	return (new);
}

void	replace(t_cmd *cmd, t_env *head)
{
	int		i;
	char	*new;

	while (cmd)
	{
		i = 0;
		while (i < cmd->argc)
		{
			new = replace_while(cmd, head, i);
			if (new == NULL && cmd->is_dollar)
				delete_argv(cmd, &i);
			else if (new == NULL)
			{
				new = ft_strdup("");
				argv_change(cmd, new, i);
			}
			else
				argv_change(cmd, new, i);
			i++;
		}
		cmd = cmd->next;
	}
}
