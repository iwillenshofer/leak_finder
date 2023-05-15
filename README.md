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