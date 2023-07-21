<p align="center">
	<img width="130px;" src="https://game.42sp.org.br/static/assets/images/42_logo_black.svg" align="center" alt="42" />
	<h1 align="center">Leak Finder</h1>
</p>
<p align="center">
	<img src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white">
</p>

<p align="center">
	<b><i>Development repository for the leak finder utility developed @ 42 Heilbronn</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/iwillenshofer/leak_finder?color=blueviolet" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/iwillenshofer/leak_finder?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/commit-activity/t/iwillenshofer/leak_finder?color=brightgreen" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/iwillenshofer/leak_finder?color=brightgreen" />
</p>
<br>

> _This is a project built on top of ft_malloc to help find leaks on other projects._

<br>

### Usage

1. clone this repo.
```bash
# create a main file.
$ git clone git@github.com:iwillenshofer/leak_finder.git
$ make
````

2. Add the `malloc.h` header as the *first header* in your project.
```c
#include "malloc.h"
```

```bash
#set this to the folder you cloned the repo, relative to your project
$ export LEAK_FINDER=./leak_finder
$ gcc -L./${LEAK_FINDER} -lft_malloc -I./${LEAK_FINDER}/includes  main.c
$ ./a.out
```

#### Example of main() file
```c
#include "malloc.h"
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
	show_alloc_mem_ex();
	print_leaks();
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
|	print_leaks			|	void	print_leaks(void);					|
