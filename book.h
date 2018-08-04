
#ifndef book_h
#define book_h

#include <stdio.h>
#include <iostream>
#include "Database.h"
//#include <boost/date_time/posix_time/posix_time.hpp>

#include "mysql_connection.h"

using namespace std;
using namespace sql;

//using namespace boost::posix_time;
//using namespace boost::gregorian;

void show_books();
void show_orders();
void show_customers();
void show_providers();
void show_purchases_between(const string &date1, const string &date2);
void books_in_sale();
void if_in_stock(const string book_title);
void book_providers(const string &book_id);
void book_copies_since(const string &book_title, const string &date);
void customer_purchases_since(const string &first_name, const string &date);
void most_popular_customer_since(const string &date);
void most_popular_provider_since(const string &date);
void sum_orders_between(const string &date1, const string &date2);
void count_orders_becomes_purchase_between(const string &date1, const string &date2);
void total_discount_customer_recived_since(const string &customer_id, const string &date);
void total_revenue_in_quarter();
void joined_customers_since(const string &date);
void amount_orders_from_provider(const string &provider_id, const string &date1, const string &date2);
void amount_purchases_from_salesman(const string &salesman_id, const string &date1, const string &date2);
void top_10_books_between(const string &date1, const string &date2);



#endif 

