#include <iostream>
#include <fstream> // header files
#include<string>
#include<cstring>
#include<stdlib.h>

using namespace std;

//book class
class book{
public:
    int Book_no;
    char Book_name[50];
    char Book_auth[50];
    int copies;
    

    void getRecord(){
        cout << "Enter book Number: ";
        cin >> Book_no;
        cin.ignore();
        cout << "Enter author Name: ";
        cin.getline(Book_auth, 50);
        cout << "Enter name of the book: ";
        cin.getline(Book_name, 50);
        cout << "Enter no. of copies: ";
        cin >> copies;
    }

    void showRecord(){
        cout<<"\n*************************"<<endl;
        cout << "Book Number: " << Book_no << endl;
        cout << "Author name: " << Book_auth << endl;
        cout << "Name of Book: " << Book_name << endl;
        cout << "Copies of Book Present: " << copies << endl;
        cout<<"***************************"<<endl;
    }

    //To add record of Book
    void AddRecord(){
        fstream ptr;
        book a;
        ptr.open("book.txt", ios::app);  
        a.getRecord();
        ptr.write((const char *)&a, sizeof(a));  
        ptr.close();
        cout<<"\nRecord Added Successfully in file"<<endl;
    }

    //to delete a book from record in library
    void DeleteRecord(){
        
        fstream ptr;
        fstream temp_f;
        int key;
        bool flag=0;
        cout << "Enter the book Number to delete: ";
        cin >> key;
        
        ptr.open("book.txt", ios::in);
        
        temp_f.open("new.txt", ios::app);
        book a;
        while (ptr.read((char *)&a, sizeof(a))){
            if (ptr){

                if (a.Book_no == key){
                   flag=1;
                    continue;
                }
                else
                    temp_f.write((char *)&a, sizeof(a));
            }
        }
        temp_f.close();
        ptr.close();

        remove("book.txt");
        rename("new.txt", "book.txt");
        if(flag==0){
            cout<<"Book with number "<<key<<" is not present in record"<<endl;
            return;
        }
        cout<<"Record of book with book number "<<key<<" deleted"<<endl;
    }

     //This function is to Update Information of a Book in record
    void UpdateRecord(){
        fstream ptr;
        fstream temp_f;
        int key;
        bool flag=false;
        cout << "Enter the book Number of the book to Update: ";
        cin >> key;
      
        ptr.open("book.txt", ios::in);
       
        temp_f.open("new.txt", ios::app);
        book a;
        while (ptr.read((char *)&a, sizeof(a))){
            if (ptr)
            {

                if (a.Book_no == key){
                    a.getRecord();
                    temp_f.write((char *)&a, sizeof(a));
                    flag=true;
                }
                else{
                    temp_f.write((char *)&a, sizeof(a));
                }
            }
        }
        temp_f.close();
        ptr.close();
        if(flag==false){
            cout<<"Book with number "<<key<<" is not prsent in library"<<endl;
            return;
        }
        cout<<"Record of Book "<<key<<" updated"<<endl;
        remove("book.txt");
        rename("new.txt", "book.txt");
    }

     //Searches a particular book in record
    void search(){
        
        bool flag = 0;
        fstream ptr;
        int key;
        cout << "Enter the book Number to search : ";
        cin>>key;
       
        ptr.open("book.txt", ios::in);
        book a;
        
        while (ptr.read((char *)&a, sizeof(a))){
            if (ptr){
                if (a.Book_no==key){
                    a.showRecord();
                    flag=1;
                    break;
                }
            }
        }
           ptr.close();
        if (flag==0)
            cout << "Record is not present!!\n";
     
    }

    // to show records of Books present in Library
    void showfile(){
        cout<<"\n**************************************"<<endl;
        cout<<"The Books Present in library are: "<<endl;
        fstream ptr;
        ptr.open("book.txt", ios::in);
        book a;
        while (ptr.read((char *)&a, sizeof(a))){
            a.showRecord();
            cout<<"\n";
        }
        ptr.close();
        cout<<"\n**************************************"<<endl;

    }

};

class student{

    char Student_name[50];
    char class_of_st[20];
    int admission_no;
    int no_of_books;

public:
    // input function
    void getRecord(){
        cout << "Enter student name: ";
        cin.ignore();
        cin.getline(Student_name, 50);
        cout << "Enter admission number: ";
        cin >> admission_no;
        cout << "Enter class: ";
        cin.ignore();
        cin.getline(class_of_st, 20);
        cout << "Enter number of books issued: ";
        fflush(stdin);
        cin >> no_of_books;
    }

    void showRecord(){
        cout << "Name: " << Student_name << endl;
        cout << "Admission number: " << admission_no << endl;
        cout << "Class: " << class_of_st << endl;
        cout << "Number of books issued : " << no_of_books << endl;
    }

