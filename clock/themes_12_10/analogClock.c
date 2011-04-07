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
#include "analogClock.h"

/* analog clock

example


        #
       #
      #
     #
    ####

           #
          ##
          ##

3h ca.7m 23s

hands are not 100% accurate due to limited pixel count
*/

void analogClock(bitmap_t destination, uint8_t hours, uint8_t minutes, uint8_t seconds, uint8_t setMode) {
    clearBuffer(destination, 0x00);
	drawLine(destination, point(0,9-(seconds % 10)), point(0,9));
	drawLine(destination, point(1,9-(seconds / 10)), point(1,9));

	drawLine(destination, point(7,4), getHandPoint(minutes,0));

	drawLine(destination, point(7,4), getHandPoint(hours % 12, 1));
}

struct point_t getHandPoint(uint8_t time, uint8_t hours) {
	uint8_t row, col;

	if (hours == 0) {
		if (time <= 15) {
			row = max(0, (time - 7)/2);
			col = max(3, (7 - time) / 2);
			return point(col,row);
		}
		if (time <= 30) {
			row = min(8, (time - 7)/2);
			col = max(3, (time - 23)/2 + 3);
			return point(col,row);
		}
		if (time <= 45) {
			row = min(8, ((37 - time) / 2) + 8);
			col = min(11, (time - 23)/2 + 3);
			return point(col,row);
		} else {
			row = max(0, ((37 - time) / 2) + 8);
			col = min(11, (53 - time) / 2 + 11);
			return point(col,row);
		}
	} else {
		// using fixed coordinates is easier here
		switch(time) {
			case 0: return point(7,1); break;
			case 1: return point(5,1); break;
			case 2: return point(3,2); break;
			case 3: return point(3,4); break;
			case 4: return point(3,6); break;
			case 5: return point(5,7); break;
			case 6: return point(7,7); break;
			case 7: return point(9,7); break;
			case 8: return point(10,6); break;
			case 9: return point(10,4); break;
			case 10: return point(10,2); break;
			case 11: return point(9,1); break;
		}
	}
	return point(0,0);
}
