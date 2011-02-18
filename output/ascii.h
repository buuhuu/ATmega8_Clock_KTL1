#ifndef ASCII_H_INCLUDED
#define ASCII_H_INCLUDED

/**
 * printChar is a simple function to print a character to a framebuffer
 * shift specifies the vertical position of the character
 * printChar does *not* destroy the previous contents of the framebuffer
 */
void printChar(bitmap_t dest, char character, uint8_t shift);

#endif // ASCII_H_INCLUDED
