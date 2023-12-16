#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - A function that used to compares two strings.
 * @s1: The 1st string.
 * @s2: The 2nd string.
 * Return: Positive byte, Negative byte.
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value - A function that used to get the numerical value of a card.
 * @card: A pointer to deck_node_t card.
 * Return: The numerical value of the card.
 */

char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - A function that used to
 *				sort a deck of cards from spades to diamonds.
 * @deck: A head pointer to deck_node_t doubly-linked list.
 */

void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iter, *m_insert, *temple;

	for (iter = (*deck)->next; iter != NULL; iter = temple)
	{
		temple = iter->next;
		m_insert = iter->prev;
		while (m_insert != NULL && m_insert->card->kind > iter->card->kind)
		{
			m_insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = m_insert;
			iter->prev = m_insert->prev;
			iter->next = m_insert;
			if (m_insert->prev != NULL)
				m_insert->prev->next = iter;
			else
				*deck = iter;
			m_insert->prev = iter;
			m_insert = iter->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - A function that used to
 *				sort a deck of cards sorted from
 *				spades to diamonds from ace to king.
 * @deck: A head pointer to deck_node_t doubly-linked list.
 */

void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iter, *m_insert, *temple;

	for (iter = (*deck)->next; iter != NULL; iter = temple)
	{
		temple = iter->next;
		m_insert = iter->prev;
		while (m_insert != NULL &&
		       m_insert->card->kind == iter->card->kind &&
		       get_value(m_insert) > get_value(iter))
		{
			m_insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = m_insert;
			iter->prev = m_insert->prev;
			iter->next = m_insert;
			if (m_insert->prev != NULL)
				m_insert->prev->next = iter;
			else
				*deck = iter;
			m_insert->prev = iter;
			m_insert = iter->prev;
		}
	}
}

/**
 * sort_deck - A functio that used to
 *		sort a deck of cards from ace to king and
 *		from spades to diamonds.
 * @deck: A head pointer to deck_node_t doubly-linked list.
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
