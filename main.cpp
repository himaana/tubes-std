#include "tubesh.h"
int main(){
    List Q1,Q2,Q3;
    int i, j, k, Quantum, prioritas, t, n;
    infotype x;
    adr P;

    createQueue(Q1);
    createQueue(Q2);
    createQueue(Q3);

    i = menu();
    while(i != 4){
        switch (i){
        case 1:
            cout << "Queue Prioritas Tinggi\n";
            cout << "Jumlah Data: ";
            cin >> j;
            k = 1;
            if (j != 0) {
                while (k <= j){
                    cout << "Data Ke-" << k << endl;
                    cout << "Job: ";
                    cin >> x.name;
                    cout << "Burst Time: ";
                    cin >> x.burstTime;
                    createElement(x, P);
                    enqueue(Q1, P);
                    k++;
                }
            }
            n += j;
            cout << "\nQueue Prioritas Sedang\n";
            cout << "Jumlah Data: ";
            cin >> j;
            k = 1;
            if (j != 0) {
                while (k <= j){
                    cout << "Data Ke-" << k << endl;
                    cout << "Job: ";
                    cin >> x.name;
                    cout << "Burst Time: ";
                    cin >> x.burstTime;
                    createElement(x, P);
                    enqueue(Q2, P);
                    k++;
                }
            }
            n += j;
            cout << "\nQueue Prioritas Rendah\n";
            cout << "Jumlah Data: ";
            cin >> j;
            k = 1;
            if (j != 0) {
                while (k <= j){
                    cout << "Data Ke-" << k << endl;
                    cout << "Job: ";
                    cin >> x.name;
                    cout << "Burst Time: ";
                    cin >> x.burstTime;
                    createElement(x, P);
                    enqueue(Q3, P);
                    k++;
                }
            }
            n += j;
            break;
        case 2:
            cout << "Menampilkan Queue Prioritas Tinggi\n\n";
            show(Q1);
            cout << "Menampilkan Queue Prioritas Sedang\n\n";
            show(Q2);
            cout << "Menampilkan Queue Prioritas Rendah\n\n";
            show(Q3);
            break;
        case 3:
            if (isEmpty(Q1)){
                cout << "TIDAK ADA QUEUE UNTUK DIEKSEKUSI\n";
            } else {
                cout << "Quantum : ";
                cin >> Quantum;
                cout << "PrioUp  : ";
                cin >> prioritas;
                cout << "\n...................MENGEKSEKUSI..................\n";
                firstTimeFirstServe(Q1, Q2, Q3, Quantum, prioritas, n);
            }
            cout << "\n.....................SELESAI.....................\n";
            break;
        }
        i = menu();
    }
    cout << "\nPROGRAM TELAH BERHENTI\n\n";
}