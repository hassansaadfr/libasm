/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:08:13 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/14 12:21:20 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int		test_strlen(char *s1, int test_nb)
{
	size_t	ft;
	size_t	real;

	ft = ft_strlen(s1);
	real = strlen(s1);
	printf("| \033[1;34m[TEST ft_strlen %d]\033[0m: ", test_nb);
	if (ft == real)
	{
		printf("                \033[1;32mOK\033[0m |\n");
		return (1);
	}
	else
		printf("\033[1;31mERROR\nShould return: %ld\\Your return: %ld\n\033[0m", real, ft);
	return (0);
}

void	print_test_strlen(int *count, int *test_nb)
{
	int		nb_success;
	int		total;

	nb_success = 0;
	total = 0;
	printf("╔----------- hsaadaou tester ------------╗\n");
	nb_success += test_strlen("", ++total);
	nb_success += test_strlen("a", ++total);
	nb_success += test_strlen("azertyuiopqsdfghjklmwxcvbn", ++total);
	nb_success += test_strlen("@&é78966131812'(§è!çà)-$^poiuytrezaqsdfghjklmù`=:;\n,nbvcxw", ++total);
	printf("╠-- ft_strlen ================== %d / %d --╣\n", nb_success, total);
	*count += nb_success;
	*test_nb += total;
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
		printf("                \033[1;32mOK\033[0m |\n");
		return (1);
	}
	else
		printf("\033[1;31mERROR\nShould return: %d\\Your return: %d\n\033[0m", real, ft);
	return (0);
}

void	print_test_strcmp(int *count, int *test_nb)
{
	int		nb_success;
	int		total;

	nb_success = 0;
	total = 0;
	nb_success += test_strcmp("", "", ++total);
	nb_success += test_strcmp("z", "a", ++total);
	nb_success += test_strcmp("azertyuiopqsdfghjklmwxcvbn", "hello", ++total);
	nb_success += test_strcmp("@&é78966131812'(§è!çà", "NULL", ++total);
	printf("╠-- ft_strcmp ================== %d / %d --╣\n", nb_success, total);
	*count += nb_success;
	*test_nb += total;
}

int		test_strdup(char *s1, int test_nb)
{
	int		diff;
	char	*s2;

	s2 = ft_strdup(s1);
	diff = ft_strcmp(s1, s2);
	if (s2)
		free(s2);
	printf("| \033[1;34m[TEST ft_strdup %d]\033[0m: ", test_nb);
	if (diff == 0)
	{
		printf("                \033[1;32mOK\033[0m |\n");
		return (1);
	}
	else
		printf("\033[1;31mERROR\nShould return: %s\nYour return: %s\n\033[0m", s1, s2);
	return (0);
}

void	print_test_strdup(int *count, int *test_nb)
{
	int		nb_success;
	int		total;

	nb_success = 0;
	total = 0;
	nb_success += test_strdup("", ++total);
	nb_success += test_strdup("a", ++total);
	nb_success += test_strdup("azertyuiopqsdfghjklmwxcvbn", ++total);
	nb_success += test_strdup("@&é78966131812'(§è!çà", ++total);
	printf("╠-- ft_strdup ================== %d / %d --╣\n", nb_success, total);
	*count += nb_success;
	*test_nb += total;
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
		printf("                \033[1;32mOK\033[0m |\n");
		return (1);
	}
	else
		printf("\033[1;31mERROR\nShould return: %s\\Your return: %s\n\033[0m", s1, s2);
	return (0);
}

void	print_test_strcpy(int *count, int *test_nb)
{
	int		nb_success;
	int		total;

	nb_success = 0;
	total = 0;
	nb_success += test_strcpy("", ++total);
	nb_success += test_strcpy("a", ++total);
	nb_success += test_strcpy("azertyuiopqsdfghjklmwxcvbn", ++total);
	nb_success += test_strcpy("@&é78966131812'(§è!çà", ++total);
	printf("╠-- ft_strcpy ================== %d / %d --╣\n", nb_success, total);
	*count += nb_success;
	*test_nb += total;
}

int		test_read(int fd, int count, char *path, int test_nb)
{
	int		diff;
	char	ft_buff[100000];
	char	real_buff[100000];
	int		fd_real;

	fd_real = open(path, O_RDONLY);
	ft_read(fd, ft_buff, count);
	read(fd_real, real_buff, count);
	diff = strcmp(real_buff, ft_buff);
	close(fd_real);
	printf("| \033[1;34m[TEST ft_read %d]\033[0m: ", test_nb);
	if (diff == 0)
	{
		printf("                  \033[1;32mOK\033[0m |\n");
		return (1);
	}
	else
	{
		printf("\033[1;31mERROR\n\033[0m");
		printf("%s \n%s\n", real_buff, ft_buff);
	}
	return (0);
}

