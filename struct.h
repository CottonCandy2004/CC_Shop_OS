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
    unsigned long long EAN; //EAN码
    char name[20]; //货物名称
    int stock; //货物库存
    int purchase_price; //货物进价
    int sale_price; //货物售价
    int margins; //货物利润
};
typedef struct FREIGHT freight;
void init_freight(freight *freight)
{
    freight->EAN = 0;
    freight->name[20] = "";
    freight->stock = 0;
    freight->purchase_price = 0;
    freight->sale_price = 0;
}
#endif
