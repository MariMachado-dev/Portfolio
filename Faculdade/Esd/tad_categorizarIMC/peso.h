typedef struct pes Peso;

Peso *peso_cria(int kg, int g);

void pes_libera(Peso *p);

void pes_acessa(Peso *p, int *kg, int *g);

/* Função atribui - Atribui novos valores às partes de um peso */
void setPeso(Peso *p, int kg, int g);

void pes_exibe(Peso* p);

/* Função getPeso- Retorna uma string com os valores do peso  no formato
kg, g*/
char *getPeso(Peso *p);

void alteraPeso(Peso *p, int g);

int pes_compara(Peso *p1, Peso *p2);

Peso *pes_soma(Peso *p, int g);

Peso *pes_copia(Peso *p);