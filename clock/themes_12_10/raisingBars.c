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
#include "raisingBars.h"

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

void raisingBars(bitmap_t destination, uint8_t hours, uint8_t minutes, uint8_t seconds, uint8_t setMode) {
    clearBuffer(destination, 0x00);
	drawLine(destination, point(0,0), point(0,(seconds % 10)));
	drawLine(destination, point(1,0), point(1,(seconds / 10)));

	drawLine(destination, point(4,0), point(4,(minutes % 10)));
	drawLine(destination, point(5,0), point(5,(minutes / 10)));

	drawLine(destination, point(8,0), point(8,(hours % 10)));
	drawLine(destination, point(9,0), point(9,(hours / 10)));
};

