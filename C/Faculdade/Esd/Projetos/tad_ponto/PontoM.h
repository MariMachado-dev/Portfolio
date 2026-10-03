/*Tipo exportado */
/* cria um ponto no pano cartesiano (x,y)*/
typedef struct ponto Ponto;

/* Funções exportadas */
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto* pto_cria(float x, float y);


/* Função libera - Libera a memória de um ponto previamente criado */
void pto_libera(Ponto* p);

/* Função copia - Aloca e retorna um novo ponto com coordenadas do 
ponto recebido (x,y) */
Ponto* pto_copia(Ponto* p);

/* Função acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa(Ponto* p, float* x, float* y);

/* Função acessaX - Retorna o valor da coordenada x de um ponto */
void pto_acessaX(Ponto* p, float* x);

/* Função atribui - Atribui novos valores às coordenadas de um ponto */
void pto_atribui(Ponto* p, float x, float y);

/* Função atribui - Atribui novo valor à coordenada x de um ponto */
void pto_atribuiX(Ponto* p, float x);

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exibe(Ponto* p);

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto(Ponto* p);

/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(Ponto* p1, Ponto* p2);

/* função compara -1:se o pt1 < pt2, 0 se pt1 == pt2, +1 se o pt1 > pt2  */
/* um ponto é menor do que o outro se estiver mais próximo da origem*/
int pto_compara(Ponto*p1,Ponto*p2);


