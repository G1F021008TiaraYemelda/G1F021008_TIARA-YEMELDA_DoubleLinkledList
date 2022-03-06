#include <iostream>

using namespace std;

struct DataMie{
  string MerekMie, jenis;
  int HargaMie;

  DataMie *prev;
  DataMie *next;
};

DataMie *head, *tail, *cur, *del, *newNode, *afterNode;

void createDataMie( string MerekMie, string jenis, int HargaMie ){
  head = new DataMie();
  head->MerekMie = MerekMie;
  head->HargaMie = HargaMie;
  head->prev = head;
  head->next = head;
  tail = head;
}

void addFirst( string MerekMie, string jenis, int HargaMie ){
  if( head == NULL ){
  }else{
    newNode = new DataMie();
    newNode->MerekMie = MerekMie;
    newNode->jenis = jenis;
    newNode->HargaMie = HargaMie;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
  }
}

void addLast( string MerekMie, string jenis, int HargaMie ){
  if( head == NULL ){
  }else{
    newNode = new DataMie();
    newNode->jenis = jenis;
    newNode->MerekMie = MerekMie;
    newNode->HargaMie = HargaMie;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
  }
}


// remove First
void removeFirst(){
  if( head == NULL ){
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    delete del;
  }
}

// remove Last
void removeLast(){
  if( head == NULL ){
  }else{
    del = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete del;
  }
}

// remove Middle
void removeMiddle(int posisi){
  if( head == NULL ){
  }else{
    if( posisi == 1 ){
    }else if( posisi < 1 ){
    }else{
      // tranversing
      cur = head;
      int nomor = 1;
      while ( nomor < posisi - 1 ){
        cur = cur->next;
        nomor++;
      }
      del = cur->next;
      afterNode = del->next;
      cur->next = afterNode;
      afterNode->prev = cur;
      delete del;
    }
  }
}

// fungsi print
void printDataMie()
{
  if( head == NULL ){
  }else{
    cout << "Data Mie : " << endl;
    cur = head;
    while( cur->next != head ){
      // print
      cout << "Merek Mie : " << cur->MerekMie << endl;
      cout << "Jenis: " << cur->jenis<< endl;
      cout << "Harga Mie : Rp." << cur->HargaMie << "\n" << endl;

      // step
      cur = cur->next;
    }
    // print last node
      cout << "Merek Mie : " << cur->MerekMie<< endl;
      cout << "Jenis : " << cur->jenis<< endl;
      cout << "Harga Mie : Rp." << cur->HargaMie << "\n" << endl;
  }
}

int main(){

  createDataMie("INDOMIE", "Kuah", 4000);
  printDataMie();

  addFirst("SEDAP", "goreng", 3000);
  printDataMie();

  addLast("INTERMI", "kuah", 2000);
  printDataMie();

  printDataMie();

  removeMiddle(2);
  
  printDataMie();



} 
