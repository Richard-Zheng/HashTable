#include <stdlib.h>
#include <string>

#include "hash_table.h"

static ht_item* ht_new_item(const char* k, const char* v) {
	ht_item* i = (ht_item*) malloc(sizeof(ht_item));
	i->key = _strdup(k);
	i->value = _strdup(v);
	return i;
}

static void ht_del_item(ht_item* i) {
	free(i->key);
	free(i->value);
	free(i);
}

ht_hash_table* ht_new() {
	ht_hash_table* ht = (ht_hash_table*) malloc(sizeof(ht_hash_table));

	ht->size = 53;
	ht->count = 0;
	ht->items = (ht_item**) calloc((size_t)ht->size, sizeof(ht_item*));
	return ht;
}

void ht_del_hash_table(ht_hash_table* ht) {
	for (int i = 0; i < ht->size; i++) {
		ht_item* item = ht->items[i];
		if (item != NULL) {
			ht_del_item(item);
		}
	}
	free(ht->items);
	free(ht);
}
