typedef struct pessoa TPessoa;

TPessoa *pessoa_cria(const char *nome, Peso *pes, Altura *alt);

void pessoa_libera(TPessoa *p);

char *getNome(TPessoa *p);

Peso* pessoa_getPeso(TPessoa* p);

Altura* getAltura(TPessoa* p);

void setNome(TPessoa *p, const char *nome);

void setAltura(TPessoa* p, Altura* alt);

void pessoa_setPeso(TPessoa* p, Peso* pes);

void pessoa_exibe(TPessoa* p);

float pessoa_calculaIMC(TPessoa* p);

char* pessoa_categorizaIMC(TPessoa *p);