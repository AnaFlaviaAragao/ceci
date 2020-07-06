#ifndef FLOP_H
#define FLOP_H
/**
 * Flop D.
 * 
 * @param a Input A pin
 * @param reset Async rest pin
 * @param clk Clock pin
 * @return "a" for clk going down->up; last "a" for clk going up->down; or "0" of reset = 1
 */
int flop(int a, int reset, int clk);

class FLOP
{
};

#endif //FLOP_H