#include "item.h"

void sort(Item *a, int lo, int hi) {
    for (int i = lo; i <= hi; i++) {
        for (int j = 0; j < hi - i; j++) {
            compexch(a[j], a[j + 1]);
        }
        for (int j = hi - i - 1; j >= i; j--) {
            compexch(a[j - 1], a[j]);
        }
    }
}
