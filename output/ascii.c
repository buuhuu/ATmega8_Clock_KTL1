/*
Copyright (C) 2011  Lucas Stach

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

#include <inttypes.h>

#include "display_12_10.h"
#include "ascii_table.h"

void printChar(bitmap_t dest, char character, int8_t shift)
{
    int i;
    for(i = 0; i < 10; i++)
    {
        if(shift > 0)
        {
            dest[i] |= ascii_table[(character-33)][i] << shift;
        }
        else
        {
            dest[i] |= ascii_table[(character-33)][i] >> -shift;
        }
    }
}
