/*
Copyright (C) 2011 Paul Ritter, Lucas Stach

Dieses Programm ist freie Software. Sie können es unter den Bedingungen der GNU
General Public License Version 2, wie von der Free Software Foundation veröffentlicht,
weitergeben und/oder modifizieren.

Die Veröffentlichung dieses Programms erfolgt in der Hoffnung, daß es Ihnen von Nutzen
sein wird, aber OHNE IRGENDEINE GARANTIE, sogar ohne die implizite Garantie der
MARKTREIFE oder der VERWENDBARKEIT FÜR EINEN BESTIMMTEN ZWECK. Details finden Sie in
der GNU General Public License.

Sie sollten ein Exemplar der GNU General Public License zusammen mit diesem Programm
erhalten haben. Falls nicht, schreiben Sie an die Free Software Foundation, Inc., 51
Franklin St, Fifth Floor, Boston, MA 02110, USA.
*/

#ifndef SIMPLE_ARITH_H_INCLUDED
#define SIMPLE_ARITH_H_INCLUDED

/**
 * This file provides simple arithmetic utility functions
 * Note: this is a header only implementation
 */


/**
 * min_{type} returns the smaller one of two values
 */
static inline uint8_t min_u8(const uint8_t a, const uint8_t b)
{
	return (a < b) ? a : b;
}

static inline int8_t min_s8(const int8_t a, const int8_t b)
{
	return (a < b) ? a : b;
}

/**
 * max_{type} returns the bigger one of two values
 */
static inline uint8_t max_u8(const uint8_t a, const uint8_t b)
{
	return (a > b) ? a : b;
}

static inline int8_t max_s8(const int8_t a, const int8_t b)
{
	return (a > b) ? a : b;
}

/**
 * abs_{type} returns the value of a value witout regard to it's sign
 */
static inline int8_t abs_s8(const int8_t a)
{
    return (a < 0) ? -a : a;
}

#endif
