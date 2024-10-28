/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:26:18 by igchurru          #+#    #+#             */
/*   Updated: 2024/04/24 12:14:23 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_int_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_specialcase(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		return (ft_strdup("0"));
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (n == -2147483648 || n == 0)
		return (ft_specialcase(n));
	len = ft_int_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	i = len - 1;
	while (n)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[len] = '\0';
	return (str);
}

/* int	main(void)
{
	char	*result;

	result = ft_itoa(123456789);
	printf("%s\n", result);
	free(result);
	return (0);
} */

/* ft_itoa convierte un número entero en una cadena de caracteres,
manejando casos especiales y números negativos, y asignando memoria
dinámica para la cadena resultante. Devuelve un puntero a la cadena
resultante. */