    //add record of student
    void AddRecord(){
        fstream ptr;
        student a;
        ptr.open("student_record.txt", ios::app);
        a.getRecord();
        ptr.write((const char *)&a, sizeof(a));
        ptr.close();
        cout << "Record of Student Added "<<endl;
    }

     //delete record of student
    void DeleteRecord(){
        int key;
        bool f=false;
        cout << "Enter the admission number of the student to delete:- ";
        cin >> key;
        fstream ptr;
        ptr.open("student_record.txt", ios::in);
        fstream temp_f;
        temp_f.open("new.txt", ios::app);
        student b1;
        while (ptr.read((char *)&b1, sizeof(b1)))
        {
            if (ptr)
            {

                if (b1.admission_no != key)
                    temp_f.write((char *)&b1, sizeof(b1));
                    else{
                        f=true;
                        continue;
                    }
            }
        }

        temp_f.close();
        ptr.close();
        if(f==false){
            cout<<"\nstudent with admission no. "<<key<<" not present in record"<<endl;
            return;
        }
        remove("student_record.txt");
        rename("new.txt", "student_record.txt");
        cout<<"\nstudent with admission no. "<<key<<" 's record deleted"<<endl;
    }

    //Update Information regarding student
    void UpdateRecord(){

        int key;
         student a;
         bool c=false;
        cout << "Enter the admission number of the student to Update the record : ";
        cin >> key;
        fstream ptr;
        fstream temp_f;
        ptr.open("student_record.txt", ios::in);
        
        temp_f.open("new.txt", ios::app);
       
        while (ptr.read((char *)&a, sizeof(a)))
        {
            if (ptr)
            {

                if (a.admission_no == key)
                {
                   c=1;
                    a.getRecord();
                    temp_f.write((char *)&a, sizeof(a));
                    continue;
                }
                else
                    temp_f.write((char *)&a, sizeof(a));
            }
        }
        temp_f.close();
        ptr.close();
        
        remove("student_record.txt");
        rename("new.txt", "student_record.txt");
        if(c==false){
            cout<<"\nNo such record present"<<endl;
            return;
        }
        cout<<"\nStudent record with admission no. "<<key<<" Updated"<<endl;
    }

    // searches a student in library
    void search(){
        student a;
         fstream ptr;
        int key;
        cout << "Enter the admission number of the student to search: ";
        cin >> key;
       
         ptr.open("student_record.txt", ios::in);
        
        bool c = 0;
        while (ptr.read((char *)&a, sizeof(a)))
        {
            if (ptr)
            {
                if (a.admission_no == key)
                {
                    c = 1;
                    a.showRecord();
                    break;
                }
            }
        }
        if (c==0)
            cout << "Record not Present in file\n";
        ptr.close();
    }


    //Issue a book in library to student
    void issue(){
        fstream ptr;
        fstream p;
        student a;
        book b;
        int val, book_id;
        fstream issue_file;
        cout << "Enter the admission number of the student to issue the book: ";
        cin >> val;
       cout << "Enter the book id of the book to be issued: ";
        cin >> book_id;
         string date;
        ptr.open("student_record.txt", ios::in);
       
        while (ptr.read((char *)&a, sizeof(a))){

         if (ptr){
             if (a.admission_no == val){
                    if (a.no_of_books > 3){
                        cout << "\nCannot issue more than 3 books\n";
                        return;
                    }
                }
            }
        }
        ptr.close();
        p.open("book.txt", ios::in);
        
        bool flag = false;
        while (p.read((char *)&b, sizeof(b)))
        {

            
            if (b.Book_no == book_id){
                flag = true;
                break;
            }
        }
        if (flag==false){
            cout << "No Book with id " << book_id << " present in library" << endl;
            return;
          }
            else if(b.copies==0){
            cout<<"\nBook is not present in library at this time\n"<<endl;
               return;
            }
           p.close();
        fstream temp_f;
        ptr.open("student_record.txt", ios::in);
        temp_f.open("new.txt", ios::app);
        while (ptr.read((char *)&a, sizeof(a)))
        {
            if (ptr)
            {
                if (a.admission_no == val)
                {   
                    student s1;
                    s1.admission_no=a.admission_no;
                    strcpy(s1.Student_name,a.Student_name);
                    strcpy(s1.class_of_st,a.class_of_st);
                    s1.no_of_books=a.no_of_books+1;
                     temp_f.write((const char *)&s1, sizeof(s1));
                    
                }
                else{
                     temp_f.write((const char *)&a, sizeof(a));
                }

            }
        }
        temp_f.close();
        ptr.close();
       remove("student_record.txt");
       rename("new.txt", "student_record.txt");

           p.open("book.txt", ios::in);
        temp_f.open("new.txt", ios::app);
        
        while (p.read((char *)&b, sizeof(b)))
        {
            if (b.Book_no == book_id){
                book k;
                strcpy(k.Book_auth, b.Book_auth);
                strcpy(k.Book_name, b.Book_name);
                k.Book_no=b.Book_no;
                k.copies=b.copies-1;
                  temp_f.write((const char *)&k, sizeof(k));
            }
            else{
                temp_f.write((const char *)&b, sizeof(b));
            }
        }

         temp_f.close();
         p.close();

       remove("book.txt");
       rename("new.txt", "book.txt");
           
            fflush(stdin);
            cout << "\nEnter the date on which the book is issued : ";
            fflush(stdin);
            getline(cin, date);
            issue_file.open("issue.txt", ios::app);
            issue_file << "\nStudent's admission number = " << a.admission_no <<"\tbook id of book issued = " << book_id << "\t Issuing date = " << date;
             issue_file.close();
    }