void	print_test_read(int *count, int *test_nb)
{
	int		fd;
	char	paths[][1000] = {"Makefile", "main.c", "ft_write.s", "ft_strdup.s", "ft_strcpy.s"};
	int		i;
	int		nb_success;
	int		total;

	nb_success = 0;
	total = 0;
	i = 0;
	while (i < 5)
	{
		fd = open(paths[i], O_RDONLY);
		nb_success += test_read(fd, 10, paths[i], ++total);
		close(fd);
		i++;
	}
	printf("╠-- ft_read ==================== %d / %d --╣\n", nb_success, total);
	*count += nb_success;
	*test_nb += total;
}

int		test_write(int fd, char *str, int count, int test_nb)
{
	int		diff;
	char	cmp[100000];

	ft_write(fd, str, count);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	read(fd, cmp, count);
	diff = strncmp(str, cmp, count);
	close(fd);
	printf("| \033[1;34m[TEST ft_write %d]\033[0m: ", test_nb);
	if (diff == 0)
	{
		printf("                 \033[1;32mOK\033[0m |\n");
		return (1);
	}
	else
	{
		printf("\nr %*s\nm %s\n", count, str, cmp);
		printf("\033[1;31m ERROR\n\033[0m");
	}
	return (0);
}

void	print_test_write(int *count, int *test_nb)
{
	int		i;
	int		fd;
	char	*str;
	int		nb_success;
	int		total;

	nb_success = 0;
	total = 0;
	i = 0;
	str = "Ft42Paris";
	system("touch test.txt");
	while (str[i])
	{
		fd = open("test.txt", O_RDWR);
		nb_success += test_write(fd, str, i * 3, ++total);
		i++;
	}
	system("rm test.txt");
	printf("╠-- ft_write =================== %d / %d --╣\n", nb_success, total);
	*count += nb_success;
	*test_nb += total;
}

t_list	*new_lst(void)
{
	return (malloc(sizeof(t_list)));
}

t_list	*generate_list(int size)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = new_lst();
	while (i < size)
	{
		real_ft_lstlast(lst)->next = new_lst();
		i++;
	}
	return (lst);
}

int		test_ft_list_size(int test_nb, t_list *lst)
{
	int		your_return;
	int		expected;
	int		out;

	out = 0;
	your_return = ft_list_size(lst);
	expected = real_ft_lstsize(lst);
	if (!lst)
		lst = new_lst();
	printf("| \033[1;34m[TEST ft_list_size %d]\033[0m: ", test_nb);
	if (expected == your_return)
	{
		printf("             \033[1;32mOK\033[0m |\n");
		out = 1;
	}
	else
		printf("\033[1;31m ERROR\n\033[0m");
	if (lst->content)
		real_ft_lstclear(&lst, free);
	return (out);
}

void	print_test_ft_list_size(int *count, int *test_nb)
{
	t_list	*lst;
	int		nb_success;
	int		total;
	int		i;

	nb_success = 0;
	total = 0;
	i = 0;
	while (i < 8)
	{
		lst = generate_list(i);
		nb_success += test_ft_list_size(++total, lst);
		i++;
	}
	nb_success += test_ft_list_size(++total, NULL);
	printf("╠-- ft_list_size =============== %d / %d --╣\n", nb_success, total);
	*test_nb += total;
	*count += nb_success;
}

void	ascii_art(int valid)
{
	char	good[] = "ascii_good.txt";
	char	wrong[] = "ascii_wrong.txt";
	int		fd;
	char	buf[10000];

	fd = open(valid ? good : wrong, O_RDWR);
	read(fd, buf, 10000);
	if (valid)
		printf("\n\033[1;32m%s\033[0m\n", buf);
	else
		printf("\n\033[1;31m%s\n\033[0m\n", buf);
	close(fd);
}

int		main(void)
{
	int		count;
	int		test_nb;

	count = 0;
	test_nb = 0;
	print_test_strlen(&count, &test_nb);
	print_test_strcmp(&count, &test_nb);
	print_test_strdup(&count, &test_nb);
	print_test_strcpy(&count, &test_nb);
	print_test_read(&count, &test_nb);
	print_test_write(&count, &test_nb);
	print_test_ft_list_size(&count, &test_nb);
	printf("╚-- END ---------------------- %d / %d --╝\n", count, test_nb);
	ascii_art(count == test_nb);
	return (1);
}
