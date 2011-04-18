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

#ifndef ASCII_H_INCLUDED
#define ASCII_H_INCLUDED

/**
 * printChar is a simple function to print a character to a framebuffer
 * shift specifies the vertical position of the character
 * printChar does *not* destroy the previous contents of the framebuffer
 */
void printChar(bitmap_t dest, const char character, const uint8_t shift);

#endif // ASCII_H_INCLUDED
