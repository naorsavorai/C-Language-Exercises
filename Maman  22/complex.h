typedef struct  complex
{
    double rl;
    double im;
} comp;

typedef struct  imaginary
{
    double im;
} img;

void print_comp(comp z);
void read_comp(comp *z ,double real, double imaginary);
comp default_comp();
comp add_comp(comp z, comp w);
comp sub_comp(comp z, comp w);
comp mult_comp_real(comp z, double x);
comp mult_comp_img(comp z, img w);
comp mult_comp_comp(comp z, comp w);
double abs_comp (comp z);
void use_read_comp(char input[],int* index,comp* pointers[]);
void use_print_comp(char input[],int* index,comp* pointers[]);
void use_add_comp(char input[],int* index,comp* pointers[]);
void use_sub_comp(char input[],int* index,comp* pointers[]);
void use_mult_comp_real(char input[],int* index,comp* pointers[]);
void use_mult_comp_img(char input[],int* index,comp* pointers[]);
void use_mult_comp_comp(char input[],int* index,comp* pointers[]);
void use_abs_comp(char input[],int* index,comp* pointers[]);
void read_input(comp* pointer[]);
