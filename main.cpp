#include "tubesh.h"
int main(){
    List Q1,Q2,Q3,Q4;
    int i, j, k, Quantum, prioritas, t, n;
    float ATAT, AWT;
    infotype x;
    adr P;

    createQueue(Q1);
    createQueue(Q2);
    createQueue(Q3);
    createQueue(Q4);

    i = menu();
    while(i != 6){
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
            cout << "\nMenampilkan Queue Prioritas Sedang\n\n";
            show(Q2);
            cout << "\nMenampilkan Queue Prioritas Rendah\n\n";
            show(Q3);
            break;
        case 3:
            if (isEmpty(Q1)){
                cout << "\nTIDAK ADA QUEUE UNTUK DIEKSEKUSI\n";
            } else {
                cout << "Quantum : ";
                cin >> Quantum;
                cout << "PrioUp  : ";
                cin >> prioritas;
                cout << "...................MENGEKSEKUSI..................";
                Q4 = firstTimeFirstServe(Q1, Q2, Q3, Quantum, prioritas, AWT, ATAT);
            }
            cout << ".....................SELESAI.....................\n";
            break;
        case 4:
            AverageWT(AWT,n);
            AverageTAT(ATAT,n);
            cout << "Rata-Rata Waiting Time Dan Turn Arround Time\n"
            << "AWT: " << AWT
            << "\nATAT: " << ATAT <<"\n";
            break;
        case 5:
            show(Q4);
            break;
        }
        cout << "====================================================\n\n\n";
        i = menu();
    }
    cout << "PROGRAM TELAH BERHENTI\n\n";
}