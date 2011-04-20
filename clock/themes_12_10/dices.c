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

void pt_dices(bitmap_t dest, const struct timeval_t time, const uint8_t clock_mode)
{
    clearBuffer(dest, 0x00);
	drawDice(dest, time.seconds % 10, point(1,6));
	drawDice(dest, time.seconds / 10, point(1,2));

	drawDice(dest, time.minutes % 10, point(5,6));
	drawDice(dest, time.minutes / 10, point(5,2));

	drawDice(dest, time.hours % 10, point(9,6));
	drawDice(dest, time.hours / 10, point(9,2));
};
