#include "hash_tables.h"
/**
 * key_index - gives the index of akey
 * @key: the key to hash
 * @size: the size of the hash table
 * Return: index of given key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
