#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;

    int array[] = {-5006566, 9698676, -3572726, -2238739, -2965688, -1813350, -7565313, 8708510, -6027364, -5035723, -4096851, -8535548, -525365, -1303813, 1412594, -1811608, -394184, 5336500, -5233795, 1599258, -1339986, -5441049, 2668350, 1944596, -4308884, -7520244, -3505811, 832831, -6849396, -6713550, 7855356, 3667378, 9999520, 6998245, 7278337, 7241551, -1912053, 9719127, 865575, -2559892, -6341400, 5895518, -8438018, -298768, -2083607, -4073003, 1511046, 1434048, 9401440, 1459816, 658945, -8137900, -5628589, -5791148, 5538895, 1116990};

    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
