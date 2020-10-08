#ifndef MENGER
#define MENGER

void menger(int level);
void build_level_one_sponge(char **sponge, char symbol);
void recurse(char **sponge, int idx, int level, int len, int nxt);
void print_sponge(char **sponge, int len);
void free_sponge(char **sponge, int max_len);
#endif /* ifndef MENGER */
