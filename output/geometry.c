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

#include <avr/io.h>
#include <inttypes.h>

#include "display_12_10.h"
#include "geometry.h"
#include "../utility/simple_arith.h"

void drawLine(bitmap_t dest, struct point_t start, struct point_t end)
{
    struct point_t pt;
    uint8_t span, vertical;

    if(abs_s8(end.column - start.column) > abs_s8(start.row - end.row)) {
        if(end.column < start.column) {
            pt = start;
            start = end;
            end = pt;
        }
        span = end.column - start.column;
        vertical = 1;
    } else {
        if(end.row < start.row) {
            pt = start;
            start = end;
            end = pt;
        }
        span = end.row - start.row;
        vertical = 0;
    }

    for(uint8_t i = 0; i < span; i++) {
        if(vertical) {
            setPixel(dest, start.column+i, (start.row*(span-i) + end.row*i +span/2)/span);
        } else {
            setPixel(dest, (start.column*(span-i) + end.column*i + span/2)/span, start.row+i);
        }
    }
}

/**
 * Dices
 *-------------------------------------------------------
 *|     |   # |   # | # # | # # | # # | # # | ### | ### |
 *|  #  |     |  #  |     |  #  | # # | ### | # # | ### |
 *|     | #   | #   | # # | # # | # # | # # | ### | ### |
 *
 *   1     2     3     4     5     6     7     8     9
 */
void drawDice(bitmap_t dest, const uint8_t number, const struct point_t center)
{
	// checking array boundaries
	if (center.row > 0 && center.column > 0 && center.row < 9 && center.column < 11) {
		// all mean numbers share center pixel
		if (number % 2 == 1) {
			dest[center.row] |= 1 << center.column;
		}
		// all numbers > 1 share corner pixels
		if (number > 1) {
			dest[center.row - 1] |= 1 << (center.column - 1);
			dest[center.row + 1] |= 1 << (center.column + 1);
		}
		// all numbers > 3 share other corner pixels
		if (number > 3) {
			dest[center.row - 1] |= 1 << (center.column + 1);
			dest[center.row + 1] |= 1 << (center.column - 1);
		}
		// all numbers > 5 share left and right pixels
		if (number > 5) {
			dest[center.row] |= (1 << (center.column - 1)) | (1 << (center.column + 1)) ;
		}
		// all numbers > 7 share top and bottom pixels
		if (number > 7) {
			dest[center.row - 1] |= 1 << center.column;
			dest[center.row + 1] |= 1 << center.column;
		}
	}
}
