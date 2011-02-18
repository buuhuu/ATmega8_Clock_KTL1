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

#ifndef ASCII_TABLE_H_INCLUDED
#define ASCII_TABLE_H_INCLUDED

/**
 * ascii_table defines the printable charset
 */

const uint8_t ascii_table[94][10] =
{
    {},   // !
    {},   // "
    {},   // #
    {},   // $
    {},   // %
    {},   // &
    {},   // '

    {},   // (
    {},   // )
    {},   // *
    {},   // +
    {},   // ,
    {},   // -
    {},   // .
    {},   // /
    {},   // 0
    {},   // 1

    {},   // 2
    {},   // 3
    {},   // 4
    {},   // 5
    {},   // 6
    {},   // 7
    {},   // 8
    {},   // 9
    {},   // :
    {},   // ;

    {},   // <
    {},   // =
    {},   // >
    {},   // ?
    {},   // @
    {0x3C, 0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x00, 0x00},   // A
    {0x7C, 0x42, 0x42, 0x7C, 0x42, 0x42, 0x42, 0x7C, 0x00, 0x00},   // B
    {0x1C, 0x22, 0x40, 0x40, 0x40, 0x40, 0x22, 0x1C, 0x00, 0x00},   // C
    {0x78, 0x44, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7C, 0x00, 0x00},   // D
    {0x3E, 0x40, 0x40, 0x3C, 0x40, 0x40, 0x40, 0x3E, 0x00, 0x00},   // E

    {},   // F
    {},   // G
    {},   // H
    {},   // I
    {},   // J
    {},   // K
    {},   // L
    {},   // M
    {},   // N
    {},   // O

    {},   // P
    {},   // Q
    {},   // R
    {},   // S
    {},   // T
    {},   // U
    {},   // V
    {},   // W
    {},   // X
    {},   // Y

    {},   // Z
    {},   // [
    {},   // backslash
    {},   // ]
    {},   // ^
    {},   // _
    {},   // `
    {0x00, 0x00, 0x00, 0x3C, 0x02, 0x3E, 0x42, 0x3E, 0x00, 0x00},   // a
    {0x40, 0x40, 0x40, 0x5C, 0x62, 0x42, 0x44, 0x78, 0x00, 0x00},   // b
    {0x00, 0x00, 0x00, 0x1C, 0x20, 0x40, 0x42, 0x3C, 0x00, 0x00},   // c

    {0x02, 0x02, 0x02, 0x3A, 0x46, 0x42, 0x42, 0x3E, 0x00, 0x00},   // d
    {0x00, 0x00, 0x00, 0x3C, 0x42, 0x7C, 0x40, 0x3C, 0x00, 0x00},   // e
    {},   // f
    {},   // g
    {},   // h
    {},   // i
    {},   // j
    {},   // k
    {},   // l
    {},   // m

    {},   // n
    {},   // o
    {},   // p
    {},   // q
    {},   // r
    {},   // s
    {},   // t
    {},   // u
    {},   // v
    {},   // w

    {},   // x
    {},   // y
    {},   // z
    {},   // {
    {},   // |
    {},   // }
    {},   // ~
};

#endif // ASCII_TABLE_H_INCLUDED
