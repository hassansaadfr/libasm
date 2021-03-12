/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:08:13 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/12 16:41:25 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "stdio.h"
#include "string.h"

int		test_strlen(char *s1, int test_nb)
{
	size_t	ft;
	size_t	real;

	ft = ft_strlen(s1);
	real = strlen(s1);
	printf("| \033[1;34m[TEST ft_strlen %d]\033[0m: ", test_nb);
	if (ft == real)
	{
		printf("\033[1;32mOK\033[0m                 |\n");
		return (1);
	}
	else
		printf("\033[1;31mERROR\nShould return: %ld\\Your return: %ld\n\033[0m", real, ft);
	return (0);
}

void	print_test_strlen(void)
{
	int		count;
	int		test_nb;

	count = 0;
	test_nb = 0;
	printf("╔----------- hsaadaou tester ------------╗\n");
	count += test_strlen("", ++test_nb);
	count += test_strlen("a", ++test_nb);
	count += test_strlen("azertyuiopqsdfghjklmwxcvbn", ++test_nb);
	count += test_strlen("@&é78966131812'(§è!çà)-$^poiuytrezaqsdfghjklmù`=:;\n,nbvcxw", ++test_nb);
	printf("╠-- ft_strlen ================== %d / %d --╣\n", count, test_nb);
}

int		test_strcmp(char *s1, char *s2, int test_nb)
{
	int		ft;
	int		real;

	ft = strcmp(s1, s2);
	real = ft_strcmp(s1, s2);
	printf("| \033[1;34m[TEST ft_strcmp %d]\033[0m: ", test_nb);
	if (ft == real)
	{
		printf("\033[1;32mOK\033[0m                 |\n");
		return (1);
	}
	else
		printf("\033[1;31mERROR\nShould return: %d\\Your return: %d\n\033[0m", real, ft);
	return (0);
}

void	print_test_strcmp(void)
{
	int		count;
	int		test_nb;

	count = 0;
	test_nb = 0;
	count += test_strcmp("", "", ++test_nb);
	count += test_strcmp("a", "a", ++test_nb);
	count += test_strcmp("azertyuiopqsdfghjklmwxcvbn", "hello", ++test_nb);
	count += test_strcmp("@&é78966131812'(§è!çà", "NULL", ++test_nb);
	printf("╠-- ft_strcmp ================== %d / %d --╣\n", count, test_nb);
}

int		test_strdup(char *s1, int test_nb)
{
	int		ft;
	int		real;
	char	*s2;

	s2 = ft_strdup(s1);
	ft = strcmp(s1, s2);
	real = ft_strcmp(s1, s2);
	printf("| \033[1;34m[TEST ft_strdup %d]\033[0m: ", test_nb);
	if (ft == real)
	{
		printf("\033[1;32mOK\033[0m                 |\n");
		return (1);
	}
	else
		printf("\033[1;31mERROR\nShould return: %d\\Your return: %d\n\033[0m", real, ft);
	return (0);
}

void	print_test_strdup(void)
{
	int		count;
	int		test_nb;

	count = 0;
	test_nb = 0;
	count += test_strdup("", ++test_nb);
	count += test_strdup("a", ++test_nb);
	count += test_strdup("azertyuiopqsdfghjklmwxcvbn", ++test_nb);
	count += test_strdup("@&é78966131812'(§è!çà", ++test_nb);
	printf("╠-- ft_strdup ================== %d / %d --╣\n", count, test_nb);
}

int		test_strcpy(char *s1, int test_nb)
{
	int		diff;
	char	s2[1000];

	ft_strcpy(s2, s1);
	diff = strcmp(s1, s2);
	printf("| \033[1;34m[TEST ft_strcpy %d]\033[0m: ", test_nb);
	if (diff == 0)
	{
		printf("\033[1;32mOK\033[0m                 |\n");
		return (1);
	}
	else
		printf("\033[1;31mERROR\nShould return: %s\\Your return: %s\n\033[0m", s1, s2);
	return (0);
}

void	print_test_strcpy(void)
{
	int		count;
	int		test_nb;

	count = 0;
	test_nb = 0;
	count += test_strcpy("", ++test_nb);
	count += test_strcpy("a", ++test_nb);
	count += test_strcpy("azertyuiopqsdfghjklmwxcvbn", ++test_nb);
	count += test_strcpy("@&é78966131812'(§è!çà", ++test_nb);
	printf("╠-- ft_strcpy ================== %d / %d --╣\n", count, test_nb);
}

int		main(void)
{
	print_test_strlen();
	print_test_strcmp();
	print_test_strdup();
	print_test_strcpy();
	// printf("╚----------------------------------------╝\n");
	return (1);
}
