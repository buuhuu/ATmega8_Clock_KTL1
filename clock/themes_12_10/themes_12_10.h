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

#ifndef THEMES_12_10_H_INCLUDED
#define THEMES_12_10_H_INCLUDED

void pt_simpleBinary(bitmap_t destination, const struct timeval_t time, const uint8_t clock_mode);

void pt_raisingBars(bitmap_t destination, const struct timeval_t time, const uint8_t clock_mode);

void pt_dices(bitmap_t dest, const struct timeval_t time, const uint8_t clock_mode);

void pt_analogClock(bitmap_t destination, const struct timeval_t time, const uint8_t clock_mode);

#endif // THEMES_12_10_H_INCLUDED
