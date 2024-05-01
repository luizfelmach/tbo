#include "item.h"

void sort(Item *a, int lo, int hi) {
    for (int i = lo; i <= hi; i++) {
        Item least = a[i];
        int index = i;
        for (int j = i + 1; j <= hi; j++) {
            if (less(a[j], least)) {
                least = a[j];
                index = j;
            }
        }
        exch(a[index], a[i]);
    }
}
