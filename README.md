TODO:

> Define the size of memory zones

> Make sure any error returns null.

> Preallocate in the beginning and free preallocated at the end

> test, test and test



> Memory Defragmentation
> if two blocks of memory next to each other are freed, 
> a larger memory block can be allocated using both spaces. This happens by design, since the previous allocations are removed from the list and a new allocation will take such spaces.
> example:
> a = malloc;
> b = malloc;
> 


`TODO:
Realloc is not reinserting... example:
int main (void)
{
	char *alloc;
	char *alloc2;

	alloc = malloc(16 * 6);
	*alloc = '0';
	alloc2 = malloc(18);
	*alloc2 = '0';
	alloc = realloc(alloc, 16 * 2);
	alloc = malloc(16*2);
	show_alloc_mem_ex();
	free(alloc);
	return (0);
}



--> Determine the correct minimum size (LIMIT) [DONE]

--> test realloc extensivelly!!! [DONE]

--> TODO:
1. Testing with online testers
2. Fix color reset
3. Fix function names (_ for internal functions)

> Nice mmap resouce
> https://www.cs.uaf.edu/2017/fall/cs301/lecture/11_20_mmap.html
