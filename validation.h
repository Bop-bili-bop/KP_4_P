#ifndef VALIDATION_H
#define VALIDATION_H
double val_double_input(const char *prompt)
{
    double value = 0 ;
    int input = 0;
    do
    {
        printf("%s", prompt);
        input = scanf("%lf", &value);
        if (input != 1)
        {
            printf("Invalid input. Please enter a valid number.\n");
            value = 0;
        }
        fflush(stdin);
    }
    while (input != 1);
    return value;
}
double val_char_input(const char *prompt)
{
    char value = 0 ;
    char input = 0;
    do
    {
        printf("%s", prompt);
        input = scanf("%c", &value);
        if (input != 1)
        {
            printf("Invalid input. Please enter a valid number.\n");
            value = 0;
        }
        fflush(stdin);
    }
    while (input != 1);
    return value;
}
double val_dx(const char *prompt, const char* error_msg, char (*condition)(double))
{
    double value = 0;
    do {
        value = val_double_input(prompt);
        if (!condition(value))
        {
            printf("%s\n", error_msg);
        }
        fflush(stdin);
    }
    while (!condition(value));
    return value;

}
//condition funcs
char zero_step(double value)
{
    return value == 0;
}
char not_negative_step(double value)
{
    return value > 0 && value !=0;
}
char negative_step(double value)
{
    return value < 0 && value !=0;
}
double dx_numbers(char var) {
    switch (var)
    {
        case 1:
            return val_dx("Please enter step dx (dx > 0):", "Invalid input. Please try again", not_negative_step);
        case 2:
            return val_dx("Please enter step dx (dx < 0):", "Invalid input. Please try again", negative_step);
        default:
            return val_dx("Please enter step dx (dx = 0):", "Invalid input. Please try again", zero_step);
    }
}


#endif