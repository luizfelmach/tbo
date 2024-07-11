#include "PQ.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "event.h"

// TODO: Aqui você deve implementar uma fila com prioridade mínima para
//       ordenar os eventos por tempo, isto é, o evento com o menor tempo tem
//       a maior prioridade. Veja as funções definidas em 'event.h' para
//       a manipulação das estruturas de evento. A princípio, as funções já
//       existentes em 'event.h' são suficientes para implementar a simulação,
//       isto é, você não precisa implementar mais nada lá.
//
//       Você é livre para implementar a fila com prioridade da forma que quiser
//       mas é recomendado usar um min-heap para obter um bom desempenho. As
//       simulações maiores geram uma quantidade grande de eventos: um
//       limite superior frouxo (mas seguro) para o número máximo simultâneo de
//       eventos é N^3, aonde N é o número de partículas.

// TODO: Crie a struct pq.

struct pq {
    Event **data;
    int max_n, size;
};

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ *PQ_create(int max_N) {
    // TODO: Implemente a criação da fila que suporta no máximo o número de
    //       de eventos informados no parâmetro.

    PQ *pq = (PQ *)calloc(1, sizeof(PQ));
    pq->max_n = max_N;
    pq->size = 0;
    pq->data = malloc(pq->max_n * sizeof(Event *) + 10);
    return pq;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
    // TODO: Implemente essa função que libera toda a memória da fila,
    //       destruindo inclusive os eventos que estavam na fila.
    for (int i = 0; i < pq->size; i++) {
        destroy_event(pq->data[i]);
    }
    free(pq->data);
    free(pq);
}

#define greater(A, B) (compare(A, B) > 0)
#define exch(A, B)    \
    {                 \
        Event *t = A; \
        A = B;        \
        B = t;        \
    }

static void fix_up(PQ *pq, int k) {
    Event **a = pq->data;
    while (k > 1 && greater(a[k / 2], a[k])) {
        exch(a[k], a[k / 2]);
        k = k / 2;
    }
}

void fix_down(PQ *pq, int k) {
    Event **a = pq->data;
    while (2 * k <= pq->size) {
        int j = 2 * k;
        if (j < pq->size && greater(a[j], a[j + 1])) {
            j++;
        }
        if (!greater(a[k], a[j])) {
            break;
        }
        exch(a[k], a[j]);
        k = j;
    }
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
void PQ_insert(PQ *pq, Event *e) {
    if (pq->size == pq->max_n) {
        fprintf(stderr, "ERROR: Queue is full (%d)!\n", pq->size);
        exit(EXIT_FAILURE);
    }
    pq->size++;
    pq->data[pq->size] = e;
    fix_up(pq, pq->size);
}

/*
 * Remove e retorna o evento mais próximo.
 */
Event *PQ_delmin(PQ *pq) {
    Event *e = pq->data[1];
    pq->data[1] = pq->data[pq->size];
    pq->data[pq->size] = NULL;
    pq->size--;
    fix_down(pq, 1);
    return e;
}

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq) {
    // TODO: Implemente essa função.
    return pq->size == 0;
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq) {
    // TODO: Implemente essa função.
    return pq->size;
}
