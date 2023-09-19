/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 04:30:18 by tyamauch          #+#    #+#             */
/*   Updated: 2023/09/19 18:49:07 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
//#include <stdio.h>
//#include <ctype.h>
//
//int ft_isdigit(int c);
//
//int main(void)
//{
//		printf("%d\n", isdigit('a'));
//        printf("%d\n", isdigit('A'));
//        printf("%d\n", isdigit('1'));
//
//        printf("%d\n", ft_isdigit('a'));
//        printf("%d\n", ft_isdigit('A'));
//        printf("%d\n", ft_isdigit('1'));
//}
//
