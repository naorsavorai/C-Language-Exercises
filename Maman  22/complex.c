#include <stdio.h>
#include <math.h>
#include "complex.h"
/**/
void read_comp(comp* z ,double real, double imaginary)
{
        (*z).rl = real;
        (*z).im = imaginary;
}
void print_comp(comp z)
{
    printf("%f + %fi",z.rl,z.im);
}
comp default_comp()
{
    comp res;
    res.rl = 0;
    res.im = 0;
    return res;
}
comp add_comp(comp z, comp w)
{
    comp res;
    res.rl = (z.rl) + (w.rl);
    res.im = (z.im) + (w.im);
    return res;
}
comp sub_comp(comp z, comp w)
{
    comp res;
    res.rl = (z.rl) - (w.rl);
    res.im = (z.im) - (w.im);
    return res;
}
comp mult_comp_real(comp z, double x)
{
    comp res;
    res.rl = (z.rl)*x;
    res.im = (z.im)*x;
    return res;
}
comp mult_comp_img(comp z, img w)
{
    comp res;
    res.im = (z.rl)*(w.im);
    res.rl = (z.im)*(w.im)*(-1);
    return res;
}
comp mult_comp_comp(comp z, comp w)
{
    comp res;
    res.rl = (z.rl)*(w.rl) - (z.im)*(w.im);
    res.im = (z.rl)*(w.im) + (z.im)*(w.rl);
    return res;
}
double abs_comp (comp z)
{
    double res;
    res = sqrt((z.rl)*(z.rl) + (z.im)*(z.im));
    return res;
}




