#ifndef STRUCT_H
#define STRUCT_H
struct date
{
    int year;
    int month;
    int day;
};

struct vip
{
    int id;
    unsigned long long phone_number;
    char name[20];
    struct date last_consume_day;
    double total_consume;
};

void init_vip(struct vip *vip)
{
    vip->id = 0;
    vip->phone_number = 0;
    vip->total_consume = 0;
    vip->last_consume_day.year = 1970;
    vip->last_consume_day.month = 1;
    vip->last_consume_day.day = 1;
    vip->name[0] = '\0';
}

struct FREIGHT
{
    unsigned long long EAN;
    char name[20];
    int stock;
    double purchase_price;
    double sale_price;
    double margins;
};
typedef struct FREIGHT freight;

void init_freight(freight *freight)
{
    freight->EAN = 0;
    memset(freight->name, 0, 20);
    freight->stock = 0;
    freight->purchase_price = 0;
    freight->sale_price = 0;
    freight->margins = 0;
}
#endif
