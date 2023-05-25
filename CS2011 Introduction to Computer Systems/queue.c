/* 
 * Code for basic C skills diagnostic.
 * Developed by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 * 
 * @author Gamage Thavishka
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "harness.h"
#include "queue.h"

queue_t *q_new()
{
    queue_t *q  = (queue_t *)malloc(sizeof(queue_t));
    if(!q)
     return q;
    else
    { 
    
    q->head = NULL;
    q->tail = NULL;
    q->qsize = 0;
    return q;
    } 
}


void q_free(queue_t *q)
{
    
    list_ele_t *temp;
    if(q == NULL)
      return;
    if(q != NULL)
    {    
    while(q->head!=NULL)
    {
        temp = q->head;
        q->head = q->head->next;
        free(temp->value);
        free(temp);
    }    
    free(q);
}
}

bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *hnew;
    char *snew;
    /* What should you do if the q is NULL? */
    if(!q)
      return false;
    else
    {  
     hnew = (list_ele_t *)malloc(sizeof(list_ele_t));
     if(hnew == NULL)
     {
       free(hnew);      
       return false;
      } 
     else
     {   
      snew = malloc(strlen(s) + 1); 
      if(snew == NULL)
       {
       	free(snew); 
	      return false; 
	     
       }
      else
      {
       strcpy(snew,s);
    
       hnew->value = snew;
      if(q->head != NULL)
      {
        hnew->next = q->head;
        q->head = hnew;
        q->qsize++;
        return true;
        
      }
      else{
      hnew->next = NULL;
      q->head = hnew;
      q->tail = hnew;
      q->qsize++;
      return true;
      }
      }
}
}
}

bool q_insert_tail(queue_t *q, char *s)
{
	list_ele_t *tnew;
    char *snew;
    /* What should you do if the q is NULL? */ 
    if(q == NULL)
      return false;
    else
    {  
     tnew = (list_ele_t *)malloc(sizeof(list_ele_t));
     if(tnew == NULL)
       return false;
     else
     {   
      snew = malloc(strlen(s)+1); 
      if(snew == NULL)
       {
	       free(tnew);
         return false;
       }
      else
      {
       strcpy(snew,s);
       tnew->value=snew;
    
      if(q->tail != NULL)
      {
        
        q->tail->next = tnew;
        tnew->next = NULL;
        q->tail = tnew;
        q->qsize++;
        return true;
      }
      else{
      tnew->next = NULL;
      q->tail = tnew;
      q->head = tnew;
      q->qsize++;
      return true;
      }
      }
}
}
}


bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    list_ele_t *temp;  
    if(q == NULL)
      return false;
    else
    if(q->qsize == 0)
      return false;  
    else
    {  
      if(q->head != NULL && sp !=NULL )
      {
        size_t n;
        n = bufsize-1;
        q->qsize--;
        temp = q->head;
        if(bufsize<strlen(temp->value))
        {
         q->head = q->head->next;
         strncpy(sp,temp->value,n);
         sp[n] = '\0';
         free(temp->value);
         free(temp);
         return true;
         }
        else
        {
         q->head = q->head->next;
         strcpy(sp,temp->value);
         free(temp->value);
         free(temp);
         return true;
         
        }
      }
      
      else
      {
        return false;
        
      }
       
      }
}


int q_size(queue_t *q)
{
  
   if(q == NULL)
      return 0;
   else
     return (q->qsize);   
}


void q_reverse(queue_t *q)
{

  list_ele_t *prev;
  list_ele_t *current;
  list_ele_t *next;

  
  if(q == NULL)
  {
   return;
   }
  else
  if(q->qsize <= 1)
    return;
  else
  {
  prev = q->head;
  current = prev->next;
  prev->next = NULL;
  q->tail = prev;   
  while(current!=NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current =next;
  }
  
  q->head = prev;
  q->tail->next = NULL;
  }
}