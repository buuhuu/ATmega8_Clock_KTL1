/*
Copyright (C) 2011 Paul Ritter

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

#ifndef GEOMETRY_H_INCLUDED
#define GEOMETRY_H_INCLUDED

/**
 * struct point holds two coordinates to describe a screen position
 */
struct point_t {
	uint8_t row;
	uint8_t column;
};

struct point_t point(const uint8_t col, const uint8_t row);

void drawLine(bitmap_t dest, struct point_t start, struct point_t end);

void drawDice(bitmap_t dest, const uint8_t number, const struct point_t center);

#endif
