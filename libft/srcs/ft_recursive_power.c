/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/29 21:05:39 by creckel           #+#    #+#             */
/*   Updated: 2020/09/19 12:32:00 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if ((nb == 0) | (power < 0))
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	else
		return (nb * ft_recursive_power(nb, (power - 1)));
}
