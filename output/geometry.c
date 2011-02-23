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

#include "display_12_10.h"
#include "geometry.h"

struct point_t point(uint8_t col, uint8_t row) {
    struct point_t temp;
    temp.column = col;
    temp.row = row;
    return temp;
};

uint8_t min(uint8_t a, uint8_t b) {
	return (a < b) ? a : b;
};

uint8_t max(uint8_t a, uint8_t b) {
	return (a > b) ? a : b;
};

void drawLine(bitmap_t dest, struct point_t start, struct point_t end) {
	uint8_t i, j;
	struct point_t temp;

	// handle vertical lines
	if (start.column == end.column) {
		if (start.row > end.row) {
			temp = start;
			start = end;
			end = temp;
		};

		for (i=start.row; i < end.row; i++) {
			dest[i] |= (1 << start.column);
		};
		return;
	};

	// handle horizontal lines
	if (start.row == end.row) {
		dest[start.row] |= (~(1 << end.column) << start.column);
		return;
	};

	// handle other types of lines and generate steps
	uint8_t step;
	uint8_t current;

	// always paint from LSB to MSB
	if (start.column > end.column) {
		temp = start;
		start = end;
		end = temp;
	};

	// going down
	if (end.row > start.row) {
		// step down horizontally
		/*
			  ##
			##
		*/
		if ((end.column - start.column) >= (end.row - start.row)) {
			// step at least 1px
			step = max((end.column - start.column) / (end.row - start.row) - 1 , 1);
			current = start.column;

			for (i = start.row; i <= end.row; i++) {
				dest[i] |= (~(1 << step) << current);
				current = min(current+step,end.column);
				// adjust step if neccessary
				step = min(step, end.column-current);
			};
			return;
		} else {
		// step down vertically
		/*
			 #
			 #
			#
			#
		*/
			step = (end.row - start.row) / (end.column - start.column) - 1;
			current = start.row;
			for (i = start.column; i <= end.column; i++) {
				for (j=step; j > 0; j--) {
					dest[min(current++,end.row)] |= 1 << i;
				};
			};
			return;
		};
	} else {
	// going up
		// step up horizontally
		/*
			##
			  ##
		*/
		if ((end.column - start.column) >= abs(end.row - start.row)) {
			// step at least 1px
			step = max((end.column - start.column) / abs(end.row - start.row) - 1 , 1);
			current = start.column;

			for (i = start.row; i >= end.row; i--) {
				dest[i] |= (~(1 << step) << current);
				current = min(current+step,end.column);
				// adjust step if neccessary
				step = min(step, end.column-current);
			};
			return;
		} else {
		// step up vertically
		/*
			#
			#
			 #
			 #
		*/
			step = abs(end.row - start.row) / (end.column - start.column) - 1;
			current = start.row;
			for (i = start.column; i >= end.column; i--) {
				for (j=step; j > 0; j--) {
					dest[min(current++,end.row)] |= 1 << i;
				};
			};
			return;
		};
	};

};
