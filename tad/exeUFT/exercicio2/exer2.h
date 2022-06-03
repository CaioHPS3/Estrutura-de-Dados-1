// especificação
typedef struct cojunto Conj;

Conj *create_conjunto(int capacity);
void desaloca(Conj **vec);
int exist(Conj *vec, int val);
int include(Conj *vec, int val);
int print(Conj *vec);
int remov(Conj *vec, int val);
Conj *inter(Conj *vec1, Conj *vec2);