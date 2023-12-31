#include "main.h"

/**
 * _memcpy - copies info from one pointer to another.
 * @newptr: destination .
 * @ptr: source .
 * @size: size of the destination.
 * Return: Non.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *_ptr = (char *)ptr;
	char *_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
    {
		_newptr[i] = _ptr[i];
	}
}

/**
 * _realloc - reallocates memory with the new size.
 * @ptr: initial memory
 * @old_size: old size of memory
 * @new_size: new size of memory
 * Return: ptr of the relevant mem.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (new_size < old_size)
		_memcpy(new_ptr, ptr, new_size);
	else
		_memcpy(new_ptr, ptr, old_size);

	free(ptr);
	return (new_ptr);
}

/**
 * _reallocdp - reallocates a memory of double pointers.
 * @ptr: initial memory
 * @old_size: old size of memory
 * @new_size: new size of memory
 * Return: ptr of the relevant mem.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **new_ptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));
	if (new_size == old_size)
		return (ptr);
	new_ptr = malloc(sizeof(char *) * new_size);
	if (new_ptr == NULL)
		return (NULL);
	for (i = 0; i < old_size; i++)
    {
        new_ptr[i] = ptr[i];
    }
	free(ptr);
	return (new_ptr);
}
