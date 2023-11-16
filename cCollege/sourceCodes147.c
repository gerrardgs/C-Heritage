// NO. 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
  char value;
  struct Node *next;
}Node;

void createNode(Node **node, char value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;

  if(*node == NULL)
  {
    *node = newNode;
    newNode->next = newNode;
    return;
  }

  newNode->next = (*node)->next;
  (*node)->next = newNode;
}

int hitungMakan(Node *node)
{
  if(node == NULL)
  {
    return 0;
  }

  int hitung = 0;
  Node *tail = node;
  do
  {
    hitung++;
    tail = tail->next;
  }
  while(tail != node && tail->value != 'B');
  return hitung;
}

int main()
{
  Node *node = NULL;
  char input[100];
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0';
  char *tb = strtok(input, " ");
  while(tb != NULL)
  {
    createNode(&node, *tb);
    tb = strtok(NULL, " ");
  }
  int x = hitungMakan(node);
  printf("Ular mati ketika memakan ekornya sebanyak %d kali.\n", x);

  if(node != NULL)
  {
    Node *tail = node->next;
      while(tail != node)
      {
      Node *temp = tail;
      tail = tail->next;
      free(temp);
    }
    free(node);
  }
return 0;
}
