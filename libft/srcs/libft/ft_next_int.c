/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:11:59 by clorcery          #+#    #+#             */
/*   Updated: 2022/09/02 15:52:42 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_next_int(int *tab, int nb, int len)
{
	int	i;
	int	n_int;

	i = 0;
	n_int = nb;
	while (nb == n_int && i < len)
	{
		if (tab[i] > n_int)
			n_int = tab[i];
		i++;
	}
	while (i < len)
	{
		if (tab[i] > nb && tab[i] < n_int)
			n_int = tab[i];
		i++;
	}
	return (n_int);
}
