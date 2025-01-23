#include <iostream>
#include <string>

class Book
{
private:
 std::string title;
 int pager;
public:
 Book() : title(""), pager(0)
 {
  std::cout << "Kонструктор по умолчанию" << '\n';
 }
 Book(const std::string& title, int pages) : title(title), pager(pager)
 {
  std::cout << "Конструктор с параметрами" << '\n';
 }
 Book(const Book& other) : title(other.title), pager(other.pager)
 {
  std::cout << "Kонструктор копирования" << '\n';
 }
 Book(const std::string& author) : title(""), pager(author.length())
 {
  std::cout << "Kонструктор преобразования" << "Число страниц: " << pager << '\n';
 }

 void setTitle(const std::string& newTitle)
 {
  title = newTitle;
 }

 void setPages(int newPages)
 {
  pager = newPages;
 }

 void InfoBook() const
 {
  std::cout << "Название книгы: " << title << " , Количество страниц: " << pager << '\n';
 }
};

int main()
{
 std.local
 Book book1;
 book1.InfoBook();

 Book book2("Война и мир", 1225);
 book2.InfoBook();

 Book book3 = book2;
 book3.InfoBook();

 Book book4("Толстой");
 book4.InfoBook();

 book1.setTitle("1984");
 book1.setPages(328);
 book1.InfoBook();

}