    //Record of books returned back to library
    void deposit(){
        int val, book_id;
        fstream ptr;
        fstream deposit_file;
        student s;
        book a;
        cout << "Enter the admission number of the student returning the book: ";
        cin >> val;
        cout << "Enter the book id of the book to be returned: ";
        cin >> book_id;
        string date;
        fstream temp_f;
        
        ptr.open("student_record.txt", ios::in);
        temp_f.open("new.txt", ios::app);
        while (ptr.read((char *)&s, sizeof(s)))
        {
            if (ptr)
            {
                if (s.admission_no == val)
                {   
                    student s1;
                    s1.admission_no=s.admission_no;
                    strcpy(s1.Student_name,s.Student_name);
                    strcpy(s1.class_of_st,s.class_of_st);
                    s1.no_of_books=s.no_of_books-1;
                     temp_f.write((const char *)&s1, sizeof(s1));
                    
                }
                else{
                     temp_f.write((const char *)&s, sizeof(s));
                }

            }
        }
        temp_f.close();
        ptr.close();
       remove("student_record.txt");
       rename("new.txt", "student_record.txt");

    
        fstream p;
        
        p.open("book.txt", ios::in);
        temp_f.open("new.txt", ios::app);
        
        while (p.read((char *)&a, sizeof(a)))
        {
            if (a.Book_no == book_id){
                book k;
                strcpy(k.Book_auth, a.Book_auth);
                strcpy(k.Book_name, a.Book_name);
                k.Book_no=a.Book_no;
                k.copies=a.copies+1;
                  temp_f.write((const char *)&k, sizeof(k));
            }
            else{
                temp_f.write((const char *)&a, sizeof(a));
            }
        }

         temp_f.close();
         p.close();

       remove("book.txt");
       rename("new.txt", "book.txt");
        
        cout << "Enter the date on which the book is returned: ";
        fflush(stdin);
        getline(cin, date);
        fflush(stdin);
        deposit_file.open("deposit.txt", ios::app);
        fflush(stdin);
        deposit_file << "\nStudent with admission number = " << s.admission_no << "\treturned book id = " << book_id << "\tReturning date = " << date;
        
    }

       // print record of students
    void showfile(){
         cout<<"\n**************************************"<<endl;
        cout<<"The Student Record is : "<<endl;
        fstream ptr;
        student a;
        ptr.open("student_record.txt", ios::in);
        while (ptr.read((char *)&a, sizeof(a)))
        {
            a.showRecord();
            cout<<"\n";
        }
        ptr.close();
          cout<<"\n**************************************"<<endl;
    }
    
};


int main(){
   
    int opt;
    cout<<"\t------------------------------------"<<endl;
    cout << "\t\tLIBRARY MANAGMENT CODE" << endl;
    cout<<"\t------------------------------------"<<endl;

    cout<<"\nAdmin Portal:-"<<endl;
        book a;
        student b;
        do{
            cout << "\nPress 1 to enter book record\nPress 2 to enter student record\nPress 3 to show the books file\nPress 4 to show the student file \nPress 5 to Delete books file\nPress 6 to Delete Student File\nPress 7 to Search book record\nPress 8 to Search student record\nPress 9 to update a record of a specific book\nPress 10 to update record of a specific student\nPress 11 to Issue a Book to Student\nPress 12 to deposit book to library\nPress any other option to exit\n";
            cout<<"-----------------------------------"<<endl;
            cout<<"-----------------------------------"<<endl<<endl;;
            cout << "Enter the option : ";
            cin >> opt;
            switch (opt){
            case 1:
                a.AddRecord();
                break;
            case 2:
                b.AddRecord();
                break;
            case 3:
                a.showfile();
                break;
            case 4:
                b.showfile();
                break;
            case 5:
               a.DeleteRecord();
               
                break;
            case 6:
                b.DeleteRecord();
                break;
            case 7:
                a.search();
                break;
            case 8:
               b.search();
                break;
            case 9:
                 a.UpdateRecord();
                break;
            case 10:
                b.UpdateRecord();
                break;
            
            case 11:
               b.issue();
               break;
           case 12:
               b.deposit();
               break;
            }
        } while (opt <= 12 && opt != 0);
    
     return 0;
}
