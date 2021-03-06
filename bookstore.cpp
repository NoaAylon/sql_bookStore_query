#include <stdlib.h>
#include <iostream>
#include "Database.h"
#include "book.h"
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <boost/tokenizer.hpp>
#include <string>

using namespace std;

using namespace sql;

int main(int argc, char *argv[])
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~ WELCOME TO ONLINE BOOK STORE ~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	cout << "                       BY NOA EYLON & SAHAR GEZER                          " << endl << endl;
	int choose;
	while (1)
	{
		
		cout << "Please choose one of the options, PRESS 1-20 " << endl
			<< "1.Show books in stock" << endl 
			<< "2.Show all orders" << endl 
			<< "3.Show all customers" << endl 
			<< "4.Show all providers" << endl 
			<< "5.Show all purchase between date1 = ? AND date2 = ?" << endl 
			<< "6.Show all books in sale" << endl
			<< "7.CHECK IF book is in stock (book title = ?) " << endl 
			<< "8.Show all providers of book (book title = ?) " << endl
			<< "9.CHECK book coppies selled since date (book id = ? AND date = ?) " << endl
			<< "10.CHECK books quantity purchaded by customer since date (customer id = ? AND date = ?)" << endl 
			<< "11.Most popular CUSTOMER since date (date = ?) " << endl 
			<< "12.Most popular PROVIDER since date (date = ?) " << endl 
			<< "13.Orders number between date 1 and date 2" << endl 
			<< "14.Orders number between date 1 and date 2 became purchase" << endl 
			<< "15.Toal discount that given to customer since date" << endl 
			<< "16.Total revenue in quarteres" << endl 
			<< "17.Customeres joines since date" << endl 
			<< "18.Show amount orders from provider (provider id = ?) between date 1 = ? AND date 2 = ?" << endl 
			<< "19.Show amount purchases from salesman (salesman id = ? ) between date 1= ? AND date 2 = ?" << endl 
			<< "20.TOP 10 BETWEEN date 1 = ? AND date 2 = ?" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl;

		cin >> choose;
		system("clear");

		switch (choose) 
		{
			case 0:
			{
				return 0;
				break;
			}
			case 1:
			{
				show_books();
				break;
			}
			case 2:
			{
				show_orders();
				break;
			}
			case 3:
			{
				show_customers();
				break;
			}
			case 4:
			{
				show_providers();
				break;
			}
			case 5:
			{
				string date1;
				string date2;
				cout << "enter start date : ";
				cin >> date1;
				cout << "enter end date : ";
				cin >> date2;
				show_purchases_between(date1, date2);
				break;
			}
			case 6:
			{
				books_in_sale();
				break;
			}
			case 7:
			{
				string book_title;
				cout << "enter book title: ";
				cin >> book_title;
				if_in_stock(book_title);
				break;
			}
			case 8:
			{
				string book_id;
				cout << "enter book id: ";
				cin >> book_id;
				book_providers(book_id);
				break;		
			}
			case 9:
			{
				string book_id;
				string date;
				cout << "enter book id: ";
				cin >> book_id;
				cout << "enter date: ";
				cin >> date;
				book_copies_since(book_id,date);
				break;			
			}
			case 10:
			{
				string customer_id;
				string date;
				cout << "enter customer id: ";
				cin >> customer_id;
				cout << "enter date: ";
				cin >> date;
				customer_purchases_since(customer_id,date);
				break;			
			}

			case 11:
			{
				string date;
				cout << "enter date: ";
				cin >> date;
				most_popular_customer_since(date);
				break;	
			}
			case 12:
			{
				string date;
				cout << "enter date: ";
				cin >> date;
				most_popular_provider_since(date);
				break;
			}
			case 13:
			{
				string date1;
				string date2;
				cout << "enter start date : ";
				cin >> date1;
				cout << "enter end date : ";
				cin >> date2;
				sum_orders_between(date1, date2);
				break;		
			}
			case 14:
			{
				string date1;
				string date2;
				cout << "enter start date : ";
				cin >> date1;
				cout << "enter end date : ";
				cin >> date2;
				count_orders_becomes_purchase_between(date1, date2);
				break;			
			}
			case 15:
			{
				string customer_id;
				string date;
				cout << "enter customer id: ";
				cin >> customer_id;
				cout << "enter date: ";
				cin >> date;
				total_discount_customer_recived_since(customer_id, date);
				break;					
			}
			case 16:
			{
				total_revenue_in_quarter();
				break;
			}
			case 17:
			{
				string date;
				cout << "enter date: ";
				cin >> date;
				joined_customers_since(date);
				break;
			}
			case 18:
			{
				string provider_id;
				cout << "enter provider id: ";
				cin >> provider_id;

				string date1;
				cout << "enter date 1: ";
				cin >> date1;

				string date2;
				cout << "enter date 2: ";
				cin >> date2;		
				amount_orders_from_provider(provider_id, date1, date2);
				break;
			}
			case 19:
			{
				string salesman_id;
				cout << "enter salesman id: ";
				cin >> salesman_id;

				string date1;
				cout << "enter date 1: ";
				cin >> date1;

				string date2;
				cout << "enter date 2: ";
				cin >> date2;
				amount_purchases_from_salesman(salesman_id, date1, date2);
				break;		
			}
			case 20:
			{
				string date1;
				string date2;
				cout << "enter start date : ";
				cin >> date1;
				cout << "enter end date : ";
				cin >> date2;
				top_10_books_between(date1,date2);
				break;
			}

		}
	}
	return 0;
}

/*	Database &db = Database::getInstance();
	cout << "test test" << endl;
	Connection *con = db.getConnection();
	cout << "DONE CREATING TABLES" << endl;
	getchar();
	return 0;*/