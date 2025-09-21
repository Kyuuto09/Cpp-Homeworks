#include "List.h"
#include <cstdio>

int main() {
    List list;
    list.AddToHead(10);
    list.AddToHead(20);
    list.AddToHead(30);
    list.Show();

    list.AddToTail(40);
    list.AddToTail(50);
    list.Show();

    list.DeleteFromTail();
    list.Show();
}
