#include <stdio.h>
#include <time.h>


//struct tm* localtime(const time_t*);


int main()
{
	time_t timer;
	time(&timer);
	struct tm* p = localtime(&timer);
	// yerine asagidaki gibi cagirabiliriz

	struct tm* p = localtime(&(time_t) { time(NULL) });

}




// --------------------------------------------------------------------
//
//typedef struct Person {
//	int m_no;
//	char m_name[20];
//	char m_surname[20];
//}Person;
//
//void process_person(const Person* p);
//
//
//int main()
//{
//	Person per = { 12, "Mustafa Aksoy" };
//	process_person(&per);
//
//	// per nesnesi buradan sonra da yasamaya devam edecek
//	// socpe leakage
//  // burada ideal olan nesnenin sadece kullanilmak uzere olsuturulmasi
//  // isim verme ihtiyaci olmamasi. isim verilmis olmasi 
//  // okuyan kisiyi nesneye daha sonrada ihtiyac varmiscasina yaniltabilir.
//}
// 
// --------------------------------------------------------------------
// void process_array(const int* p, size_t size);
// 
//int main()
//{
//	// Scope leakage diziler icinde gecerli
//	// fonksiyonu cagirabilmek icin diziyi olusturmak isim vermek gerekli
//	int primes[] = { 2, 3, 5, 7, 11 };
//	process_array(primes, 5);
//
//	// primes hala bu noktada gorunur durumda
//}
// 
// --------------------------------------------------------------------
// void process_array(const int* p, size_t size);
//
//int main()
//{
//	// burada otomatik omurlu yerel bir dizi tanimlanmis oldu
//	process_array((int[]) { 2, 3, 5, 7, 11 }, 5); // array decay oldu
//	// array decay: dizinin adrese donusmesi
//}
//
// --------------------------------------------------------------------
//
//int main()
//{
//	(int[]) {2, 3, 5, 7, 11}; // derleyici dizinin uzunlugu derleme zamaninda ilk deger sayisindan anlayacak
//	(int[10]) {2, 3, 5, 7, 11}; // 10 deger ile baslatma ama 5 deger atamam var kalan 5 tanesi 0
//	(int[100]) {[1] = 2, [55] = 20, [90] = 30}; // ilk deger verilen indisler disindakiler sifir dizi uzunlugu 100
//	(int[]) {[1] = 2, [55] = 20, [90] = 30}; // ilk deger verilen indisler disindakiler sifir dizi uzunlugu 91
//}
// --------------------------------------------------------------------
// 
//void foo(const int* ptr);
//
// 
//int main()
//{
//	(int) {10}; // int turunde bir nesne
//	&(int) {10}; // int turunde bir nesne referans
//	foo(&(int) { 10 });
//}
// 
// --------------------------------------------------------------------
// 
//void func(int x, int y, int z)
//{
//	int *p = (int[]) {x,y,z}; //fonksiyon girdileri ile olusturuluyor.
//  // ilk deger verme sarti yok
//}
//
// --------------------------------------------------------------------
// 
//typedef struct Person {
//	int m_no;
//	char m_name[20];
//	char m_surname[20];
//}Person;
//
//void func(const Person* p)
//{
//	///.
//}
//
//int main()
//{
//	Person per;
//	per = (Person){ 654, "Osman", "Ersoz" }; // atama isleminde 
//
//	Person a[10];
//	a[0] = (Person){ 654, "Osman", "Ersoz" }; // dizi elemanina atama
//	a[1] = (Person){ 975, "Ahmet", "Yilmaz" };
//
//	func(&(Person) { 1234, "Ali", "Caner" }); // fonksyion cagirma
//
//	Person *p = &(Person){ 76, "Ayse", "Karaman" }; // Const olmayan durumda degisim yapmak
//	p->m_no = 9871;
//}
// --------------------------------------------------------------------
//typedef struct {
//	int x, y;
//}Point;
//
//void draw_point(const Point* p);
//
//int main()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		draw_point(&(Point) { i, i });
//	}
//}
// 
// --------------------------------------------------------------------
//
//int main()
//{
//	time_t timer;
//	time(&timer);
//	struct tm* p = localtime(&timer);
//	// yerine asagidaki gibi cagirabiliriz
//
//	struct tm* p = localtime(&(time_t) { time(NULL) });
//
//}
// 
// --------------------------------------------------------------------
// 
// 
// --------------------------------------------------------------------
