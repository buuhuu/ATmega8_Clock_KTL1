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
#include <stdint.h>

#include "../../output/display_12_10.h"
#include "../../output/geometry.h"
#include "../../utility/simple_arith.h"
#include "../clock.h"

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

struct point_t getHandPoint(const uint8_t time, const uint8_t hours)
{
	uint8_t row, col;

	if (hours == 0) {
		if (time <= 15) {
			row = max_s8(0, (time - 7)/2);
			col = max_s8(3, 7 - time / 2);
			return point(col,row);
		}
		if (time <= 30) {
			row = min_s8(8, (time - 7)/2);
			col = max_s8(3, (time - 23)/2 + 3 + time/30);
			return point(col,row);
		}
		if (time <= 45) {
			row = min_s8(8, ((37 - time) / 2) + 8);
			col = min_s8(11, (time - 23)/2 + 4);
			return point(col,row);
		} else {
			row = max_s8(0, ((37 - time) / 2) + 8);
			col = min_s8(11, (53 - time) / 2 + 11);
			return point(col,row);
		}
	} else {
		// using fixed coordinates is easier here
		switch(time) {
			case 0: return point(7,1);
			case 1: return point(5,1);
			case 2: return point(4,2);
			case 3: return point(4,4);
			case 4: return point(4,6);
			case 5: return point(5,7);
			case 6: return point(7,7);
			case 7: return point(9,7);
			case 8: return point(10,6);
			case 9: return point(10,4);
			case 10: return point(10,2);
			case 11: return point(9,1);
		}
	}
	return point(0,0);
}

void pt_analogClock(bitmap_t destination, const struct timeval_t time,
                    const uint8_t clock_mode)
{
    clearBuffer(destination, 0x00);
	drawLine(destination, point(0,9-(time.seconds % 10)), point(0,9));
	drawLine(destination, point(1,9-(time.seconds / 10)), point(1,9));

	drawLine(destination, point(7,4), getHandPoint(time.minutes,0));

	drawLine(destination, point(7,4), getHandPoint(time.hours % 12, 1));
}
