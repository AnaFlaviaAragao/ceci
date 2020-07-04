#ifndef MUX_H
#define MUX_H
/**
 *  2x1 multiplexer 
 * 
 *  @param a Input A pin
 *  @param b Input B pin
 *  @param selector Selector pin
 *  @return a or b depending on the selector (0 or 1 respectively)
 */
int mux(int a, int b, int selector);
#endif //MUX_H