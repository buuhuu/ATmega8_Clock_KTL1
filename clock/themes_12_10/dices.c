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

#include <avr/io.h>
#include <inttypes.h>

#include "../../output/display_12_10.h"
#include "../../output/geometry.h"
#include "dices.h"

/* Dices */
/*

 #	1


  #
	2
#

  #
 #	3
#

# #
	4
# #

# #
 #	5
# #

# #
# #	6
# #

# #
###	7
# #

###
# #	8
###

###
###	9
###

*/

void drawDice(bitmap_t dest, uint8_t number, struct point_t center) {
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

void dices(bitmap_t dest, uint8_t hours, uint8_t minutes, uint8_t seconds, uint8_t setMode) {
    clearBuffer(dest, 0x00);
	drawDice(dest, seconds % 10, point(1,6));
	drawDice(dest, seconds / 10, point(1,2));

	drawDice(dest, minutes % 10, point(5,6));
	drawDice(dest, minutes / 10, point(5,2));

	drawDice(dest, hours % 10, point(9,6));
	drawDice(dest, hours / 10, point(9,2));
};
