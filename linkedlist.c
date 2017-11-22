#include "linkedlist.h"

int add_to_list(linked_list *ll, char *s)
{
	linked_list *newll=ll;
	int i=0;
	while (newll->next != NULL)
		{
			newll = newll->next;
			i++;
		}
	i++;
	newll->next = (linked_list* )malloc(sizeof(struct linked_list));
    newll->next->data = s;
    newll->next->next = NULL;
	newll->next->index = i;
	newll->next->previous = newll;

//	struct linked_list *newll
//	newll = (linked_list* )malloc(sizeof(struct linked_list));
//	newll->data = s;
//	ll->next = newll;
//	newll->next = NULL;	
//	newll->index=ll->index;
//	newll->index++;
	
	
	return newll->next->index;
};

int display_item(linked_list *ll)
{
	if(ll->data != NULL)
		{
			printf("%s\n",ll->data);
			return 0;
		}
	else 
		return -1;

};

int display_list(linked_list *ll)
{
	linked_list *newll=ll;
	int i=0;
	while (newll->next != NULL)
		{
			newll = newll->next;
			i++;
			display_item(newll);
		}
	return i;
};

linked_list * search_from_list(linked_list *ll, char *s)
{
	linked_list *newll=ll;
	while (newll->next != NULL)
		{
			newll = newll->next;
			if(newll->data==s)
				return newll;			
		}
	return NULL;
};

int delete_from_list(linked_list *ll, int index)
{
	int i;
	linked_list * newll = ll;
	linked_list * temp = NULL;

	if (index<=0)
		return -1;
	else
		{
			for (i = 0; i < index-1; i++)
				{
					if (newll->next == NULL)
						{
							if(newll->index==index-1)
							{
								free(newll);
								ll->next=NULL;
								return 0;
							}
							return -1;
						}
					newll = newll->next;
				}

    temp = newll->next;
    newll->next = temp->next;
	
    free(temp);
	i=0;
	newll = ll;
	
	while (newll->next != NULL)
		{
			newll->next->previous = newll;
			newll = newll->next;
			i++;
		}
			return i;
		}
};

int empty_list(linked_list *ll)
{
	if (ll->next == NULL) 
	{
        free(ll);
        return 0;
    }
 
	linked_list * current = ll;	
    while (current->next->next != NULL) 
		{
			current = current->next;
		}

    free(current->next);
    current->next = NULL;
	return 0;
};

int linkedlist_status(linked_list *ll)
{
	int i=0;
	linked_list * newll = ll;
	
	while (newll->next != NULL)
		{
			newll = newll->next;
			i++;
		}
	
	if(i<0)
		return -1;
	else
		return i;	
};
