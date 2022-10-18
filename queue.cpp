/*  Nama    : Khoirizqi Velarati
    NIM     : A11.2021.13895
    Kelas   : A11.4317
    Matkul  : Struktur Data
*/

#include<iostream>
using namespace std;
#define MAX 8

struct Antrian
{
    int data[MAX];
    int head;
    int tail;
};

Antrian antre;
void create();
bool isEmpty();
bool isFull();
void enqueue(int);
int dequeue();
void tampil();

int main()
{
    int pilih,data;

    menu:
    cout << endl;
    cout << "Daftar pilihan:" << endl;

    cout << "1. Tambah data" << endl;
    cout << "2. Hapus data" << endl;
    cout << "3. Menampilkan data" << endl;

    cout << "Masukkan Pilihan Anda : ";
    cin >> pilih;
    cout << endl;

    switch(pilih){
    case 1: cout << "1. Tambah data" << endl;
                cout << "Masukkan data yang ingin ditambahkan: ";
                cin >> data;
                enqueue(data);
                goto menu;
        break;

        case 2: cout << "2. Hapus data" << endl;
                dequeue();
                goto menu;
        break;

        case 3: cout << "3. Menampilhan data" << endl;
                tampil();
                goto menu;
        break;

        default : cout << "Masukkan pilihan anda terlebih dahulu" << endl;
        break;
    }

    return 0;
}


void create()
{
    antre.head = antre.tail = -1;
}

bool isEmpty()
{
    if(antre.tail == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull()
{
    if(antre.tail == MAX )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(int data)
{
    if(isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        if(isEmpty())
        {
            antre.head = antre.tail = 0;
            antre.data[antre.tail] = data;
            antre.head++;
            antre.tail++;
        }
        else
        {
            antre.data[antre.tail] = data;
            antre.tail++;

            cout << data << " dimasukan kedalam antrian." << endl;
        }
    }

}


int dequeue()
{
    if(isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        int e = antre.data[antre.head];
        int i;
        for(i=0; i<antre.tail; i++)
        {
            antre.data[i] = antre.data[i+1];
        }
        antre.tail--;
        return e;
    }


}

void tampil()
{
    if(isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for(int i=00; i<MAX; i++)
        {
            if(antre.data[i]==NULL)
            {
                cout << "Data ke-" << i+1 << " = " << "Kosong" << endl;
            }
            else
            {
                cout << "Data ke-" << i+1 << " = "<< antre.data[i] << endl;
            }
        }
    }
}
