#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct hash_node_s - Node of a hash table
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

/**
 * struct sort_hash_nd_s - Node of a sorted hash node
 * @key: String
 * @value: The value related to key
 * @next: A pointer to the next node of the List
 * @sprev: A pointer to the previous element of the sorted list
 * @snext: A pointer to the next element of the sorted list
 */
typedef struct sort_hash_nd_s
{
	char *key;
	char *value;
	struct sort_hash_nd_s *next;
	struct sort_hash_nd_s *sprev;
	struct sort_hash_nd_s *snext;
} sort_hash_nd_t;

/**
 * struct sort_hash_table_s - Sorted hash table
 * @size: Size of array
 * @array: An array
 * @shead: A pointer to the first element in list
 * @stail: A pointer to the last element in list
 */
typedef struct sort_hash_table_s
{
	unsigned long int size;
	sort_hash_nd_t **array;
	sort_hash_nd_t *shead;
	sort_hash_nd_t *stail;
} sort_hash_table_t;

sort_hash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(sort_hash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const sort_hash_table_t *ht, const char *key);
void shash_table_print(const sort_hash_table_t *ht);
void shash_table_print_rev(const sort_hash_table_t *ht);
void shash_table_delete(sort_hash_table_t *ht);

#endif
