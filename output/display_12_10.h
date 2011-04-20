/*
Copyright (C) 2011  Dirk Rudolph, Lucas Stach, Paul Ritter

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

#ifndef DISPLAY_12_10_H_INCLUDED
#define DISPLAY_12_10_H_INCLUDED

/**
 * bitmap_t is the only memory layout we can scanout from.
 * Every row is represented as a single 16 bit integer, where every pixel is
 * assigned to a single bit. The 4 msb are ignored.
 */
typedef uint16_t bitmap_t[10];

/**
 * setPixel is a helper function to set a single Pixel on a given bitmap
 * Note: this is a header only implementation
 */
static inline void setPixel(bitmap_t dest, const uint8_t col, const uint8_t row)
{
    dest[row] |= (1<<col);
}

/**
 * Scanout the given bitmap to the display
 */
void scanout(const bitmap_t bitmap);

/**
 * clearBuffer clears the framebuffer with a given pattern
 */
void clearBuffer(bitmap_t bitmap, const uint8_t pattern);

/**
 * shiftBuffer shifts the contents of a bitmap by the given degree
 */
void shiftBuffer(bitmap_t bitmap, const uint8_t shift);

#endif // DISPLAY_12_10_H_INCLUDED
