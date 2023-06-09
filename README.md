<p align="center">
	<img width="130px;" src="https://game.42sp.org.br/static/assets/images/42_logo_black.svg" align="center" alt="42" />
	<h1 align="center">malloc</h1>
</p>
<p align="center">
	<img src="https://img.shields.io/badge/Success-116/100_✓-gray.svg?colorA=61c265&colorB=4CAF50&style=for-the-badge">
	<img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black">
	<img src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white">
</p>

<p align="center">
	<b><i>Development repository for the 42cursus malloc project @ 42 Heilbronn</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/iwillenshofer/malloc?color=blueviolet" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/iwillenshofer/malloc?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/commit-activity/t/iwillenshofer/malloc?color=brightgreen" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/iwillenshofer/malloc?color=brightgreen" />
</p>
<br>

> _What’s the deal with malloc? You’ve been using it since the piscine C but it’s not a system call. Find out the workings behind optimum memory management and recode it, as well as free and realloc._

[Download the Subject ⤓](en.subject.pdf)

<br>

<p align="center">
	<table>
		<tr>
			<td><b>Est. Time</b></td>
			<td><b>Skills</b></td>
			<td><b>Allowed Functions</b></td>
			<td><b>Difficulty</b></td>
		</tr>
		<tr>
			<td valign="top">49 hours</td>
			<td valign="top">
<img src="https://img.shields.io/badge/Unix-555">
<img src="https://img.shields.io/badge/Algorithms & AI-555">
			</td>
			<td valign="top">
				<img src="https://img.shields.io/badge/mmap()-lightgrey">
				<img src="https://img.shields.io/badge/munmap()-lightgrey">
			</td>
			<td valign="top"> 9450 XP</td>
		</tr>
	</table>
</p>

<br>

### Usage
```bash
# create a main file.
$ make
$ gcc -L. -lft_malloc main.c
$ ./a.out
```

#### Example of main() file
```c
#include "includes/malloc.h"
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char *s;
	char *string = "hello world";
	size_t size = strlen(string);

	s = malloc(size + 1);
	s[size] = '\0';
	memcpy(s, string, size);
	printf("Malloc'd string: %s\n", s);
	free(s);
	return (0);
}
```

### Included Functions

|name					|prototype										|
|---					|---											|
|	malloc				|	void	*malloc(size_t size);				|
|	realloc				|	void	*realloc(void *ptr, size_t size);	|
|	free				|	void	free(void *ptr);					|
|	show_alloc_mem		|	void	show_alloc_mem(void);				|
|	show_alloc_mem_ex	|	void	show_alloc_mem_ex(void);			|
