#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "queue.h"

/* Notice: sometimes, Cppcheck would find the potential NULL pointer bugs,
 * but some of them cannot occur. You can suppress them by adding the
 * following line.
 *   cppcheck-suppress nullPointer
 */

typedef struct list_head list_head;

/* Create an empty queue */
struct list_head *q_new()
{
    struct list_head *lh = malloc(sizeof(list_head));
    if (lh != NULL) {
        lh->next = lh;
        lh->prev = lh;
    }
    return lh;
}

/* Free all storage used by queue */
void q_free(struct list_head *l)
{
    if (l == NULL) {
        return;
    }
    list_head *next = l->next;
    while (next != l) {
        list_head *tmp = next;
        next = next->next;
        element_t *element = container_of(tmp, element_t, list);
        free(element->value);
        free(element);
    }
    free(l);
}

/* Insert an element at head of queue */
bool q_insert_head(struct list_head *head, char *s)
{
    if (head == NULL)
        return false;
    size_t length = strlen(s) + 1;  // 因 strcpy 會多抓一個結尾字元
    char *str = malloc(length);
    element_t *element = malloc(sizeof(element_t));
    if (str == NULL || element == NULL)
        return false;
    str = strncpy(str, s, length);
    element->value = str;
    element->list.prev = head;
    element->list.next = head->next;
    head->next->prev = &element->list;
    head->next = &element->list;
    return true;
}

/* Insert an element at tail of queue */
bool q_insert_tail(struct list_head *head, char *s)
{
    if (head == NULL)
        return false;
    size_t length = strlen(s) + 1;  // 因 strcpy 會多抓一個結尾字元
    char *str = malloc(length);
    element_t *element = malloc(sizeof(element_t));
    if (str == NULL || element == NULL)
        return false;
    str = strncpy(str, s, length);
    element->value = str;
    element->list.prev = head->prev;
    element->list.next = head;
    head->prev->next = &element->list;
    head->prev = &element->list;
    return true;
}

/* Remove an element from head of queue */
element_t *q_remove_head(struct list_head *head, char *sp, size_t bufsize)
{
    if (head == NULL || head->next == head)
        return NULL;
    element_t *target = container_of(head->next, element_t, list);
    target->list.next->prev = head;
    head->next = target->list.next;
    if (sp != NULL) {
        strncpy(sp, target->value, bufsize - 1);
        sp[bufsize - 1] = '\0';
    }
    return target;
}

/* Remove an element from tail of queue */
element_t *q_remove_tail(struct list_head *head, char *sp, size_t bufsize)
{
    if (head == NULL || head->next == head)
        return NULL;
    element_t *target = container_of(head->prev, element_t, list);
    target->list.prev->next = head;
    head->prev = target->list.prev;
    if (sp != NULL) {
        strncpy(sp, target->value, bufsize - 1);
        sp[bufsize - 1] = '\0';
    }
    return target;
}

/* Return number of elements in queue */
int q_size(struct list_head *head)
{
    return -1;
}

/* Delete the middle node in queue */
bool q_delete_mid(struct list_head *head)
{
    // https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
    return true;
}

/* Delete all nodes that have duplicate string */
bool q_delete_dup(struct list_head *head)
{
    // https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
    return true;
}

/* Swap every two adjacent nodes */
void q_swap(struct list_head *head)
{
    // https://leetcode.com/problems/swap-nodes-in-pairs/
}

/* Reverse elements in queue */
void q_reverse(struct list_head *head) {}

/* Reverse the nodes of the list k at a time */
void q_reverseK(struct list_head *head, int k)
{
    // https://leetcode.com/problems/reverse-nodes-in-k-group/
}

/* Sort elements of queue in ascending order */
void q_sort(struct list_head *head) {}

/* Remove every node which has a node with a strictly greater value anywhere to
 * the right side of it */
int q_descend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Merge all the queues into one sorted queue, which is in ascending order */
int q_merge(struct list_head *head)
{
    // https://leetcode.com/problems/merge-k-sorted-lists/
    return 0;
}
