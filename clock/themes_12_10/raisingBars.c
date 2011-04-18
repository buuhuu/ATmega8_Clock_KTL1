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
#include "../clock.h"

/* raisingBars

example

			 #
			 #
			 #
	 #		 #
	 #	 #	##
	 #	 #	##
	##	##	##
	14	13	37

	14h	13m	37s
*/

void pt_raisingBars(bitmap_t destination, const struct timeval_t time, const uint8_t clock_mode) {
    clearBuffer(destination, 0x00);
	drawLine(destination, point(0,9-(time.seconds % 10)), point(0,9));
	drawLine(destination, point(1,9-(time.seconds / 10)), point(1,9));

	drawLine(destination, point(4,9-(time.minutes % 10)), point(4,9));
	drawLine(destination, point(5,9-(time.minutes / 10)), point(5,9));

	drawLine(destination, point(8,9-(time.hours % 10)), point(8,9));
	drawLine(destination, point(9,9-(time.hours / 10)), point(9,9));
}
