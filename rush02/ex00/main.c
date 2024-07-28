/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:25:17 by talin             #+#    #+#             */
/*   Updated: 2024/07/28 16:09:08 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define INITIAL_BUFFER_SIZE 1024
#define CHUNK_SIZE 1024

void	write_error(const char *message)
{
	write(STDERR_FILENO, message, strlen(message));
}

char	*allocate_buffer(size_t size)
{
	char	*buffer;

	buffer = (char *)malloc(size);
	if (buffer == NULL)
		write_error("Error allocating memory\n");
	return (buffer);
}

void	copy_buffer(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*expand_buffer(char *buffer, size_t *buffer_size, size_t total_size)
{
	char	*new_buffer;

	*buffer_size *= 2;
	new_buffer = allocate_buffer(*buffer_size);
	if (new_buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	copy_buffer(new_buffer, buffer, total_size);
	free(buffer);
	return (new_buffer);
}

char	*read_file_chunk(int fd, char *buffer, size_t *total_size, size_t *buffer_size)
{
	ssize_t	bytes_read;
	char	chunk[CHUNK_SIZE];
	size_t	i;

	bytes_read = read(fd, chunk, CHUNK_SIZE);
	while (bytes_read > 0)
	{
		if (*total_size + bytes_read >= *buffer_size)
		{
			buffer = expand_buffer(buffer, buffer_size, *total_size);
			if (buffer == NULL)
			{
				close(fd);
				return (NULL);
			}
		}
		i = 0;
		while (i < bytes_read)
		{
			buffer[*total_size + i] = chunk[i];
			i++;
		}
		*total_size += bytes_read;
		bytes_read = read(fd, chunk, CHUNK_SIZE);
	}
	if (bytes_read == -1)
		write_error("Error reading file\n");
	return (buffer);
}

char	*read_file(const char *filename, size_t *out_size)
{
	int		fd;
	size_t	buffer_size;
	size_t	total_size;
	char	*buffer;

	buffer_size = INITIAL_BUFFER_SIZE;
	total_size = 0;
	buffer = allocate_buffer(buffer_size);
	if (buffer == NULL)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write_error("Error opening file\n");
		free(buffer);
		return (NULL);
	}
	buffer = read_file_chunk(fd, buffer, &total_size, &buffer_size);
	if (buffer == NULL)
	{
		close(fd);
		return (NULL);
	}
	buffer[total_size] = '\0';
	*out_size = total_size;
	close(fd);
	return (buffer);
}

void	convert_number_to_string(int number, char *number_str, int *number_len)
{
	int		temp_number;
	int		i;
	char	temp;

	*number_len = 0;
	temp_number = number;
	if (temp_number == 0)
		number_str[(*number_len)++] = '0';
	else
	{
		while (temp_number > 0)
		{
			number_str[(*number_len)++] = (temp_number % 10) + '0';
			temp_number /= 10;
		}
		i = 0;
		while (i < *number_len / 2)
		{
			temp = number_str[i];
			number_str[i] = number_str[*number_len - 1 - i];
			number_str[*number_len - 1 - i] = temp;
			i++;
		}
	}
	number_str[*number_len] = '\0';
}

char	*extract_word_from_line(char *line_start, char *colon_pos, char *line_end)
{
	char	word[CHUNK_SIZE];
	size_t	word_index;
	char	*result;
	char	*ptr;

	word_index = 0;
	ptr = colon_pos + 1;
	while (ptr < line_end)
	{
		if (*ptr != ' ' && *ptr != '\t')
			word[word_index++] = *ptr;
		ptr++;
	}
	word[word_index] = '\0';
	result = allocate_buffer(word_index + 1);
	if (result != NULL)
	{
		copy_buffer(result, word, word_index);
		result[word_index] = '\0';
	}
	return (result);
}

char	*find_word_in_buffer(int number, char *buffer, size_t buffer_size)
{
	char	number_str[12];
	int		number_len;
	char	*line_start;
	char	*colon_pos;
	char	*line_end;
	int		num;
	char	*ptr;

	convert_number_to_string(number, number_str, &number_len);
	line_start = buffer;
	while (line_start < buffer + buffer_size)
	{
		line_end = line_start;
		while (line_end < buffer + buffer_size && *line_end != '\n')
			line_end++;
		if (line_end < buffer + buffer_size)
			*line_end = '\0';
		colon_pos = line_start;
		while (colon_pos < line_end && *colon_pos != ':')
			colon_pos++;
		if (colon_pos < line_end)
		{
			num = 0;
			ptr = line_start;
			while (ptr < colon_pos)
			{
				if (*ptr >= '0' && *ptr <= '9')
					num = num * 10 + (*ptr - '0');
				ptr++;
			}
			if (num == number)
				return (extract_word_from_line(line_start, colon_pos, line_end));
		}
		line_start = line_end + 1;
	}
	return (NULL);
}

char	*find_combined_word(int number, char *buffer, size_t buffer_size)
{
	int		tens;
	int		ones;
	char	*tens_word;
	char	*ones_word;
	size_t	result_size;
	char	*result;

	tens = (number / 10) * 10;
	ones = number % 10;
	tens_word = find_word_in_buffer(tens, buffer, buffer_size);
	ones_word = find_word_in_buffer(ones, buffer, buffer_size);
	result_size = 0;
	if (tens_word != NULL)
		result_size += strlen(tens_word);
	if (ones_word != NULL)
		result_size += strlen(ones_word) + 1;
	result = allocate_buffer(result_size + 1);
	if (result == NULL)
	{
		write_error("Error allocating memory for result\n");
		free(tens_word);
		free(ones_word);
		return (NULL);
	}
	result[0] = '\0';
	if (tens_word != NULL)
	{
		strcat(result, tens_word);
		if (ones_word != NULL)
			strcat(result, " ");
	}
	if (ones_word != NULL)
		strcat(result, ones_word);
	free(tens_word);
	free(ones_word);
	return (result);
}

char	*find_word(int number, const char *filename)
{
	size_t	buffer_size;
	char	*buffer;
	char	*result;

	buffer = read_file(filename, &buffer_size);
	if (buffer == NULL)
		return (NULL);
	result = find_combined_word(number, buffer, buffer_size);
	free(buffer);
	return (result);
}

int	main(void)
{
	int		number;
	char	*word;

	printf("Enter a number: ");
	scanf("%d", &number);
	word = find_word(number, "numbers.dict");
	if (word != NULL)
	{
		printf("%d is written as %s\n", number, word);
		free(word);
	}
	else
		printf("Number not found in file.\n");
	return (0);
}

